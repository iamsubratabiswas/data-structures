/*Write a C program to find the minimum element of a stack.*/

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
    Node min;
    int size;
};

void test();

// Stack functions :
Stack newStack();
int stackSize(Stack s);
int isEmpty(Stack s);
int push(Stack s, int data);
int pop(Stack s);
int top(Stack s);
int min(Stack s);

// returns a new Stack
Stack newStack() {
    Stack s = (Stack)malloc(sizeof *s);
    s->head = NULL;
    s->size = 0;
    return s;
}

int min(Stack s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return UNDERFLOW;
    } else
        return s->min->data;
}

// returns the size of the stack
int stackSize(Stack s) { return s->size; }

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
    Node newMinNode = (Node)malloc(sizeof *newNode);
    if (!newMinNode) {
        free(newNode);
        printf("Memory allocation error!\n");
        return ERROR;
    }
    newNode->data = data;
    newNode->next = s->head;
    s->head = newNode;
    s->size++;
    if (s->size == 1 || s->min->data >= data) {
        newMinNode->data = data;
        newMinNode->next = s->min;
        s->min = newMinNode;
    } else {
        free(newMinNode);
    }
    printf("pushed : %d\n", data);
    return SUCCESS;
}

/**
 * pops the last pushed (top most) element and returns the value
 *  returns UNDERFLOW if Stack is empty
 */
int pop(Stack s) {
    if (isEmpty(s)) {
        printf("Underflow!\n");
        return UNDERFLOW;
    }
    int data = s->head->data;
    Node to_free = s->head;
    s->head = s->head->next;
    free(to_free);
    s->size--;
    if (data == s->min->data) {
        to_free = s->min;
        s->min = s->min->next;
        free(to_free);
    }
    printf("popped : %d\n", data);
    return data;
}

/**
 * returns the last pushed (top most) element without poping it
 *  returns UNDERFLOW if Stack is Empty
 */
int top(Stack s) {
    if (isEmpty(s)) {
        printf("Underflow!\n");
        return UNDERFLOW;
    }
    printf("top : %d\n", s->head->data);
    return s->head->data;
}

// testing :
void test() {
    Stack s = newStack();
    int data, ch = 1, ret;
    while (ch) {
        printf("1:push  2:pop  3:top  4:size  5:isEmpty  6:min  0:Exit\n");
        printf("Enter a choice : ");
        scanf("%d", &ch);
        switch (ch) {
            case 0:
                printf("Exiting.\n");
                break;
            case 1:
                printf("Enter data to push : ");
                scanf("%d", &data);
                if (push(s, data) == ERROR)
                    printf("Error while pushing!\n");
                else
                    printf("Pushed %d onto the stack\n", data);
                break;
            case 2:
                ret = pop(s);
                if (ret == UNDERFLOW)
                    printf("Error : Stack Underflow!\n");
                else
                    printf("Popped %d from stack\n", ret);
                break;
            case 3:
                ret = top(s);
                if (ret == UNDERFLOW)
                    printf("Error : Stack Underflow!\n");
                else
                    printf("Top of stack : %d\n", ret);
                break;
            case 4:
                printf("Size of stack : %d\n", stackSize(s));
                break;
            case 5:
                if (isEmpty(s))
                    printf("Stack is empty!\n");
                else
                    printf("Stack is not empty\n");
                break;
            case 6:
                ret = min(s);
                if (ret != UNDERFLOW) printf("Minimum element : %d\n", ret);
                break;
            default:
                printf("Invalid choice\n");
        }
        printf("\n");
    }
}

int main() { test(); }
