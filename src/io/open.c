// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */

    int result_open;

    /* asa cum se mentioneaza in laborator, daca trebuie sa cream fisierul este nevoie
       sa dam syscall ul si cu permisiunile fisierului nou creat */
    if (flags & O_CREAT) {
        va_list mode_args;
        va_start(mode_args, flags);  /* contine parametrii primiti dupa flags (permisiunile) */
        mode_t mode = va_arg(mode_args, mode_t);  /* extragerea permisiunilor */
        va_end(mode_args);
        result_open = syscall(__NR_open, filename, flags, mode);
    } else {
        result_open = syscall(__NR_open, filename, flags);
    }

    if (result_open < 0) {
        errno = -result_open;
        return -1;
    }

    return result_open;
}
