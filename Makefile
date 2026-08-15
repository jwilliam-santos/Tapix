ASM = nasm
CC = gcc
SRC_DIR = kernel
BUILD_DIR = build
ISO_DIR = iso

C_SOURCES := $(shell find $(SRC_DIR) -name "*.c")
C_OBJECTS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(C_SOURCES))

.PHONY: all iso kernel clean always run

all: iso

iso: kernel
	cp $(BUILD_DIR)/kernel.bin $(ISO_DIR)/boot/kernel.bin
	grub-mkrescue -o $(BUILD_DIR)/Tapix.iso $(ISO_DIR)

kernel: always $(BUILD_DIR)/kernel_entry.o $(C_OBJECTS)
	$(CC) -m64 -ffreestanding -nostdlib -no-pie -T linker.ld \
		$(BUILD_DIR)/kernel_entry.o $(C_OBJECTS) \
		-o $(BUILD_DIR)/kernel.bin

$(BUILD_DIR)/kernel_entry.o: $(SRC_DIR)/kernel_entry.asm always
	$(ASM) $< -f elf64 -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c always
	mkdir -p $(dir $@)
	$(CC) -m64 -ffreestanding -fno-stack-protector -nostdlib -c $< -o $@

always:
	mkdir -p $(BUILD_DIR)

run: iso
	qemu-system-x86_64 -cdrom $(BUILD_DIR)/Tapix.iso

clean:
	rm -rf $(BUILD_DIR)
	rm -f $(ISO_DIR)/boot/kernel.bin