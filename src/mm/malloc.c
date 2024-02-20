// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <../include/errno.h>

#define INT_MAX 2147483647

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */

    if (size == 0) {
        return NULL;
    }

    /* alocam memorie */
    void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);


    /* adaugam memoria alocata in lista */
    if (ptr != MAP_FAILED) {
        mem_list_add(ptr, size);
    } else {
		errno = ENOMEM;
        return NULL;
	}

    return ptr;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */

    /* verificam daca se face integer overflow */
    if (nmemb > 0 && size > INT_MAX / nmemb) {
        errno = EOVERFLOW;
        return NULL;
    }

    if (nmemb == 0 || size == 0) {
        return NULL;
    }

	size_t total_size = nmemb * size;

    void *ptr = malloc(total_size);

    if (ptr != NULL) {
        memset(ptr, 0, total_size);
    }

    return ptr;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */

	if (ptr == NULL) {
        return;
    }

    /* stergerea memoriei din lista */
    mem_list_del(ptr);

    /* eliberam memoria alocata, facand-o disponibila pentru alocari ulterioare */
    munmap(ptr, mem_list_find(ptr)->len);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */

	if (ptr == NULL) {
        return malloc(size);
    }

    if (size == 0) {
        free(ptr);
        return NULL;
    }

    void *new_ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (new_ptr != MAP_FAILED) {
        size_t old_size = mem_list_find(ptr)->len;
		size_t new_size;

        /* aflam cat trebuie sa copiem */
		if (size < old_size) {
			new_size = size;
		} else {
			new_size = old_size;
		}

        memmove(new_ptr, ptr, new_size);

        mem_list_del(ptr);

		mem_list_add(new_ptr, new_size);

        return new_ptr;
    } else {
		errno = ENOMEM;
        return NULL;
    }
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */

	size_t total_size = nmemb * size;
    return realloc(ptr, total_size);
}
