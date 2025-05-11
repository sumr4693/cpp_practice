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
        head = temp_node;
    }
    else
    {
        free(temp_node);
        head->next = insertNode(head->next, value);
    }

    return head;
}

struct Node* reverse_list(struct Node* head)
{
    struct Node* temp_node = head;
    struct Node* reverse_head = NULL;
    uint8_t list_length;

    while (temp_node)
    {
        list_length++;
        temp_node = temp_node->next;
    }

    uint32_t list_array[list_length];

    temp_node = head;
    int i = -1;
    while (temp_node)
    {
        list_array[++i] = temp_node->data;
        temp_node = temp_node->next;
    }
    
    for(i = list_length-1; i >= 0; i--)
    {
        reverse_head = insertNode(reverse_head, list_array[i]);
    }

    free(temp_node);
    free(head);

    return reverse_head;
}

void print_elements(struct Node* head)
{
    if (head == NULL)
    {
        printf("End of list!\n");
        return;
    }

    printf("%d\n", head->data);
    print_elements(head->next);
}

struct Node* deleteNode(struct Node* head, int target){
  
  struct Node* temp_node = NULL;

  if (head == NULL)
  {
    printf("The list doesn't contain the target\n");
  }
  else
  {
    if (head->data == target)
    {
        printf("Deleting element: %d\n", head->data);
        temp_node = head;
        head = head->next;
        free(temp_node);
    }
    else
    {
        head->next = deleteNode(head->next, target);
    }
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
    head = reverse_list(head);

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
