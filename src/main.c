#include "commands.h"
#include "common.h"
#include "file_handler.h"

#include <string.h>

commands cmd_list;

uint8_t buffer[ROM_SIZE];

int main(int argc, char** argv) {
	// Check for arguments; don't even continue if they aren't correct
	if(argc <= 1) {
		printf("Invalid number of arguments!\n");
		printf("Usage: %s <file>\n", argv[0]);
		exit(1);
	}

	init_list();

	if(!(strcmp(argv[1], "--help"))) {
		_help();
		exit(0);
	}

	select_file(argv[1]);

	char command[256] = "";

	printf("Enter 'help' to display valid commands, 'exit' to exit the program.\n");
	while(1) {
		printf("Command> ");
		fflush(stdout);
		scanf("%s", command);

		interpret(command);
	}

	close_file();
	exit(0);
}
