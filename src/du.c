#include <getopt.h>
#include <stdio.h>
#include <sys/stat.h>

int
main(int argc, char *argv[])
{
	int c;
	int human_readable = 0;
	struct stat file_data;

	while((c = getopt(argc, argv, "h")) != -1) {
		switch(c) {
			case 'h':
				human_readable = 1;
				break;
		}
	}
	if(argc == optind) {
		printf("no!\n");
		return 1;
	}
	for(int i = optind; i < argc; i++) {
		stat(argv[i], &file_data);
		if(human_readable)
			printf("%li\t %s", file_data.st_size * 1024, argv[i]);
		else
			printf("%li\t %s", file_data.st_size, argv[i]);
		puts("");
	}
	return 0;
}
