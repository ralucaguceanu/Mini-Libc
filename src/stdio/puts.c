#include <../include/errno.h>
#include <../include/string.h>
#include <../include/internal/io.h>
#include <../include/stdio.h>

#define EOF (-1)  /* end of file */

int puts(const char *s)
{
    int len = strlen(s);
    int result_puts = write(1, s, len);

    if (result_puts < 0) {
        errno = -result_puts;
        return EOF;
    }

    char newline = '\n';
    int result_newline = write(1, &newline, 1);

    if (result_newline < 0) {
        errno = -result_newline;
        return EOF;
    }

    return len + 1;
}
