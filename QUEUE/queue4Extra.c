/* Implement a queue using stack using C Program.*/

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

// Stack functions : 
struct LinkedList_node {
    int data;
    Node next;
};

struct Stack_node {
    Node head;
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

typedef struct QueueStr* Queue;

struct QueueStr {
    Stack s;
    Stack aux;
};

// Queue functions
Queue newQueue();
int enqueue(Queue x, int data);
int dequeue(Queue x);
int rear(Queue x);
int front(Queue x);
int isQueueEmpty(Queue x);
int size(Queue x);

Queue newQueue() {
    Queue x = (Queue)malloc(sizeof(*x));
    if (!x) return NULL;
    x->s = newStack();
    if (!x->s) {
        free(x);
        return NULL;
    }
    x->aux= newStack();
    if (!x->aux) {
        free(x->s);
        free(x);
        return NULL;
    }
    return x;
}

int enqueue(Queue x, int data) {
    return push(x->s, data);
}

int dequeue(Queue x) {
    while (stackSize(x->s) > 1) push(x->aux, pop(x->s));
    int data = pop(x->s);
    while (!isEmpty(x->aux)) push(x->s, pop(x->aux));
    return data;
}

int rear(Queue x) {
    return top(x->s);
}

int front(Queue x) {
    while (!isEmpty(x->s)) push(x->aux, pop(x->s));
    int data = top(x->aux);
    while (!isEmpty(x->aux)) push(x->s, pop(x->aux));
    return data;
}

int isQueueEmpty(Queue x) {
    return (x->s->size == 0);
}

int size(Queue x) {
    return stackSize(x->s);
}

void test() {
    Queue x = newQueue();
    if (!x) {
        printf("Error occured!\n");
        return;
    }
    int ch = 1;
    int data;
    while (ch) {
        printf("0:Exit  1:Enqueue  2:Dequeue  3:front  4:rear  5:isEmpty  6:size\n");
        printf("Enter a choice : ");
        scanf("%d", &ch);
        switch(ch) {
            case 0 :
                printf("Exiting!\n");
                break;
            case 1 :
                printf("Enter a data : ");
                scanf("%d", &data);
                if (enqueue(x, data) == SUCCESS)
                    printf("Enqueued %d\n", data);
                else 
                    printf("Error in enqueue!\n"); 
                break;
            case 2 :
                data = dequeue(x);
                if (data == UNDERFLOW) 
                    printf("Error : Underflow!\n");
                else 
                    printf("Dequeued %d\n", data);
                break;
            case 3 :
                data = front(x);
                if (data == UNDERFLOW) 
                    printf("Error : Queue is empty!\n");
                else 
                    printf("Front : %d\n", data);
                break;
            case 4 :
                data = rear(x);
                if (data == UNDERFLOW) 
                    printf("Error : Queue is empty!\n");
                else 
                    printf("Rear : %d\n", data);
                break;
            case 5 :
                if (isQueueEmpty(x))
                    printf("Queue is empty\n");
                else
                    printf("Queue is not empty\n");
                break;
            case 6 :
                printf("Size : %d\n", size(x));
                break;
            default :
                printf("Invalid choice!\n");
        }
        printf("\n");
    }
}

int main() {
    test();
    return 0;
}


// returns a new Stack
Stack newStack() {
    Stack s = (Stack)malloc(sizeof *s);
    s->head = NULL;
    s->size = 0;
    return s;
}

// returns the size of the stack
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
    return SUCCESS;
}

/**
 * pops the last pushed (top most) element and returns the value
 *  returns UNDERFLOW if Stack is empty 
 */
int pop(Stack s) {
    if (isEmpty(s)) {
        return UNDERFLOW;
    }
    int data = s->head->data;
    Node to_free = s->head;
    s->head = s->head->next;
    free(to_free);
    s->size--;
    return data;
}

/**
 * returns the last pushed (top most) element without poping it 
 *  returns UNDERFLOW if Stack is Empty
 */
int top(Stack s) {
    if (isEmpty(s)) {
        return UNDERFLOW;
    }
    return s->head->data;
}