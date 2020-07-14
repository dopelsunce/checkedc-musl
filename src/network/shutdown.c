#include <sys/socket.h>
#include "syscall.h"
#pragma CHECKED_SCOPE on

int shutdown(int fd, int how)
{
	return socketcall(shutdown, fd, how, 0, 0, 0, 0);
}
