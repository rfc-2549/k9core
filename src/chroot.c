#include <stdio.h>
#include <unistd.h>

/* UNTESTED */

int
main(int argc, char *argv[])
{
	if(argc == 1) {
		fprintf(stderr, "Missing operand\n");
		return 1;
	}
	chroot(argv[1]);
}
