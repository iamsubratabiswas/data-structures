/* Implement Double Ended Queue with following functions using Array and Linked List
void insertFront(double)
• void insertRear(double)
• double deleteFront(void)
• double deleteRear(void)
• bool isEmpty(void)
• bool isFull(void)
• double front(void)
• double rear(void)
• void clear(void)*/

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define UNDERFLOW INT_MIN
#define SUCCESS 1
#define ERROR 0

typedef struct DequeStr* Deque;
struct DequeStr {
    double* arr;
    int capacity;
    int first;
    int last;
    int size;
};

// function prototypes
Deque newDeque(int capacity);
void insertFront(Deque x, double data);
void insertRear(Deque x, double data);
double deleteFront(Deque x);
double deleteRear(Deque x);
bool isEmpty(Deque x);
bool isFull(Deque x);
double front(Deque x);
double rear(Deque x);
void clear(Deque x);

void test() {
    printf("Enter capacity : ");
    int capacity;
    scanf("%d", &capacity);
    Deque x = newDeque(capacity);
    if (!x) {
        printf("Error! Exiting\n");
        return;
    }
    double data;
    int ch = 1;
    while (ch) {
        printf(
            "0:Exit     1:insertFront  2:insertRear  3:deleteFront  "
            "4:deleteRear\n"
            "5:isEmpty  6:isFull       7:front       8:rear         "
            "9:clear\n");
        printf("Enter a choice : ");
        scanf("%d", &ch);
        switch (ch) {
            case 0:
                printf("Exiting.\n");
                break;
            case 1:
                printf("Enter data : ");
                scanf("%lf", &data);
                insertFront(x, data);
                break;
            case 2:
                printf("Enter data : ");
                scanf("%lf", &data);
                insertRear(x, data);
                break;
            case 3:
                data = deleteFront(x);
                if (data == UNDERFLOW)
                    printf("Error : Underflow!\n");
                else
                    printf("Deleted %lf from the deque\n", data);
                break;
            case 4:
                data = deleteRear(x);
                if (data == UNDERFLOW)
                    printf("Error : Underflow!\n");
                else
                    printf("Deleted %lf from the deque\n", data);
                break;
            case 5:
                if (isEmpty(x))
                    printf("Deque is empty\n");
                else
                    printf("deque is not empty\n");
                break;
            case 6:
                if (isFull(x))
                    printf("Deque is full\n");
                else
                    printf("deque is not full\n");
                break;
            case 7:
                data = front(x);
                if (data == UNDERFLOW)
                    printf("Error : Underflow!\n");
                else
                    printf("Front : %lf\n", data);
                break;
            case 8:
                data = rear(x);
                if (data == UNDERFLOW)
                    printf("Error : Underflow!\n");
                else
                    printf("Rear : %lf\n", data);
                break;
            case 9:
                clear(x);
                break;
            default:
                printf("Invalid choice\n");
        }
        printf("\n");
    }
}

int main() { test(); }

Deque newDeque(int capacity) {
    if (capacity < 1) return NULL;
    Deque x = (Deque)malloc(sizeof(*x));
    if (!x) return NULL;
    x->arr = (double*)malloc(sizeof(double) * capacity);
    if (!(x->arr)) {
        free(x);
        return NULL;
    }
    x->capacity = capacity;
    x->first = -1;
    x->last = -1;
    x->size = 0;
    return x;
}

bool isEmpty(Deque x) { return x->size == 0; }

bool isFull(Deque x) { return x->size == x->capacity; }

void clear(Deque x) {
    x->first = -1;
    x->last = -1;
    x->size = 0;
}

void insertFront(Deque x, double data) {
    if (isEmpty(x)) {
        x->first = 0;
        x->last = 0;
        x->arr[x->first] = data;
    } else {
        if (isFull(x)) {
            printf("Error : Overflow!\n");
            return;
        }
        if (x->first == 0)
            x->first = x->capacity - 1;
        else
            x->first = x->first - 1;
        x->arr[x->first] = data;
    }
    x->size++;
}

void insertRear(Deque x, double data) {
    if (isEmpty(x)) {
        x->first = 0;
        x->last = 0;
        x->arr[x->first] = data;
    } else {
        if (isFull(x)) {
            printf("Error : Overflow!\n");
            return;
        }
        x->last = (x->last + 1) % x->capacity;
        x->arr[x->last] = data;
    }
    x->size++;
}

double deleteFront(Deque x) {
    if (isEmpty(x)) return UNDERFLOW;
    double data = x->arr[x->first];
    x->first = (x->first + 1) % x->capacity;
    x->size--;
    if (isEmpty(x)) {
        x->first = -1;
        x->last = -1;
    }
    return data;
}

double deleteRear(Deque x) {
    if (isEmpty(x)) return UNDERFLOW;
    double data = x->arr[x->last];
    if (x->last == 0)
        x->last = x->capacity - 1;
    else
        x->last = x->last - 1;
    x->size--;
    if (isEmpty(x)) {
        x->first = -1;
        x->last = -1;
    }
    return data;
}

double front(Deque x) {
    if (isEmpty(x)) return UNDERFLOW;
    return x->arr[x->first];
}

double rear(Deque x) {
    if (isEmpty(x)) return UNDERFLOW;
    return x->arr[x->last];
}