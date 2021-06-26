#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define UNDERFLOW INT_MIN
#define SUCCESS 1
#define ERROR 0

typedef struct ListNode* Link;
struct ListNode {
    double data;
    Link next, prev;
};

typedef struct DequeStr* Deque;
struct DequeStr {
    Link first;
    Link last;
    int size;
};

// function prototypes
Deque newDeque();
void insertFront(Deque x, double data);
void insertRear(Deque x, double data);
double deleteFront(Deque x);
double deleteRear(Deque x);
bool isEmpty(Deque x);
// bool isFull(Deque x);
double front(Deque x);
double rear(Deque x);
void clear(Deque x);
void clearList(Link x);

void test() {
    Deque x = newDeque();
    if (!x) {
        printf("Error! Exiting\n");
        return;
    }
    double data;
    int ch = 1;
    while (ch) {
        printf(
            "0:Exit        1:insertFront  2:insertRear  3:deleteFront\n"
            "4:deleteRear  5:isEmpty      6:front       7:rear         "
            "8:clear\n");
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
                data = front(x);
                if (data == UNDERFLOW)
                    printf("Error : Underflow!\n");
                else
                    printf("Front : %lf\n", data);
                break;
            case 7:
                data = rear(x);
                if (data == UNDERFLOW)
                    printf("Error : Underflow!\n");
                else
                    printf("Rear : %lf\n", data);
                break;
            case 8:
                clear(x);
                break;
            default:
                printf("Invalid choice\n");
        }
        printf("\n");
    }
}

int main() { test(); }

Deque newDeque() {
    Deque x = (Deque)malloc(sizeof(*x));
    if (!x) return NULL;
    x->first = NULL;
    x->last = NULL;
    x->size = 0;
    return x;
}

bool isEmpty(Deque x) { return x->size == 0; }

void clear(Deque x) {
    clearList(x->first);
    x->first = NULL;
    x->last = NULL;
    x->size = 0;
}

void clearList(Link x) {
    if (!x) return;
    clearList(x->next);
    free(x);
}

void insertFront(Deque x, double data) {
    if (isEmpty(x)) {
        x->first = (Link)malloc(sizeof(*(x->first)));
        x->first->data = data;
        x->first->prev = NULL;
        x->first->next = NULL;
        x->last = x->first;
    } else {
        Link newNode = (Link)malloc(sizeof(*newNode));
        newNode->data = data;
        newNode->next = x->first;
        newNode->prev = NULL;
        x->first->prev = newNode;
        x->first = newNode;
    }
    x->size++;
}

void insertRear(Deque x, double data) {
    if (isEmpty(x)) {
        x->first = (Link)malloc(sizeof(*(x->first)));
        x->first->data = data;
        x->first->prev = NULL;
        x->first->next = NULL;
        x->last = x->first;
    } else {
        Link newNode = (Link)malloc(sizeof(*newNode));
        newNode->data = data;
        newNode->prev = x->last;
        newNode->next = NULL;
        x->last->next = newNode;
        x->last = newNode;
    }
    x->size++;
}

double deleteFront(Deque x) {
    if (isEmpty(x)) return UNDERFLOW;
    double data = x->first->data;
    Link toFree = x->first;
    x->first = x->first->next;
    x->size--;
    if (isEmpty(x)) {
        x->first = NULL;
        x->last = NULL;
    } else {
        x->first->prev = NULL;
    }
    free(toFree);
    return data;
}

double deleteRear(Deque x) {
    if (isEmpty(x)) return UNDERFLOW;
    double data = x->last->data;
    Link toFree = x->last;
    x->last = x->last->prev;
    x->size--;
    if (isEmpty(x)) {
        x->first = NULL;
        x->last = NULL;
    } else {
        x->last->next = NULL;
    }
    free(toFree);
    return data;
}

double front(Deque x) {
    if (isEmpty(x)) return UNDERFLOW;
    return x->first->data;
}

double rear(Deque x) {
    if (isEmpty(x)) return UNDERFLOW;
    return x->last->data;
}