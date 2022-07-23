#include <stddef.h>
#include <stdio.h>

size_t sfio_fread(void *ptr, size_t size, size_t count, void *unused);

size_t sfio_fwrite(const void *ptr, size_t size, size_t count, void *unused);

int sfio_fseek(void *, long int, int);
