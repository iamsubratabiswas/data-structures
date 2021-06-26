/*Concatenate two singly linked lists*/


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void list1(Node *head) {
    Node *cur = head;
    printf("\nList is : ");
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void insert(Node **phead, int data) {
    Node *to_insert = (Node *)malloc(sizeof(Node));
    to_insert->data = data;
    to_insert->next = NULL;
    if (*phead == NULL) {
        *phead = to_insert;
        return;
    }
    Node *cur = *phead;
    if (data <= cur->data) {
        to_insert->next = cur;
        *phead = to_insert;
        return;
    }
    while (cur->next && cur->next->data < data) {
        cur = cur->next;
    }
    to_insert->next = cur->next;
    cur->next = to_insert;
}

Node *concatlist(Node *head1, Node *head2) {
    if (!head1) return head2;
    if (!head2) return head1;
    Node *cur = head1;
    while (cur->next) cur = cur->next;
    cur->next = head2;
    return head1;
}

int main() {
    Node *head1, *head2;
    head1 = NULL;
    head2 = NULL;
    for (int i = 1; i <= 5; i++) {
        insert(&head1, i);
    }
    printf("\nList 1 : ");
    list1(head1);
    for (int i = 6; i <= 10; i++) {
        insert(&head2, i);
    }
    printf("\nList 2 : ");
    list1(head2);
    Node *concated = concatlist(head1, head2);
    printf("\nConcatenated singly linked List is : ");
    list1(concated);
    return 0;
}
