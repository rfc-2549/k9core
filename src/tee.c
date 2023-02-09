#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int
tee(int fd)
{
	if(fd == -1) {
		fprintf(stderr, "%s\n", strerror(errno));
		return 1;
	}
	char buf[8192];
	int read_bytes = 0;
	while((read_bytes = read(0, buf, 8192)) > 0) {
		write(fd, buf, read_bytes);
		if(fd != 1)
			write(1, buf, read_bytes);
	}
	return 0;
}

int
main(int argc, char *argv[])
{
	int c;
	int append = 0;
	int ignore_signt = 0;
	int fd = 0;
	int FLAGS = O_WRONLY | O_CREAT; /* yeah, it will overwrite the thing if it
							   * can't read what's in the file, thanks
							   * POSIX! */
	while((c = getopt(argc, argv, "ai")) != -1) {
		switch(c) {
			case 'a':
				append = 1;
				break;
			case 'i':
				ignore_signt = 1;
				break;
		}
	}
	if(argc == optind) {
		if(ignore_signt)
			signal(SIGINT, SIG_IGN);
		tee(1);
	} else {
		if(argv[argc - 1][0] == '-')
			fd = 1;
		if(append)
			FLAGS = O_RDWR | O_APPEND; /* Remember what I said? */

		fd = open(argv[argc - 1], FLAGS);
		if(ignore_signt)
			signal(SIGINT, SIG_IGN);
		if(tee(fd) == 1)
			return -1;
	}
	return 0;
}
