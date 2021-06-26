/*Implement a stack using queue using C Program.*/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define UNDERFLOW INT_MIN
#define SUCCESS 1
#define ERROR 0

// Queue structures and function prototypes.
typedef struct ListNode* Node;
typedef struct QueueStr* Queue;

struct ListNode {
    int data;
    Node next;
};

struct QueueStr {
    int size;
    Node first; //front of queue
    Node last;  //rear of queue
};

Node newNode(int data);
Queue newQueue();
int size(Queue x);
int isEmpty(Queue x);
int enqueue(Queue x, int data);
int dequeue(Queue x);
int front(Queue x);
int rear(Queue x);
int printQueue(Queue x);

// Stack structures and prototypes
typedef struct StackStr* Stack;

struct StackStr {
    Queue s;
    Queue aux;
};

Stack newStack();
int isStackEmpty(Stack x);
int push(Stack x, int data);
int pop(Stack x);
int top(Stack x);
int sizeOfStack(Stack x);

Stack newStack() {
    Stack x = (Stack)malloc(sizeof(*x));
    if (!x) return NULL;
    x->s = newQueue();
    if (!(x->s)) {
        free(x);
        return NULL;
    }
    x->aux = newQueue();
    if (!(x->aux)) {
        free(x->s);
        free(x);
        return NULL;
    }
    return x;
}

int isStackEmpty(Stack x) {
    return isEmpty(x->s);
}

int push(Stack x, int data) {
    return enqueue(x->s, data);
}

int pop(Stack x) {
    while (size(x->s) > 1) enqueue(x->aux, dequeue(x->s));
    int data = dequeue(x->s);
    while (!isEmpty(x->aux)) enqueue(x->s, dequeue(x->aux));
    return data;
}

int top(Stack x) {
    return rear(x->s);
}

int sizeOfStack(Stack x) {
    return size(x->s);
}

void test() {
    Stack x = newStack();
    if (!x) {
        printf("Error occured exiting!\n");
        return;
    }
    int ch = 1;
    while (ch) {
        printf("0:Exit  ");
        printf("1:push  ");
        printf("2:pop  ");
        printf("3:top  ");
        printf("4:isEmpty  ");
        printf("5:size\n");
        printf("Enter choice : ");
        scanf("%d", &ch);
        int data;
        switch (ch) {
            case 0:
                break;
            case 1:
                printf("Enter data : ");
                scanf("%d", &data);
                if (push(x, data) == SUCCESS)
                    printf("Pushed %d\n", data);
                break;
            case 2:
                data = pop(x);
                if (data != UNDERFLOW) 
                    printf("Popped %d.\n", data);
                else 
                    printf("Error : Underflow!\n");
                break;
            case 3 : 
                data = top(x);
                if (data != UNDERFLOW) 
                    printf("Top : %d\n", data);
                else 
                    printf("Error : Stack is Empty!\n");
                break;
            case 4:
                if (isStackEmpty(x))
                    printf("Stack is empty\n");
                else 
                    printf("Stack is not empty\n");
                break;
            case 5:
                printf("Size : %d\n", sizeOfStack(x));
                break;
            
            default:
                printf("Invalid choice.\n");
        }
        printf("\n");
    }
}

int main() {
    test();
    return 0;
}

/* Queue Functions*/

Node newNode(int data) {
    Node x = (Node)malloc(sizeof(*x));
    if (!x) return NULL;
    x->data = data;
    x->next = NULL;
    return x;
}

Queue newQueue() {
    Queue x = (Queue)malloc(sizeof(*x));
    if (!x) return NULL;
    x->first = NULL;
    x->last = NULL;
    x->size = 0;
    return x;
}

int size(Queue x) {
    return x->size;
}

// must use size!
int isEmpty(Queue x) {
    return !(x->size);
}

int enqueue(Queue x, int data) {
    if (data == UNDERFLOW) return ERROR;
    Node nNode = newNode(data);
    if (!nNode) return ERROR;

    if (isEmpty(x)) {
        x->first = nNode;
        x->last = nNode;
        x->size++;
        return SUCCESS;
    }

    x->last->next = nNode;
    x->last = nNode;
    x->size++;
    return SUCCESS;
}

int dequeue(Queue x) {
    if (isEmpty(x)) return UNDERFLOW;

    Node first = x->first;
    x->first = x->first->next;
    x->size--;
    if (isEmpty(x)) {
        x->first = NULL;
        x->last = NULL;
    }
    int data = first->data;
    free(first);
    return data;
}

int front(Queue x) {
    if (isEmpty(x)) return UNDERFLOW;
    return x->first->data;
}

int rear(Queue x) {
    if (isEmpty(x)) return UNDERFLOW;
    return x->last->data;
}

int printQueue(Queue x) {
    Node cur = x->first;
    printf("Queue : ");
    while (cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}