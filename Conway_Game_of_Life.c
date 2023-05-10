#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAB_SIZE 16

int tab[TAB_SIZE][TAB_SIZE] = {0};
int tab_buff[TAB_SIZE][TAB_SIZE] = {0};

void update(){
    for(int y; y < TAB_SIZE-1; y++){
        for(int x; x < TAB_SIZE-1; x ++){

            int neighbors_nbr;
            neighbors_nbr = 
            tab[y-1][x-1]   + tab[y-1][x]   + tab[y-1][x+1] + 
            tab[y][x-1]     + 0             + tab[y][x+1] + 
            tab[y+1][x-1]   + tab[y+1][x]   + tab[y+1][x+1];

            if(neighbors_nbr <3){           // Lonely
                tab_buff[y][x] = 0;
            }
            else if (neighbors_nbr = 3){    // Survive
                tab_buff[y][x] = tab[y][x];
            }
            else if (neighbors_nbr >3){     // Overpopulated
                tab_buff[y][x] = 1;
            }
        }
    }
}

int main(){
    // Initialisation part
    int seed = rand();
    srand(seed); // set seed to 42
    printf("Seed : %d\n", seed);

    int gen_nbr;
    printf("Enter the number of generations : ");
    scanf("%d", &gen_nbr);

    for(int y; y < TAB_SIZE-1; y++){
        for(int x; x < TAB_SIZE-1; x ++){
                tab[y][x] =  rand() % 1; // generate random number between 0 and 1;
                tab_buff[y][x] = tab[y][x];
        }
    }
    printf("Setup done.\n");

    // Simulation part
    for(int gen; gen < gen_nbr; gen++){
        printf("Generation number %d.\n", gen);

        update();

        for(int y; y < TAB_SIZE-1; y++){
            for(int x; x < TAB_SIZE-1; x ++){
                tab[y][x] = tab_buff[y][x];
                printf("%d", tab[y][x]);
            }
            printf("\n");
        }
    }

    printf("Conway\n");
    return 0;
}