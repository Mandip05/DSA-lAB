#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int stack[MAX], top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

int evaluatePrefix(char* expr) {
    int len = strlen(expr);
    for (int i = len - 1; i >= 0; i--) {
        if (isdigit(expr[i])) {
            push(expr[i] - '0');
        } else {
            int op1 = pop();
            int op2 = pop();
            switch (expr[i]) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
            }
        }
    }
    return pop();
}

int main() {
    char expr[MAX];
    printf("Enter prefix expression: ");
    scanf("%s", expr);
    printf("Result: %d\n", evaluatePrefix(expr));
    return 0;
}
