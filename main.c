#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COMMAND_LENGTH 100

void add(int a, int b) {
    printf("%d\n", a + b);
}

void subtract(int a, int b) {
    printf("%d\n", a - b);
}

void multiply(int a, int b) {
    printf("%d\n", a * b);
}

void divide(int a, int b) {
    printf("%d\n", a / b);
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char *token;
    int a, b;
    
    while (1) {
        printf(">>> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        
        token = strtok(input, " ");
        if (strcmp(token, "exit\n") == 0) {
            break;
        } else if (strcmp(token, "add\n") == 0) {
            a = atoi(strtok(NULL, " "));
            b = atoi(strtok(NULL, " "));
            add(a, b);
        } else if (strcmp(token, "subtract\n") == 0) {
            a = atoi(strtok(NULL, " "));
            b = atoi(strtok(NULL, " "));
            subtract(a, b);
        } else if (strcmp(token, "multiply\n") == 0) {
            a = atoi(strtok(NULL, " "));
            b = atoi(strtok(NULL, " "));
            multiply(a, b);
        } else if (strcmp(token, "divide\n") == 0) {
            a = atoi(strtok(NULL, " "));
            b = atoi(strtok(NULL, " "));
            divide(a, b);
        } else {
            printf("Unsupported command: %s", input);
        }
    }
    
    return 0;
}
