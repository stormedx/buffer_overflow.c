# Buffer Overflow Example with ASAN

This repository contains a simple C program, `buffer_overflow.c`, designed to demonstrate how a buffer overflow can occur and how it can be detected using ASAN (AddressSanitizer).

## Prerequisites

To use ASAN with this program, you'll need a C compiler that supports ASAN (such as `gcc` or `clang`) and the standard C libraries.

## Installation

### Debian/Ubuntu (apt)

```bash
sudo apt update
sudo apt install build-essential
```

### Arch Linux
```bash
sudo pacman -Syu
sudo pacman -S base-devel
```

### Fedora
```bash
sudo dnf groupinstall "Development Tools"
sudo dnf install @development-tools
```

### Brew (macOS)
```bash
brew install gcc
```

## Compiling with ASAN
To compile the buffer_overflow.c program with AddressSanitizer, use the following command:
```bash
gcc -fsanitize=address -g buffer_overflow.c -o buffer_overflow
./buffer_overflow
```
