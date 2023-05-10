#include <stdio.h>
#include <stdlib.h>

#define TAB_SIZE 16

int tab[TAB_SIZE][TAB_SIZE] = {0};
int tab_buff[TAB_SIZE][TAB_SIZE] = {0};

int check_neighbors(int y, int x){
    int neighbors_nbr = 0;
    return neighbors_nbr;
};

int main(){
    // Initialisation part
    int gen_nbr;
    printf("Enter the number of generations : ");
    scanf("%d", &gen_nbr);

    for(int y; y < TAB_SIZE-1; y++){
        for(int x; x < TAB_SIZE-1; x ++){
                tab[y][x] = 0;
        }
    }

    // Simulation part
    for(int gen; gen < gen_nbr; gen++){
        printf("Generation number %d.\n", gen);

        for(int y; y < TAB_SIZE-1; y++){
            for(int x; x < TAB_SIZE-1; x ++){
                //check_neighbors(y, x);
                
                
                printf("%d", tab[y][x]);
            }
            printf("\n");
        }
    }

    printf("Conway\n");
    return 0;
}