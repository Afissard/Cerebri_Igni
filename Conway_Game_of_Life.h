#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

#define BLACK 1
#define WHITE 2
#define TAB_Y_SIZE 32
#define TAB_X_SIZE 128

int tab[TAB_Y_SIZE][TAB_X_SIZE] = {0};
int tab_buff[TAB_Y_SIZE][TAB_X_SIZE] = {0};

int seed = 0;
unsigned long gen = 0;
int gen_nbr = 100; // default number (and prevent error)

void delay(int);
void init();
void update();
void simulation();