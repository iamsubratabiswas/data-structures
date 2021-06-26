/*Write a C program to generate Fibonacci sequence using stack*/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>


// using INT_MIN to represent underflow
// stack can only store values belonging to [INT_MIN - 1, INT_max]
#define UNDERFLOW INT_MIN
#define SUCCESS 1
#define ERROR 0

typedef struct LinkedList_node* Node;
typedef struct Stack_node* Stack;

struct LinkedList_node {
    int data;
    Node next;
};

struct Stack_node {
    Node head;
    int size;
};

void generateFibonacci(int n);

// Stack functions :
Stack newStack();
int stackSize(Stack s);
int isEmpty(Stack s);
int push(Stack s, int data);
int pop(Stack s);
int top(Stack s);



// Generating fibonacci
void generateFibonacci(int n) {
    Stack fib = newStack();
    if (n > 0) {
        printf("%d ", 0);
        push(fib, 0);
    }
    if (n > 1) {
        printf("%d ", 1);
        push(fib, 1);
    }
    for (int i = 3; i <= n; i++) {
        int last = pop(fib);
        int slast = pop(fib);
        int newTop = last + slast;
        printf("%d ", newTop);
        push(fib, slast);
        push(fib, last);
        push(fib, newTop);
    }
    printf("\n");
}

int main() {
    printf("Enter a positive number : ");
    int n;
    scanf("%d", &n);
    printf("Fibonacci sequence : \n");
    generateFibonacci(n);
    return 0;
}

/** STACK FUNCTIONS*/
// returns a new Stack
Stack newStack() {
    Stack s = (Stack)malloc(sizeof *s);
    s->head = NULL;
    s->size = 0;
    return s;
}

int stackSize(Stack s) {
    return s->size;
}

// returns  1 if Stack is empty
//          0 if Stack is not empty
int isEmpty(Stack s) { return !(s->size); }

/**
 * Pushed data onto Stack s
 * Fails to push data if :
 *  data == UNDERFLOW, or
 *  malloc fails to allocate memory for new LinkedList_node 
 * 
 * returns SUCCESS : if pushed successfully
 *         ERROR   : if some errors occured
 */
int push(Stack s, int data) {
    if (data == UNDERFLOW) {
        printf("The vaule %d cannot be stored in stack!\n", UNDERFLOW);
        return ERROR;
    }
    Node newNode = (Node)malloc(sizeof *newNode);
    if (!newNode) {
        printf("Memory allocation error!\n");
        return ERROR;
    }
    newNode->data = data;
    newNode->next = s->head;
    s->head = newNode;
    s->size++;
    // printf("pushed : %d\n", data);
    return SUCCESS;
}

/**
 * pops the last pushed (top most) element and returns the value
 *  returns UNDERFLOW if Stack is empty 
 */
int pop(Stack s) {
    if (isEmpty(s)) {
        // printf("Underflow!\n");
        return UNDERFLOW;
    }
    int data = s->head->data;
    Node to_free = s->head;
    s->head = s->head->next;
    free(to_free);
    s->size--;
    // printf("popped : %d\n", data);
    return data;
}

/**
 * returns the last pushed (top most) element without poping it 
 *  returns UNDERFLOW if Stack is Empty
 */
int top(Stack s) {
    if (isEmpty(s)) {
        // printf("Underflow!\n");
        return UNDERFLOW;
    }
    // printf("top : %d\n", s->head->data);
    return s->head->data;
}