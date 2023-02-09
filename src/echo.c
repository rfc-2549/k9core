#include <stdio.h>
#include <string.h>

int
main(int argc, char *argv[])
{
	int nflag;
	if(!strcmp(*++argv, "-n")) {
		nflag = 1;
		argv++;
	}

	while(*argv) {
		(void)fputs(*argv, stdout); /* Print argv */
		if(*++argv)
			putchar(' '); /* If multiple things in argv, print a space
						  between them. */
	}
	if(!nflag)
		putchar('\n');
	return 0;
}
