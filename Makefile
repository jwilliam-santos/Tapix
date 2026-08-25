ASM = nasm
CC = gcc
SRC_DIR = kernel
BUILD_DIR = build
ISO_DIR = iso
INC_DIR = kernel/LibC

C_SOURCES := $(shell find $(SRC_DIR) -name "*.c")
C_OBJECTS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(C_SOURCES))

ASM_SOURCES := $(shell find $(SRC_DIR) -name "*.asm")
ASM_OBJECTS := $(patsubst $(SRC_DIR)/%.asm, $(BUILD_DIR)/%.o, $(ASM_SOURCES))

.PHONY: all iso kernel clean always run

all: iso

iso: kernel
	cp $(BUILD_DIR)/kernel.bin $(ISO_DIR)/boot/kernel.bin
	grub-mkrescue -o $(BUILD_DIR)/Tapix.iso $(ISO_DIR)

kernel: always $(ASM_OBJECTS) $(C_OBJECTS)
	$(CC) -m64 -ffreestanding -nostdlib -no-pie -T linker.ld \
		$(ASM_OBJECTS) $(C_OBJECTS) \
		-o $(BUILD_DIR)/kernel.bin

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.asm always
	mkdir -p $(dir $@)
	$(ASM) $< -f elf64 -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c always
	mkdir -p $(dir $@)
	$(CC) -m64 -ffreestanding -fno-stack-protector -I$(INC_DIR) -nostdlib -c $< -o $@

always:
	mkdir -p $(BUILD_DIR)

run: iso
	qemu-system-x86_64 -cdrom $(BUILD_DIR)/Tapix.iso -d int,cpu_reset

clean:
	rm -rf $(BUILD_DIR)
	rm -f $(ISO_DIR)/boot/kernel.bin

help:
	printf "Comandos: make clean,make run\n"