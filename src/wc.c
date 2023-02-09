#include <ctype.h>
#include <errno.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int show_lines, show_words, show_bytes;
struct wc_values data;

struct wc_values
{
	int lines;
	int bytes;
	int words;
	int total_lines;
	int total_bytes;
	int total_words;
};

int
wc(const char *filename, struct wc_values *data)
{
	FILE *file = fopen(filename, "r");
	if(file == NULL) {
		fprintf(stderr,
			   "error opening file %s: %s\n",
			   filename,
			   strerror(errno));
		return -1;
	}
	size_t c;
	char buf;
	int newlines, spaces, bytes = 0;
	newlines = spaces = bytes = 0;
	while((c = fread(&buf, 1, 1, file)) > 0) {
		if(!isascii(buf))
			buf = toascii(buf);
		bytes++;
		if(buf == '\n')
			newlines++;
		if(isspace(buf))
			spaces++;
	}
	data->bytes = bytes;
	data->lines = newlines;
	data->words = spaces;

	data->total_bytes += data->bytes;
	data->total_lines += data->lines;
	data->total_words += data->words;

	fclose(file);
	return 0;
}

void
print_values(const char *filename, struct wc_values data)
{
	if(show_bytes && show_lines && show_words)
		printf("%i %i %i", data.lines, data.words, data.bytes);
	else {
		if(!show_lines)
			printf("%i ", data.lines);
		if(!show_words)
			printf("%i ", data.words);
		if(!show_bytes)
			printf("%i ", data.bytes);
	}
	printf(" %s\n", filename);
}

int
main(int argc, char *argv[])
{
	int c;
	struct wc_values data;
	data.total_bytes = data.total_lines = data.total_words = 0;
	int return_value = 0; /* Please let me know a better name */
	show_lines = show_words = show_bytes = 1;
	/* Process arguments */
	while((c = getopt(argc, argv, "lwcm")) > 0) {
		switch(c) {
			case 'l':
				show_lines = 0;
				break;
			case 'w':
				show_words = 0;
				break;
			case 'c':
			case 'm':
				show_bytes = 0;
				break;
		}
	}
	if(optind == argc) {
		wc("/dev/stdin", &data); /* lol */
		print_values("stdin", data);
	} else
		for(int i = optind; i < argc; i++) {
			if(argv[i][0] == '-' && argv[i][1] == '\0')
				return_value = wc("/dev/stdin", &data);
			else
				return_value = wc(argv[i], &data);
			if(return_value == 0)
				print_values(argv[i], data);
		}
	if(argc > optind + 1)
		printf("%i %i %i total\n",
			  data.total_lines,
			  data.total_words,
			  data.total_bytes);

	return 0;
}
