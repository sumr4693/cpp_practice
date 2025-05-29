#include "singly_linked_list.hpp"
#include "singly_linked_list.h"

int main()
{
    // Cpp singly linked list
    linked_list<int> sll{1};
    sll.insert_value(2);
    sll.insert_value(3);
    sll.insert_value(4);
    sll.insert_value(5);

    sll.traverse_list();

    sll.remove_value(2);
    sll.remove_value(4);

    sll.traverse_list();

    sll.reverse_list();

    // C singly linked list
    printf("\n");
    printf("C singly linked list testing\n");
    Node* head = NULL;
    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 3);
    insert_node(&head, 4);
    insert_node(&head, 2);
    insert_node(&head, 5);

    traverse_nodes(head);

    remove_nodes(&head, 2);

    traverse_nodes(head);

    bool result = search_node(head, 3);
    if (result)
    {
        printf("Match for 3 is found\n");
    }
    else
    {
        printf("Match for 3 is not found\n");
    }

    destroy_list(&head);

    return 0;
}