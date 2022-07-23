#include <assert.h>

#include "simple_fileio.h"
#include "dfu.h"

static long int g_offset = 0;

// TODO use the last argument to specify the slot
size_t sfio_fread(void *ptr, size_t size, size_t count, void *unused) {
    return dfu_read(IMAGE_SLOT_2, ptr, g_offset, size * count);
}

size_t sfio_fwrite(const void *ptr, size_t size, size_t count, void *unused) {
    return dfu_write(IMAGE_SLOT_2, ptr, g_offset, size * count);
}

int sfio_fseek(void *unused, long int offset, int origin) {
    assert(origin == SEEK_SET);
    g_offset = offset; 
    return 0;
}
