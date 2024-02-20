// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	/* TODO: Implement close(). */

	long result_close = syscall(__NR_close, fd);

    if (result_close < 0) {
        errno = -result_close;
        return -1;
    }

    return (int) result_close;
}
