#include "common.h"
#include "file_handler.h"

#include <string.h>

void __exit() { exit(0); }
void _help();
void _flush();
void dummy() { asm("nop"); }

void init_list() {
	for (uint8_t i = 0; i < 16; i++) {
		cmd_list[i] = (command) {"", "", dummy};
	}
	cmd_list[0] = (command) {"help", 	"Displays this message and all of the commands.", 	_help	};
	cmd_list[1] = (command) {"exit", 	"Exit the program without saving changes.", 		__exit	};
	cmd_list[2] = (command) {"flush", 	"Write changes to the file selected.", 				_flush	};
}

void interpret(char* command) {
	uint8_t match = 0;
	for (uint16_t i = 0; i < 16; i++) {
		if(!(strcmp(cmd_list[i].name, command))) {
			if(cmd_list[i].callback == NULL) {
				printf("%sCommand exists, but is not implemented!%s\n", RED, RESET);
				match = 1;
				continue;
			}
			cmd_list[i].callback();
			match = 1;
		}
	}
	if(!match) {
		printf("%sCommand not found! Enter 'help' to get a list of the valid commands.%s\n", RED, RESET);
	}
}

void _help() {
	printf("%sList of commands:%s\n", BHWHT, RESET);
	for (uint8_t i = 0; i < 16; i++) {
		if(strcmp(cmd_list[i].name, "")) {
			printf("%s%s: %s%s%s\n", BYEL, cmd_list[i].name, YEL, cmd_list[i].desc, RESET);
		}
	}
}

void _flush() {
	fwrite(buffer, sizeof(uint8_t[ROM_SIZE]), 1, working_file);
}