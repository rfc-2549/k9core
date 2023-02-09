#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int
copy(const char *src, const char *dst)
{
	int source = open(src, O_RDONLY);
	int destination = creat(dst, 0644);

	if(destination == -1) {
		fprintf(stderr,
			   "Error opening destination file: %i = %s\n",
			   errno,
			   strerror(errno));
		return 1;
	}
	if(source == -1) {
		fprintf(stderr,
			   "Error opening source file: %i = %s\n",
			   errno,
			   strerror(errno));
		return 1;
	}
	int lines;
	char buf[8912];
	while((lines = read(source, buf, sizeof(buf))) > 0)
		write(destination, buf, lines);
	close(destination);
	close(source);
	return 0;
}

int
main(int argc, char *argv[])
{
	int fd;
	if(argc == 1) {
		fprintf(stderr, "usage: cp source destination\n");
		return 1;
	} else
		fd = copy(argv[1], argv[2]);
}
