/*Concatenate two circular linked lists*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// prints the list :
void list1(Node *head) {
    Node *cur = head;
    printf("List : ");
    if (cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    while (cur != head) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}
int getLength(Node *head) {
    Node *cur = head;
    if (!head) return 0;
    int length = 1;
    cur = cur->next;
    while (cur != head) {
        length++;
        cur = cur->next;
    }
    return length;
}

int insert(Node **phead, int data, int index) {
    if (index < 0) {
        printf("Error : negative index not allowed!\n");
        return 0;
    }

    if (index > getLength(*phead)) {
        printf("\nError : index %d is out of size %d!\n", index,
                   getLength(*phead));
            return 0;
    }

    Node *to_insert = (Node *)malloc(sizeof(Node));
    to_insert->data = data;
    to_insert->next = NULL;
    if (to_insert == NULL) {
        printf("\nunable to allocate memory.\n");
        return 0;
    }

    if (*phead == NULL) {
        if (index == 0) {
            *phead = to_insert;
            to_insert->next = to_insert;
            return 1;
        } else {
            printf(
                "Error : List is empty, can perform insertion at 0 but not at %d!\n",index);
            return 0;
        }
    }



    int flag = 0;
    if (index == 0){
        index = getLength(*phead);
        flag = 1;
    }

    int i = 0;
    Node *cur = *phead;
    while (i < index - 1) {
        if (cur->next == *phead) {
            printf("\nError : index %d is out of size %d!\n",
                   index, getLength(*phead));
            return 0;
        }
        cur = cur->next;
        i++;
    }
    to_insert->next = cur->next;
    cur->next = to_insert;
    if (flag) *phead = to_insert;
    return 1;
}

Node *concatlist(Node *head1, Node *head2) {
    if (!head1) return head2;
    if (!head2) return head1;
    Node *cur = head1;
    while (cur->next != head1) cur = cur->next;
    cur->next = head2;
    cur = head2;
    while (cur->next != head2) cur = cur->next;
    cur->next = head1;
    return head1;
}

int main() {
    Node *head1, *head2;
    head1 = NULL;
    head2 = NULL;
    for (int i = 0; i <= 5; i++) {
        insert(&head1, i, i);
    }
    printf("\nList 1 : ");
    list1(head1);
    for (int i = 0; i <= 4; i++) {
        insert(&head2, i+6, i);
    }
    printf("\nList 2 : ");
    list1(head2);
    Node *concated = concatlist(head1, head2);
    printf("\nConcatenated circular linked List : ");
    list1(concated);
    return 0;
}