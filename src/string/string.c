// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */

	size_t count = 0;

	while (*source != '\0') {
		*destination = *source;
		source++;
		destination++;
		count++;
		/* numaram cate caractere am copiat ca sa stim
		cat sa scadem pt a ne intoarce la adresa de inceput a destinatiei */
	}

	*destination = *source; /* punem si \0 */

	return destination - count;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */

	size_t count = 0;

	if (len < strlen(source)) {
		for (count = 0; count < len; count++) {
			*destination = *source;
			source++;
			destination++;
		}
	} else if (len > strlen(source)) {
		while (*source != '\0') {
			*destination = *source;
			source++;
			destination++;
			count++;
			/* numaram cate caractere am copiat ca sa stim
			cat sa scadem pentru a ne intoarce la adresa de inceput a destinatiei */
		}
	}

	while (count < len) {
		*destination = '\0';
		count++;
		destination++;
	}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */

	char *d = destination + strlen(destination);

    while (*source != '\0') {
        *d = *source;
		d++;
		source++;
    }

    *d = '\0';

    return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */

	size_t count = 0;

	char *d = destination + strlen(destination);

	if (len < strlen(source)) {
		for (count = 0; count < len; count++) {
			*d = *source;
			d++;
			source++;
		}
	} else if (len > strlen(source)) {
		while (*source != '\0') {
			*d = *source;
			source++;
			d++;
			count++;
		}
	}

	while (count < len) {
		*d = '\0';
		count++;
		d++;
	}

	*d = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */

	while (*str1 != '\0' && *str2 != '\0') {
		if (*str1 != *str2) {
			if (*str1 < *str2) {
				return -1;
			} else {
				return 1;
			}
		}

		str1++;
		str2++;
	}

	if (strlen(str1) == strlen(str2)) {
		return 0;
	} else if (*str1 == '\0') {
		return -1;
	}

	return 1;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */

	size_t count = 0;

    while (*str1 != '\0' && *str2 != '\0' && count < len) {
        if (*str1 != *str2) {
            if (*str1 < *str2) {
				return -1;
			} else {
				return 1;
			}
        }
        str1++;
        str2++;
        count++;
    }

    if (count == len || (strlen(str1) == strlen(str2))) {
        return 0;
    } else if (*str1 == '\0') {
        return -1;
    }

	return 1;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */

	while (*str != '\0') {
		if (*str == c) {
			return (char *) str;
		}

		str++;
	}

	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */

	char *final = (char *) (str + strlen(str));

	while (final != str) {
		if (*final == c) {
			return final;
		}

		final--;
	}

	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */

	size_t haystack_length = strlen(haystack);
	size_t needle_length = strlen(needle);

	if (haystack_length < needle_length) {
		return NULL;
	}

	for (size_t i = 0; i <= haystack_length - needle_length; i++) {
		size_t count = 0;
		while (*(haystack + i + count) == *(needle + count) && count < strlen(needle)) {
			count++;
		}

		if (count == strlen(needle)) {
			return (char *) (haystack + i);
		}
	}

	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */

	size_t haystack_length = strlen(haystack);
	size_t needle_length = strlen(needle);

	for (ssize_t i = haystack_length - needle_length; i >= 0; i--) {
		size_t count = 0;
		while (*(haystack + i + count) == *(needle + count) && count < strlen(needle)) {
			count++;
		}

		if (count == strlen(needle)) {
			return (char *) (haystack + i);
		}
	}

	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */

	char *dest = (char *) destination;
    char *src = (char *) source;

	size_t count = 0;

	while (count < num) {
		*dest = *src;
		dest++;
		src++;
		count++;
	}

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */

	char *dest = (char *) destination;
    char *src = (char *) source;

	size_t count = 0;

	/* cand destinatia se afla inaintea sursei */
	if (dest < src) {
		while (dest < src && count < num) {
			*dest = * src;
			dest++;
			src++;
			count++;
		}

		return destination;
	}

	/* cand destinatia se afla dupa sursa */
	if (dest > src) {
		while (src < dest && count < num) {
			*dest = * src;
			dest++;
			src++;
			count++;
		}
	}

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */

	char *p1 = (char *)ptr1;
    char *p2 = (char *)ptr2;

	size_t count = 0;

	while (count < num) {
		if (*p1 < *p2) {
			return 1;
		} else if (*p1 > *p2) {
			return -1;
		}
		p1++;
		p2++;
		count++;
	}

	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */

	char *src = (char *)source;

	size_t count = 0;

	while (count < num) {
		*src = value;
		src++;
		count++;
	}

	return source;
}
