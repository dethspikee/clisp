#include <stdio.h>


#define BUFFER_SIZE 2048

/* Declare a buffer for user input of size BUFFER_SIZE */
static char input[BUFFER_SIZE];

int main(int argc, char** argv) {
    /* Print Version and Exit Information */
    puts("Clisp Version 0.0.0.0.1");
    puts("Press Ctrl+c to Exit\n");

    while(1) {
        fputs("clisp> ", stdout);

        fgets(input, BUFFER_SIZE, stdin);

        printf("No you're a %s", input); 
    }
    
    return 0;
}
