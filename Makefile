ASM=nasm
BOOT_DIR = bootloader
SRC_DIR=src
BUILD_DIR=build

$(BUILD_DIR)/tapix_floppy.img: $(BUILD_DIR)/tapix.bin
	cp $(BUILD_DIR)/tapix.bin $(BUILD_DIR)/main_floppy.img
	truncate -s 1440k $(BUILD_DIR)/main_floppy.img
	
$(BUILD_DIR)/tapix.bin: $(BOOT_DIR)/boot.asm
	mkdir -p $(BUILD_DIR)
	$(ASM) $(BOOT_DIR)/boot.asm -f bin -o $(BUILD_DIR)/tapix.bin

run: $(BUILD_DIR)/tapix_floppy.img
	qemu-system-x86_64 -machine pc -cpu qemu64 -drive format=raw,file=$(BUILD_DIR)/main_floppy.img


clean:
	rm -rf $(BUILD_DIR)
