#include <stdio.h>
#include <unistd.h>

int
main(void)
{
	printf("%s\n", getlogin());
}
