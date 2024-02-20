// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	/* TODO: Implement fstat(). */

	int result_fstat = syscall(__NR_fstat, fd, st);

    if (result_fstat < 0) {
        errno = -result_fstat;
        return -1;
    }

    return 0;
}
