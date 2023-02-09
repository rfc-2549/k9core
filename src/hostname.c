#include <stdio.h>
#include <unistd.h>

int
main(void)
{
	char buf[64];
	gethostname(buf, 64);
	puts(buf);
	return 0;
}
