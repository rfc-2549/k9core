#include <getopt.h>
#include <stdio.h>
#include <string.h>
#include <sys/utsname.h>

const char *
get_operating_system()
{
#ifdef __gnu_linux__
	return "GNU/Linux";
#endif
#ifdef __FreeBSD__
	return "FreeBSD";
#endif
#ifdef __OpenBSD__
	return "OpenBSD";
#endif
#ifdef _WIN32
	return "Here's a USB stick kid, get a real operating system";
#endif
	return "Unknown operating system";
}

int
main(int argc, char *argv[])
{
	int c;
	int all = 0;
	int machine = 0;
	int node_name = 0;
	int kernel_release = 0;
	int kernel_name = 0;
	int operating_system = 0;
	int nothing = 0;
	struct utsname kernel_info;

	if(argc == 1)
		nothing = 1;
	while((c = getopt(argc, argv, "amnrsv")) != -1) {
		switch(c) {
			case 'a':
				all = 1;
				break;
			case 'm':
				machine = 1;
				break;
			case 'n':
				node_name = 1;
				break;
			case 'r':
				kernel_release = 1;
				break;
			case 's':
				kernel_name = 1;
				break;
			case 'v':
				operating_system = 1;
				break;
		}
	}

	uname(&kernel_info);

	if(all) {
		printf("%s %s %s %s %s %s\n",
			  kernel_info.sysname,
			  kernel_info.nodename,
			  kernel_info.release,
			  kernel_info.version,
			  kernel_info.machine,
			  get_operating_system());
	} else {
		if(machine)
			printf("%s ", kernel_info.machine);
		if(node_name)
			printf("%s ", kernel_info.nodename);
		if(kernel_release)
			printf("%s ", kernel_info.release);
		if(kernel_name || nothing)
			printf("%s ", kernel_info.sysname);
		if(operating_system)
			printf("%s", get_operating_system());
		printf("\n");
	}
	return 0;
}
