#include <internal/arch/x86_64/syscall_list.h>
#include <internal/syscall.h>
#include <internal/types.h>
#include <../include/errno.h>

struct timespec {
    uint64_t tv_sec;        /* seconds */
    long tv_nsec;       /* nanoseconds */
};

unsigned int sleep(unsigned int seconds);
int nanosleep(const struct timespec *req, struct timespec *rem);

