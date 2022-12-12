#pragma once

#include "common.h"

extern FILE* working_file;

void select_file(char path[4096]);

void write_to_file(uint8_t buffer[32768]);

void close_file();