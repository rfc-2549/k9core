#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
	int c;
	int u = 0;
	char buffer[256];
	time_t now;
	now = time(NULL);
	char FORMAT[256] = "%c";
	struct tm *timeinfo;

	while((c = getopt(argc, argv, "u")) != -1) {
		switch(c) {
			case 'u':
				u = 1;
				break;
		}
	}

	timeinfo = localtime(&now);

	if(u)
		timeinfo = gmtime(&now);

	if(argc > optind && argv[optind][0] == '+') {
		argv[optind]++;
		strcpy(FORMAT, argv[optind]);
	}

	strftime(buffer, 256, FORMAT, timeinfo);
	puts(buffer);
	return 0;
}
