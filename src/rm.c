#include <errno.h>
#include <stdio.h>
#include <string.h>
int
main(int argc, char *argv[])
{
	if(argc == 1) {
		printf("Specify files to remove.\n");
		return 1;
	}

	for(int i = 1; i < argc; i++) {
		int fd = remove(argv[i]);
		if(fd == -1) {
			fprintf(stderr,
				   "Error removing file: %i = %s",
				   errno,
				   strerror(errno));
		}
	}
	return 0;
}
