#include <stdio.h>
#include <sys/sysinfo.h>

int
main(void)
{
	int cores = get_nprocs_conf();
	printf("%i\n", cores);
	return 0;
}
