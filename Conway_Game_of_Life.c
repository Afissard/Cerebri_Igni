/*
Information :
Compile : gcc Conway_Game_of_Life.c -o ./bin/life -l ncurses
if targeting window : x86_64-w64-mingw32-gcc Conway_Game_of_Life.c -l ncurses -o ./bin/life.exe --static
*/

#include "Conway_Game_of_Life.h"


int main(){
    // ncurses setup
    initscr();
    //curs_set(0);
    cbreak();
    noecho(); // do not print the user input
    //nodelay(stdscr, true); // do not wait for the user input
    keypad(stdscr, TRUE);

    if(has_colors() == FALSE){	
        endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}
    start_color();
    init_pair(BLACK, COLOR_BLACK, COLOR_BLACK);
    init_pair(WHITE, COLOR_WHITE, COLOR_WHITE);

    init();
    simulation();

    // ncurses end
    mvprintw(40, 0, "Press anything to quit");
	getch();
	endwin();
    return 0;
}

void delay(int number_of_seconds){
    int milli_seconds = 1000 * number_of_seconds; // Converting time into milli_seconds
    clock_t start_time = clock(); // Storing start time
    while (clock() < start_time + milli_seconds){;} // looping till required time is not achieved
}

void init(){
    /* Initialisation of the game of life */
    seed = rand();
    srand(seed); // set seed when compiled
    mvprintw(33, 0, "Seed : %d", seed);

    /*
    mvprintw(34, 0, "Enter the number of generations : ");
    gen_nbr = getch();
    mvprintw(34, 0, "Number of generations targeted : %d.", gen_nbr);
    */

    for(int y=0; y < TAB_Y_SIZE-1; y++){
        for(int x=0; x < TAB_X_SIZE-1; x ++){
                tab[y][x] =  rand() % 2; // generate random number between 0 and 1;
                tab_buff[y][x] = tab[y][x];
                if(tab[y][x] == 0){
                    attron(COLOR_PAIR(BLACK));
                    mvprintw(y, x, "%d", tab[y][x]);
                    attroff(COLOR_PAIR(BLACK));
                }
                else{
                    attron(COLOR_PAIR(WHITE));
                    mvprintw(y, x, "%d", tab[y][x]);
                    attroff(COLOR_PAIR(WHITE));
                }
                
        }
    }
    //printf("Setup done.\n");
}

void update(){
    /*Apply the rule of the game of life*/
    for(int y=0; y < TAB_Y_SIZE-1; y++){
        for(int x=0; x < TAB_X_SIZE-1; x ++){

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
    /*Run the Game of Life*/
    nodelay(stdscr, true); // do not wait for the user input
    int ch =0;
    while (1){
        ch = getch();
        if(ch == KEY_UP){nodelay(stdscr, false); break;}
        mvprintw(40, 0, "To end press \"KEY_UP\".");

        mvprintw(35, 0, "Generation number %d.", gen);
        gen++;
        update();

        for(int y=0; y < TAB_Y_SIZE-1; y++){
            for(int x=0; x < TAB_X_SIZE-1; x ++){
                tab[y][x] = tab_buff[y][x];
                if(tab[y][x] == 0){
                    attron(COLOR_PAIR(BLACK));
                    mvprintw(y, x, "%d", tab[y][x]);
                    attroff(COLOR_PAIR(BLACK));
                }
                else{
                    attron(COLOR_PAIR(WHITE));
                    mvprintw(y, x, "%d", tab[y][x]);
                    attroff(COLOR_PAIR(WHITE));
                }
            }
        }
        refresh();
        delay(500);
    }
    /*
    for(int gen=0; gen < gen_nbr; gen++){
        move(35, 0);
        printw("Generation number %d.", gen);

        update();

        for(int y=0; y < TAB_SIZE-1; y++){
            for(int x=0; x < TAB_SIZE-1; x ++){
                tab[y][x] = tab_buff[y][x];
                mvprintw(y, x, "%d", tab[y][x]);
            }
        }
        refresh();
        delay(100);
    }*/
}