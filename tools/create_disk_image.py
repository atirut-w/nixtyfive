from argparse import ArgumentParser, Namespace
from os.path import getsize
import subprocess


def main(args: Namespace):
    if getsize(args.bootloader) > 512:
        print("Bootloader is too large")
        return 1

    with open(args.output + ".uncompressed", "wb") as f:
        f.write(b"CAB!") # CAB boot sector, no text boot records
        f.write(b"\x00\x1a\xca\xbd") # Start of binary boot records

        f.write((8 + len(b"OCMOS") + 1).to_bytes(1, "little")) # Record length
        f.write((0x40 + 0x80).to_bytes(1, "little")) # Record flags(load start is sector num, start and length LE)
        f.write((2).to_bytes(2, "little")) # Load start at sector 2
        f.write(getsize(args.bootloader).to_bytes(4, "little")) # Length of bootloader
        f.write(b"OCMOS\x00") # Architecture ID

        f.seek(512, 0) # Seek to sector 2
        with open(args.bootloader, "rb") as b:
            f.write(b.read())

    # Compress the image using GZIP. Do remove original file.
    subprocess.run(["gzip", "-fk", args.output + ".uncompressed"])
    subprocess.run(["mv", args.output + ".uncompressed.gz", args.output])

    return 0


if __name__ == '__main__':
    parser = ArgumentParser(
        description="Create a CAB-bootable disk image with bootloader")

    # Bootloader binary file
    parser.add_argument("-b", "--bootloader", dest="bootloader", required=True)
    # # FAT16 root directory
    # parser.add_argument("-r", "--root", dest="root", required=True)

    # Output file
    parser.add_argument("-o", "--output", dest="output", required=True)

    exit(main(parser.parse_args()))
