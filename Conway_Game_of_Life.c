#include "Conway_Game_of_Life.h"

int main(){
    init();
    simulation();
    return 0;
}

void init(){
    /* Initialisation of the game of life */
    seed = rand();
    srand(seed); // set seed when compiled
    printf("Seed : %d\n", seed);

    printf("Enter the number of generations : ");
    scanf("%d", &gen_nbr);

    for(int y=0; y < TAB_SIZE-1; y++){
        for(int x=0; x < TAB_SIZE-1; x ++){
                tab[y][x] =  rand() % 2; // generate random number between 0 and 1;
                tab_buff[y][x] = tab[y][x];
                printf("%d", tab[y][x]);
        }
        printf("\n");
    }
    printf("Setup done.\n");
}

void update(){
    /*Apply the rule of the game of life*/
    for(int y=0; y < TAB_SIZE-1; y++){
        for(int x=0; x < TAB_SIZE-1; x ++){

            int neighbors_nbr;
            // TODO: prevent going out of range of the board: may cause memory leaks ?
            neighbors_nbr = 
            tab[y-1][x-1]   + tab[y-1][x]   + tab[y-1][x+1] + 
            tab[y][x-1]     + 0             + tab[y][x+1] + 
            tab[y+1][x-1]   + tab[y+1][x]   + tab[y+1][x+1]; 

            if(neighbors_nbr <2){                               // Lonely
                tab_buff[y][x] = 0;
            }
            else if ((neighbors_nbr ==2) | (neighbors_nbr ==3)){// Survive or Birth
                tab_buff[y][x] = 1;
            }
            else if (neighbors_nbr >3){                         // Overpopulated
                tab_buff[y][x] = 0;
            }
        }
    }
}

void simulation(){
    // Simulation part
    for(int gen=0; gen < gen_nbr; gen++){
        printf("Generation number %d.\n", gen);

        update();

        for(int y=0; y < TAB_SIZE-1; y++){
            for(int x=0; x < TAB_SIZE-1; x ++){
                tab[y][x] = tab_buff[y][x];
                printf("%d", tab[y][x]);
            }
            printf("\n");
        }
    }
}