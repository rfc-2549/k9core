#include <stdio.h>
#include <unistd.h>

int
main()
{
	puts(getcwd(NULL, 0));
	return 0;
}
