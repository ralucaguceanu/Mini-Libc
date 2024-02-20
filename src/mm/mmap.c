// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>
#include <../include/string.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */

    void *ptr = (void *) syscall(__NR_mmap, addr, length, prot, flags, fd, offset);

    ssize_t result_mmap = (ssize_t) ptr;

    if (result_mmap < 0) {
        errno = -result_mmap;
        return MAP_FAILED;
    }

    return ptr;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */

    if ((size_t) old_address % 4096 != 0) {
        errno = EINVAL;
        return MAP_FAILED;
    }

    int prot = PROT_READ | PROT_WRITE;

    /* permiterea kernel-ului sa relocheze maparea la o noua adresa virtuala, ca mentionat in manual */
    if (flags & MREMAP_MAYMOVE) {
        prot |= PROT_EXEC;
    }

    void *new_address = mmap(NULL, new_size, prot, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (new_address == MAP_FAILED) {
        return MAP_FAILED;
    }

    memmove(new_address, old_address, old_size);

    /* eliberam memoria veche */
    if (munmap(old_address, old_size) == -1) {
        return MAP_FAILED;
    }

    return new_address;
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */

    /* daca adresa nu este un multiplu al paginii */
    if ((size_t) addr % 4096 != 0) {
        errno = EINVAL;
        return -1;
    }

	int result_munmap = syscall(__NR_munmap, addr, length);

    if (result_munmap == -1) {
        errno = EINVAL;
        return -1;
    }

    return 0;
}
