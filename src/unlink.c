#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
	if(argc == 1) {
		fprintf(stderr, "What do I unlink?\n");
		return 1;
	}

	int fd = unlink(argv[1]);
	if(fd == -1) {
		fprintf(stderr, "Error unlinking: %i = %s\n", errno, strerror(errno));
	}
	return 0;
}
