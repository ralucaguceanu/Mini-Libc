// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, off_t length)
{
	/* TODO: Implement ftruncate(). */

	int result_ftruncate = syscall(__NR_ftruncate, fd, length);

    if (result_ftruncate < 0) {
        errno = -result_ftruncate;
        return -1;
    }

    return 0;
}
