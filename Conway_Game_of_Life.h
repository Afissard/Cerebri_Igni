#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAB_SIZE 16

int tab[TAB_SIZE][TAB_SIZE] = {0};
int tab_buff[TAB_SIZE][TAB_SIZE] = {0};

int seed =0;
int gen_nbr =0;

void init();
void update();
void simulation();