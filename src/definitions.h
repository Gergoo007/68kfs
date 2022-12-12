#pragma once

#include "common.h"

typedef struct fs_header {
	char label[256];
	uint64_t size;
	uint64_t pos;
} fs_header;

typedef struct file_header {
	uint64_t modified;
	uint64_t created;
	char name[256];
	char path[4096];
} file_header;
