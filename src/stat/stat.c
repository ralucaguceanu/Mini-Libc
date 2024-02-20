// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	/* TODO: Implement stat(). */

	int result_stat = syscall(__NR_stat, path, buf);

	if (result_stat < 0) {
        errno = -result_stat;
        return -1;
    }

    return result_stat;
}
