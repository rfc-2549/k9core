#include <stdio.h>
#include <unistd.h>

int
main(void)
{
	long id = gethostid();
	printf("%lx\n", id);

	return 0;
}
