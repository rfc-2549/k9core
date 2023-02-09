#include <getopt.h>
#include <pwd.h>
#include <stdio.h>
#include <unistd.h>
int
main(int argc, char *argv[])
{
	int c = getopt(argc, argv, "Ggnru");
	struct passwd *user_data = getpwnam(getlogin());
	switch(c) {
		case 'g':
		case 'u':
			printf("%u\n", user_data->pw_gid);
			break;
		case 'n':
			printf("%s\n", user_data->pw_name);
			break;
		default:
			printf("%u %s\n",
				  user_data->pw_gid,
				  user_data->pw_name); /* I know
								    * it does not work
								    * like this */
	}

	return 0;
}
