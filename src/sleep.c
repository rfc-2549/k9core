#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
	if(argc == 1) {
		fprintf(stderr, "missing opperand\n");
		return 1;
	}
	usleep(atof(argv[1]) * 1000000);

	return 0;
}
