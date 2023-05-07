/* 
PROJECT INFORMATIONS :
This is a side project of my current projet of creating a full
tui app without any other library than the standard one's in C.

GOAL :
Create a brainfuck interpreter in C without any documention else
than the wiki page of Brainfuck : https://en.wikipedia.org/wiki/Brainfuck .

TODO :
- Add safty.

OTHER INFORMATIONS :
compile : gcc main.c -o cerebri_version-name
run     : ./cerebri_version-name

*/

#include <stdio.h>
#include <string.h>

#define PGR_SIZE 256
#define MEM_SIZE 1024
#define HELLO_WORLD "+[-->-[>>+>-----<<]<--<---]>-.>>>+.>>..+++[.>]<<<<.+++.------.<<-.>>>>+."
#define PROG_TEST ".+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++."

char program[PGR_SIZE] = "";

unsigned char data[MEM_SIZE] = {0};
unsigned char* data_ptr = data;

unsigned int L_entry;
unsigned int L_exit;


void move_right();
void move_left();
void increase();
void decrease();
void ouput();
void input();
void loop_entry();
void loop_exit();

int main(){
    // initialisation
    //for(int i; i < MEM_SIZE; i++){data[i] = 0;} // fill the data
    strcpy(program, PROG_TEST);
    printf("%s\n:", program);

    // execution
    for(int i; i < PGR_SIZE; i++){
        switch (program[i]){
        case '>': move_right(); break;
        case '<': move_left();  break;
        case '+': increase();   break;
        case '-': decrease();   break;
        case '.': ouput();      break;
        case ',': input();      break;
        case '[': loop_entry(); break;
        case ']': loop_exit();  break;
        default: // ignore all the rest : there are comment
            break;
        }
    }

    printf(":\nCerebri Igni ! \n");
    return 0;
}

void move_right(){
    if (*data_ptr < MEM_SIZE){
        data_ptr ++;
    }
}

void move_left(){
    if (*data_ptr > 0){
        data_ptr --;
    }
}

void increase(){
    if(*data_ptr > sizeof(unsigned char)){
        *data_ptr ++;
    }
}

void decrease(){
    if(*data_ptr < 0){
        *data_ptr --;
    }
}

void ouput(){
    putchar(*data_ptr);
}

void input(){
    *data_ptr = getchar();
}

void loop_entry(){
    L_entry = *data_ptr;
    if(*data_ptr == 0){
        *data_ptr = L_exit+1;
    }
}

void loop_exit(){
    L_exit = *data_ptr;
    if(*data_ptr == 0){
        *data_ptr = L_entry+1;
    }
}