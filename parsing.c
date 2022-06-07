#include <stdio.h>
#include <stdlib.h>


/* If we are compiling on Windows compile these functions */
#ifdef _WIN64
#include <string.h>

#define BUFFER_SIZE 2048

static char buffer[BUFFER_SIZE];

/* Fake readline function */
char* readline(char* prompt) {
    fputs(prompt, stdout);
    fgets(buffer, BUFFER_SIZE, stdin);
    char* cpy = malloc(strlen(buffer) + 1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy) - 1] = '\0';
    return cpy;
}

/* Fake add_history function */
void add_history(char* unused) {}

/* Otherwise include the editline headers */
#else
#include <editline/readline.h>
#include <editline/history.h>
#endif


int main(int argc, char** argv) {
    /* Print Version and Exit Information */
    puts("Clisp Version 0.0.0.0.1");
    puts("Press Ctrl+c to Exit\n");

    while(1) {
        char* input = readline("clisp> ");
        add_history(input);

        printf("No you're a %s\n", input); 
        free(input);
    }
    
    return 0;
}
