#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert_node(Node** head, const int value);
bool search_node(const Node* head, const int search_value);
int get_length(const Node* head);
void traverse_nodes(const Node* head);
void remove_nodes(Node** head, const int target);
void destroy_list(Node** head);

#ifdef __cplusplus
}
#endif

#endif // SINGLY_LINKED_LIST_H