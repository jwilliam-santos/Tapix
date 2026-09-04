# Tapix
## Tapix is an operating system focused on the global open-source market, inspired by Linux. Built entirely from scratch without Vibecode.
## folder structures
```text
Tapix/
├── .gitignore
├── LICENSE
├── License-lua.txt
├── Makefile
├── README.MD
├── linker.ld
└── kernel/
    ├── kernel.c
    ├── kernel.h
    ├── kernel_entry.asm
    └── libc/
        └── Minimal libc
```
## Technologies
```text
    Assembly X86_64
    C
    Grub
    linker.ld
    make
```
### How to use
```text
    sudo apt update
    sudo apt install -y make nasm qemu-system-x86 gcc binutils
    git clone https://github.com/jwilliam-santos/Tapix 
    cd Tapix
    make clean && make run
```