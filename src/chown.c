#include <pwd.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/* TODO: use strtok() to get the group */

int
main(int argc, char *argv[])
{
	if(argc == 1) {
		fprintf(stderr, "No command given\n");
		return 1;
	}
	const char *user = argv[1];

	struct passwd *data = getpwnam(user);
	uid_t uid = data->pw_gid;
	gid_t gid = data->pw_gid; /* Change this with the strtok() thing */

	for(int i = 2; i <= argc; i++) {
		chown(argv[i], uid, gid);
	}

	return 0;
}
