#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int item) {
    if(top == MAX-1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
    printf("%d pushed to stack\n", item);
}

void pop() {
    if(top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d popped from stack\n", stack[top]);
    top--;
}

void display() {
    if(top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for(int i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
}

int main() {
    push(5);
    push(10);
    push(20);
    display();
    pop();
    display();
    return 0;
}
