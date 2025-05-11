#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* insertNode(struct Node* head, int value)
{
    struct Node* temp_node = (struct Node*) malloc(sizeof(struct Node));

    temp_node->data = value;
    temp_node->next = NULL;

    if (head == NULL)
    {
        return temp_node;
    }

    struct Node* current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = temp_node;

    return head;
}

struct Node* reverseList(struct Node* head)
{
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL)
    {
        next = current->next;  // Store next node
        current->next = prev;  // Reverse the link
        prev = current;        // Move prev to current
        current = next;        // Move current to next
    }

    return prev;
}

void print_elements(struct Node* head)
{
    if (head == NULL)
    {
        printf("Empty list..\n");
        return;
    }

    struct Node* current = head;
    while (current)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

struct Node* deleteNode(struct Node* head, int target)
{
    struct Node* temp_node = NULL;

    if (head->data == target)
    {
        temp_node = head;
        head = head->next;
        free(temp_node);
        return head;
    }

    struct Node* current = head;
    while (current->next != NULL && current->next->data != target)
    {
        current = current->next;
    }

    if (current->next == NULL)
    {
        printf("The list doesn't contain the target.\n");
    }
    else
    {
        temp_node = current->next;
        current->next = current->next->next;
        free(temp_node);
    }

    return head;
}

int main()
{
    struct Node* head = NULL;

    head = insertNode(head, 1);
    head = insertNode(head, 4);
    head = insertNode(head, 7);
    head = insertNode(head, 10);
    head = insertNode(head, 11);

    printf("Printing the elements of linked list:\n");
    print_elements(head);

    printf("Reversing the list...\n");
    head = reverseList(head);

    printf("Printing the elements of reversed linked list:\n");
    print_elements(head);

    head = deleteNode(head, 7);

    printf("Printing the elements after deletion:\n");
    print_elements(head);

    head = deleteNode(head, 11);

    printf("Printing the elements after deletion:\n");
    print_elements(head);

    head = insertNode(head, 50);

    head = deleteNode(head, 1);

    printf("Printing the elements after deletion:\n");
    print_elements(head);

    return 0;
}
