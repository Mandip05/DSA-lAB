#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int data) {
    if ((front == 0 && rear == MAX-1) || (front == rear+1)) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX-1) {
        rear = 0;
    } else {
        rear++;
    }
    queue[rear] = data;
    printf("%d enqueued\n", data);
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("%d dequeued\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX-1) {
        front = 0;
    } else {
        front++;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    } else {
        for (int i = front; i < MAX; i++)
            printf("%d ", queue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(5);
    enqueue(10);
    enqueue(15);
    display();
    dequeue();
    enqueue(20);
    display();
    return 0;
}


