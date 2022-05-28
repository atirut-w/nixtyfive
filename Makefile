CC65 = cc65
CA65 = ca65
LD65 = ld65

build: compile assemble link

compile:
	mkdir -p build/s
	find src/ -name '*.s' -exec cp {} build/s/ \;
	find src/ -name '*.c' -exec sh -c '$(CC65) -T -t none --cpu 65c02 -Osir -Isrc/include {} -o build/s/$$(basename {} .c).s' \;

assemble:
	mkdir -p build/o
	for f in build/s/*.s; do $(CA65) --cpu 65c02 $$f -o build/o/`basename $$f .s`.o; done

link:
	$(LD65) build/o/*.o -o build/kernel.bin -m build/kernel.map -C ocmos.cfg c64.lib

bootloader:
	$(CA65) --cpu 65c02 bootloader.s -o build/bootloader.o
	$(LD65) build/bootloader.o -o build/bootloader.bin -m build/bootloader.map -C ocmos.cfg

clean:
	rm -rf build/o build/s
