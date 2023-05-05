/* 
PROJECT INFORMATIONS :
This is a side project of my current projet of creating a full
tui app without any other library than the standard one's in C.

GOAL :
Create a brainfuck interpreter in C without any documention else
than the wiki page of Brainfuck : https://en.wikipedia.org/wiki/Brainfuck .

TODO :
Add safty.

OTHER INFORMATIONS :
compile : gcc main.c -o cerebri_version-name
run     : ./cerebri_version-name

*/

#include <stdio.h>
#include <string.h>

#define PGR_SIZE 256
#define MEM_SIZE 1024
#define HELLO_WORLD "+[-->-[>>+>-----<<]<--<---]>-.>>>+.>>..+++[.>]<<<<.+++.------.<<-.>>>>+."

char program[PGR_SIZE] = "";

unsigned char memory[MEM_SIZE] = {};
unsigned int mem_ptn = 0;

void move_right();
void move_left();
void increase();
void decrease();

int main(){

    strcpy(program, HELLO_WORLD);
    printf("%s\n", program);

    for(int i; i < PGR_SIZE; i++){
        switch (program[i]){
        case '>': move_right(); break;
        case '<': move_left();  break;
        case '+': increase();   break;
        case '-': decrease();   break;
        case '.': printf("%c", memory[mem_ptn]);            break;
        case ',': scanf("input %c \n", &memory[mem_ptn]);   break;
        case '[':
            break;
        case ']':
            break;
        default:
            break;
        }
    }

    printf("\nCerebri Igni ! \n");
    return 0;
}

void move_right(){
    if (mem_ptn < MEM_SIZE){
        mem_ptn ++;
    }
}

void move_left(){
    if (mem_ptn > 0){
        mem_ptn --;
    }
}

void increase(){
    if(memory[mem_ptn] > 255){
        memory[mem_ptn] ++;
    }
}

void decrease(){
    if(memory[mem_ptn] < 0){
        memory[mem_ptn] --;
    }
}
