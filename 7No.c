#include <stdio.h>
#define MAXSIZE 5

int queue[MAXSIZE];
int front = 0, rear = -1;

int isempty() {
    if (rear == -1)
        return 1;
    else 
        return 0;
}

int isfull() {
    if (rear == MAXSIZE - 1)
        return 1;
    else
        return 0;
}

void enqueue(int data) {
    if (isfull())
        printf("Queue is full.\n");
    else {
        rear++;
        queue[rear] = data;
        printf("%d enqueued successfully\n", data);
    }
}

void dequeue() {
    int data, i, min_idx = front;
    if (isempty()) {
        printf("Queue is empty.\n");
        return;
    }
    
    // Find element with minimum value (highest priority)
    for (i = front + 1; i <= rear; i++) {
        if (queue[i] < queue[min_idx]) {
            min_idx = i;
        }
    }
    
    // Remove the minimum element and shift others
    data = queue[min_idx];
    for (i = min_idx; i < rear; i++) {
        queue[i] = queue[i + 1];
    }
    rear--;
    printf("Dequeued element with highest priority: %d\n", data);
}

void display() {
    if (isempty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    // Demonstrate priority queue operations
    printf("Inserting elements into priority queue...\n");
    enqueue(1);  // Lower value = Higher priority
    enqueue(2);
    enqueue(10);
    enqueue(20);
    
    display();
    
    printf("\nRemoving elements based on priority...\n");
    dequeue();  // Will remove 1 (highest priority)
    display();
    
    dequeue();  // Will remove 2 (next highest priority)
    display();
    
    return 0;
}

