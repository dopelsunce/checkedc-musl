#define _GNU_SOURCE
#include <string.h>

void *mempcpy(void *dest : itype(_Array_ptr<void>) byte_count(n),
              const void *src : itype(_Array_ptr<const void>) byte_count(n),
              size_t n)
  : itype(_Array_ptr<void>) byte_count(n)
_Checked
{
	return (_Array_ptr<char>)memcpy(dest, src, n) + n;
}
