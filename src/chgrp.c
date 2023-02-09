#include <errno.h>
#include <grp.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
	int c;
	int follow_symlink;
	while((c = getopt(argc, argv, "h")) != -1) {
		switch(c) {
			case 'h':
				follow_symlink = 1;
				break;
		}
	}
	if(argc == 1 || argc == 2) {
		fprintf(stderr, "usage: chgrp group file...\n");
		return 1;
	}
	struct group *group_data = getgrnam(argv[optind]);
	gid_t gid = group_data->gr_gid;
	for(int i = optind + 1; i < argc; i++) {
		if(follow_symlink) {
			if(lchown(argv[i], gid, getuid()) == -1)
				fprintf(stderr, "Error: %i = %s\n", errno, strerror(errno));
		} else if(chown(argv[i], gid, getuid()) == -1) {
			fprintf(stderr, "Error: %i = %s\n", errno, strerror(errno));
		}
	}
}
