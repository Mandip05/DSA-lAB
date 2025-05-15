#include <stdio.h>

// Algorithm for Enqueue:
// 1. Check if queue is full
// 2. If not full, increment rear
// 3. Add element at rear position
// 4. If this is first element, set front to 0

// Algorithm for Dequeue:
// 1. Check if queue is empty
// 2. If not empty, get element at front
// 3. Increment front
// 4. If front exceeds rear, reset front and rear to -1
// 5. Return the dequeued element

int queue[100];
int front = -1, rear = -1;
int maxSize;

void enqueue(int data) {
    if (rear == maxSize - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = data;
    printf("%d enqueued successfully\n", data);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }
    printf("%d dequeued successfully\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are:\n");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, data;
    
    printf("Enter the maximum size of queue: ");
    scanf("%d", &maxSize);
    
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
