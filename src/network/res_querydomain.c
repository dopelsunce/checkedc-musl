#include <resolv.h>
#include <string.h>

_Checked int res_querydomain(const char *name : itype(_Nt_array_ptr<const char>),
	const char *domain : itype(_Nt_array_ptr<const char>),
	int class,
	int type,
	unsigned char *dest : count(len),
	int len)
{
	char tmp _Nt_checked[255];
	// TODO(yahsun): remove the unchecked scope once the str* functions are annotated with bounds-safe interfaces.
	size_t nl, dl;
	_Unchecked {
		nl = strnlen(name, 255);
		dl = strnlen(domain, 255);
	}
	if (nl+dl+1 > 254) return -1;
	memcpy(tmp, name, nl);
	tmp[nl] = '.';
	memcpy(tmp+nl+1, domain, dl+1);
	return res_query(tmp, class, type, dest, len);
}
