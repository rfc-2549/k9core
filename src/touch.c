#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
	if(argc <= 1) {
		fprintf(stderr, "Give a file\n");
		return 1;
	}

	int fd = creat(argv[1], 0644);

	if(fd == -1) {
		fprintf(stderr,
			   "Error creating file: %i = %s\n",
			   errno,
			   strerror(errno));
		return 1;
	}
	close(fd);
	return 0;
}
