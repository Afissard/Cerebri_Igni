#include <ncurses.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SMALL_PROGRAM_SIZE 16*16
#define PROGRAM_SIZE 256*256

char objects_statuts[16][16] = {
    "input",
    "output",
    "right",
    "left"
    "up",
    "down"
};

typedef struct object{
    char display;
    uint8_t value;
    uint8_t statut_ptr;
} object;

object program_actual[SMALL_PROGRAM_SIZE];
object program_buffer[SMALL_PROGRAM_SIZE];
