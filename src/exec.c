#include <stdio.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
	if(argc == 1) {
		fprintf(stderr, "what do you want to do?\n");
		return 1;
	}
	char *const argv2[1] = { argv[2] };
	execv(argv[1], argv2);
	return 0;
}
