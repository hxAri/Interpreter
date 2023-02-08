#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum TokenType {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    INTEGER,
    EXIT,
    UNKNOWN
};

struct Token {
    enum TokenType type;
    int value;
};

void get_token(char *input, struct Token *token) {
    if (strcmp(input, "add") == 0) {
        token->type = ADD;
    } else if (strcmp(input, "subtract") == 0) {
        token->type = SUBTRACT;
    } else if (strcmp(input, "multiply") == 0) {
        token->type = MULTIPLY;
    } else if (strcmp(input, "divide") == 0) {
        token->type = DIVIDE;
    } else if (strcmp(input, "exit") == 0) {
        token->type = EXIT;
    } else {
        token->value = atoi(input);
        if (token->value == 0 && input[0] != '0') {
            token->type = UNKNOWN;
        } else {
            token->type = INTEGER;
        }
    }
}

int evaluate_expression(int first, int second, struct Token operation) {
    switch (operation.type) {
        case ADD:
            return first + second;
        case SUBTRACT:
            return first - second;
        case MULTIPLY:
            return first * second;
        case DIVIDE:
            return first / second;
        default:
            printf("Error: Invalid operation\n");
            exit(1);
    }
}

int parse_expression(char *input, int *pos) {
    int first = 0;
    int second = 0;
    struct Token operation;
    struct Token token;
    
    get_token(input + *pos, &token);
    if (token.type == INTEGER) {
        first = token.value;
        *pos += strlen(input + *pos) + 1;
        get_token(input + *pos, &operation);
        if (operation.type == ADD || operation.type == SUBTRACT ||
            operation.type == MULTIPLY || operation.type == DIVIDE) {
            *pos += strlen(input + *pos) + 1;
            second = parse_expression(input, pos);
            first = evaluate_expression(first, second, operation);
        }
    }
    
    return first;
}

int main() {
    char input[100];
    int pos = 0;
    int result = 0;
    
    while (1) {
        printf(">>> ");
        scanf("%[^\n]%*c", input);
        
        pos = 0;
        result = parse_expression(input, &pos);
        printf("Result: %d\n", result);
    }
    
    return 0;
}
