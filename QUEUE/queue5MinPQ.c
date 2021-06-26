/*Write a C program which will reflect the following property of a queue : A new element will be added at one end in enqueue operation and minimum element will be returned in dequeue operation.*/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define ERROR 0
#define UNDERFLOW INT_MIN

typedef struct MinPQN* MinPQ;

struct MinPQN {
    int* q;
    int* iq;
    int size;
    int rear;
    int end;
};

MinPQ newMinPQ(int size) {
    if (size < 1) return NULL;
    MinPQ x = (MinPQ)malloc(sizeof(*x));
    if (!x) return NULL;
    x->size = size;
    x->end = -1;
    x->rear = -1;
    x->q = (int*)malloc(sizeof(int) * size);
    if (!(x->q)) return NULL;
    for (int i = 0; i < size; i++) x->q[i] = -1;
    x->iq = (int*)malloc(sizeof(int) * size);
    if (!(x->iq)) return NULL;
    for (int i = 0; i < size; i++) x->iq[i] = -1;
    return x;
}

int enqueue(MinPQ x, int data) {
    if (data == UNDERFLOW) return ERROR;
    if (x->rear + 1 == x->size) return ERROR;
    x->q[++(x->rear)] = data;
    // updating iq :
    int i = 0;
    while (i <= x->end && x->q[x->iq[i]] < data) i++;
    int j = x->end;
    while (j >= i) {
        x->iq[j + 1] = x->iq[j];
        j--;
    }
    x->iq[i] = x->rear;
    x->end++;
    return SUCCESS;
}

int dequeue(MinPQ x) {
    if (x->end == -1) return UNDERFLOW;
    int data = x->q[x->iq[0]];
    x->q[x->iq[0]] = -1;
    int j = 0;
    while (j < x->end) {
        x->iq[j] = x->iq[j + 1];
        j++;
    }
    x->iq[x->end] = -1;
    x->end--;
    return data;
}

void test() {
    printf("Enter a capacity : ");
    int capacity;
    scanf("%d", &capacity);
    MinPQ x = newMinPQ(capacity);
    if (!x) return;
    int ch = 1, data;
    while (ch) {
        printf("0: Exit  1: enqueue  2: dequeue\n");
        printf("Enter a choice : ");
        scanf("%d", &ch);
        switch(ch) {
            case 0:
                printf("Exiting\n");
                break;
            case 1:
                printf("Enter data : ");
                scanf("%d", &data);
                if (enqueue(x, data) == SUCCESS) printf("Enqueued %d \n", data);
                else printf("Error : Overflow!\n");
                break;
            case 2:
                data = dequeue(x);
                if (data == UNDERFLOW)
                    printf("Error : Underflow!\n");
                else
                    printf("Dequeued %d \n", data);
                break;
            default:
                printf("Invalid choice\n");
        }
        printf("\n");
    }
}

int main() { test(); }
