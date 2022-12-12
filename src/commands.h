#pragma once

#include "common.h"

typedef struct command {
	char name[16];
	char desc[512];
	void (*callback) (); 	// I can't use commands* because it's not declared yet,
								// so I replaced it with void* and will cast it when needed
} command;

typedef command commands[64];

extern commands cmd_list;

void init_list();

void interpret(char* command);

void _help();