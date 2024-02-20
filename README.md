# Mini-Libc

A **minimalistic** [**standard C library**](https://en.wikipedia.org/wiki/C_standard_library) implementation for Linux systems, that can be used as a replacement for the **system libc** ([glibc](https://www.gnu.org/software/libc/) in Linux).
The goal is to have a minimally functional libc with features such as string management, basic memory support and POSIX file I/O.

The implementation of mini-libc is **freestanding**, i.e. it does not use any outside library calls.
It is implemented on top of the system call interface provided by Linux on an `x86_64` architecture.
