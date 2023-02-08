#include <stdio.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

// Btw I'm so boring
int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        printf(">>> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Remove newline character from the end of the command
        int length = strlen(command);
        if (command[length - 1] == '\n') {
            command[length - 1] = '\0';
        }

        // Exit the interpreter when the "exit" command is entered
        if (strcmp(command, "exit") == 0) {
            break;
        }

        // Add your own commands here
        if (strcmp(command, "hello") == 0) {
            printf("Hello, World!\n");
        } else {
            printf("Unknown command.\n");
        }
    }

    return 0;
}
