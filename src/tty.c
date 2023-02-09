#include <stdio.h>
#include <unistd.h>

int
main(void)
{
	printf("%s\n", ttyname(1));
	return 0;
}
