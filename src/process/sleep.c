#include <../include/time.h>

unsigned int sleep(unsigned int seconds)
{
    struct timespec req, rem;
    req.tv_sec = (uint64_t) seconds;
    req.tv_nsec = 0;

    return syscall(__NR_nanosleep, &req, &rem);
}

int nanosleep(const struct timespec *req, struct timespec *rem)
{
    int result = syscall(__NR_nanosleep, req, rem);
    if (result == -1) {
        return -1;
    }

    return 0;
}
