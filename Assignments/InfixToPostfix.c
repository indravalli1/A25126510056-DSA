#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char ch) {
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/' || ch == '%')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' ||
           ch == '*' || ch == '/' ||
           ch == '%' || ch == '^';
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, j = 0;
    char ch;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        // If operand, add directly to postfix
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }

        // If opening parenthesis
        else if (ch == '(') {
            push(ch);
        }

        // If closing parenthesis
        else if (ch == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }

            if (top != -1 && peek() == '(')
                pop();
        }

        // If operator
        else if (isOperator(ch)) {
            while (top != -1 &&
                   peek() != '(' &&
                   precedence(peek()) >= precedence(ch)) {

                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}