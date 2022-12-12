#include "file_handler.h"
#include <string.h>

FILE* working_file = NULL;

void select_file(char path[4096]) {
	working_file = fopen(path, "wb+");
	if (working_file == NULL) {
		fprintf(stderr, "Error when opening/creating file: %s\n", strerror(errno));
		exit(1);
	}
}

void write_to_file(uint8_t buffer[ROM_SIZE]) {
	fwrite(buffer, sizeof(uint8_t[ROM_SIZE]), 1, working_file);
}

void close_file() {
	fclose(working_file);
}