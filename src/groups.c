#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
	struct passwd *pwd;
	if(argc == 2)
		pwd = getpwnam(argv[1]);
	else
		pwd = getpwuid(getuid());

	int ngroups = 10;
	uid_t *groups = malloc(ngroups);
	getgrouplist(pwd->pw_name, pwd->pw_gid, groups, &ngroups);
	struct group *gr;
	for(int i = 0; i < ngroups; i++) {
		gr = getgrgid(groups[i]);
		printf("%s ", gr->gr_name);
	}
	printf("\n");
	return 0;
}
