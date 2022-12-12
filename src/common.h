#pragma once

#define ROM_SIZE 524288 // 512 * 1024

#include "commands.h"
#include "colors.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

extern uint8_t buffer[ROM_SIZE];
