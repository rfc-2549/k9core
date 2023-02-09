#include <libgen.h>
#include <stdio.h>

int
main(int argc, char *argv[])
{
	char *dir = dirname(argv[1]);
	if(dir == NULL) {
		fprintf(stderr, "%s", argv[0]);
		return 1;
	}
	printf("%s/\n", dir); /* Trailing slash because POSIX */
	return 0;
}
