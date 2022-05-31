from argparse import ArgumentParser, Namespace
from os.path import getsize
import subprocess


def main(args: Namespace):
    with open(args.output, "wb") as f:
        with open(args.disk, "rb") as f2:
            f.write(f2.read())

        if args.bootloader is not None:
            if getsize(args.bootloader) > 512:
                raise ValueError("Bootloader is too large")

            with open(args.bootloader, "rb") as f2:
                f.seek(0)
                f.write(f2.read(3)) # JMP $xxxx
                f.seek(args.address)
                f.write(f2.read())
        else:
            f.seek(0xfe)
            f.write(b"\x00\x00") # Remove boot sector signature

    return 0


if __name__ == '__main__':
    parser = ArgumentParser(
        description="Create a CAB-bootable disk image with bootloader")

    # Base disk image
    parser.add_argument("disk", help="Base disk image")
    # Optional bootloader
    parser.add_argument("-b", "--bootloader", help="Bootloader", required=None)
    # At what address should the bootloader be placed?
    parser.add_argument("-a", "--address", type=int, default=0x3e, help="Address of bootloader")

    # Output file
    parser.add_argument("-o", "--output", dest="output", default="disk.img")

    exit(main(parser.parse_args()))
