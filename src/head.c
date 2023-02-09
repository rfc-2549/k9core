#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
head(FILE *file, int lines)
{
	if(file == NULL) {
		fprintf(
			stderr, "error opening file: %i = %s\n", errno, strerror(errno));
		return 1;
	}
	int a;
	int c = 0;

	while((a = fgetc(file)) != EOF) {
		if(a == '\n')
			++c;

		putchar(a);
		if(c == lines)
			return lines;
	}
	return lines;
}

int
main(int argc, char *argv[])
{
	int lines = 10;
	switch(argc) {
		case 1:
			head(stdin, lines);
			break;
		case 2:
			head(fopen(argv[1], "r"), lines);
			break;
		case 3:
			lines = abs(atoi(argv[1]));
			head(fopen(argv[2], "r"), lines);
			break;
		default:
			lines = atoi(argv[2]);
			head(fopen(argv[3], "r"), lines);
			break;
	}
	return 0;
}
