#include <stdio.h>

int
main(int argc, char *argv[])
{
	if(argc > 1)
		while(1)
			puts(argv[1]);
	else
		while(1)
			puts("y");
	return 0;
}
