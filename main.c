/* 
PROJECT INFORMATIONS :
The main goal of this side project is to create a sort ofesoteric 
programming language, turing complete, of my own...
My main inspiration for this language is the Orca "programming"
language : https://esolangs.org/wiki/Orca and Minecraft Redstone.

OBJECTIVES :
- Retro challenge : 16bit era (variable type)
- The interpreter will have to be as minimalist as possible.
- The language have to be easy to understand, but hard to master.
- The program could be edit in live like Orca, and save in some sort of txt file.

PS : "Cerebri Igni" mean "Brain in fire" in Latin. This is
just the code name of my project. 

TODO :
- All

OTHER INFORMATIONS :
compile : gcc main.c -l ncurses -o bin/cerebri
run     : ./bin/cerebri
*/

#include "main.h"

int main(){
    // SETUP
    initscr();
    //curs_set(0);
    //cbreak();
    noecho(); // do not print the user input
    //nodelay(stdscr, true);
    //keypad(stdscr, TRUE);

    if (has_colors() == false){
        perror("Terminal doesn't support colors");
        return 1;
    }
    // ACTUAL PROGRAM
    printw("Hello World! Press any key to exit ...");
	refresh();
	getch();
	endwin();
    return 0;
}