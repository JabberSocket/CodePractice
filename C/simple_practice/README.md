# simple_practice

This directory contains basic C practice programs.

# Compiling with clang

```
clang -fsanitize=address -g3 -O0 hello_world.c -o hello_world
```

## Address Sanitizer

When practicing pointer manipulation or custom C memory allocation, compile with Clang's AddressSanitizer. It instantly catches out-of-bounds array reads, use-after-free errors, and stack buffer overflows at runtime. `-fsanitize=address` is not suitable for production due to CPU, memory, abort dynamics, and unsupported allocators.