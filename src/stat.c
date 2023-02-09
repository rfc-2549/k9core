#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

int
main(int argc, char **argv)
{
	if(argc == 1) {
		fprintf(stderr, "usage: stat FILE...\n");
		return 1;
	}
	char mod_date[64], acc_date[64], creat_date[64];
	struct stat file_data;
	for(int i = 1; i < argc; i++) {
		if(stat(argv[i], &file_data) == -1) {
			printf("Cannot stat '%s': %s\n", argv[i], strerror(errno));
			continue;
		}
		/* About file size, location... */
		printf("File: %s\nSize: %lu\t blocks: %li\t IO Block: %li\nDevice: "
			  "%lu\t",
			  argv[i],
			  file_data.st_size,
			  file_data.st_blocks,
			  file_data.st_blksize,
			  file_data.st_dev);
		/* File permisions
		 * TODO: Display only the permissions (644) instead of the whole mode
		 * (100644)
		 */
		printf("Inode: %u\t Links: %lu\nAccess: %o\tUid: %u\tGid:%u\n",
			  file_data.st_gid,
			  file_data.st_nlink,
			  file_data.st_mode,
			  file_data.st_uid,
			  file_data.st_gid);
		/* Access, creation and modification date */
		struct tm *timeinfo;
		/* Modification time */
		timeinfo = localtime(&file_data.st_mtim.tv_sec);
		strftime(mod_date, 64, "%F %H:%M:%S", timeinfo);
		/* Creation time */

		timeinfo = localtime(&file_data.st_ctim.tv_sec);
		strftime(creat_date, 64, "%F %H:%M:%S", timeinfo);

		/* Access time */
		timeinfo = localtime(&file_data.st_atim.tv_sec);
		strftime(acc_date, 64, "%F %H:%M:%S", timeinfo);

		printf("Access: %s\nModify: %s\nCreation %s\n",
			  acc_date,
			  mod_date,
			  creat_date);
	}

	return 0;
}
