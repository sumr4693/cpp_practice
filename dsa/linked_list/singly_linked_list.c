#include "singly_linked_list.h"

/**  Macro definitions **/

/** Global variables **/

/** Private function declarations **/
static Node* create_node(const int value);

/** Public function definitions **/

/**
 * @brief Inserts a new node with the given value at the end of the list.
 * @param head Pointer to the head pointer of the list (Node**).
 *             May be updated if the list is initially empty.
 * @param value The value to insert.
 * @note Modifies the list by adding a new node at the end.
 */
void insert_node(Node** head, const int value)
{
    Node* new_node = create_node(value);

    /* Handle allocation failure */
    if (new_node == NULL)
    {
        return;
    }

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        Node* current = *head;

        /* Check both current and current->next so that we can append the new node in the next node that is NULL */
        while (current != NULL && current->next != NULL)
        {
            current = current->next;
        }

        current->next = new_node;
    }
}

/**
 * @brief Searches for a node with the specified value in the list.
 * @param head Pointer to the head of the list (const Node*).
 * @param search_value The value to search for.
 * @return true if the value is found, false otherwise.
 */
bool search_node(const Node* head, const int search_value)
{
    bool search_result = false;

    if (head == NULL)
    {
        printf("Head is empty, can't search\n");
    }
    else
    {
        const Node* current = head;

        while (current != NULL)
        {
            if (current->data == search_value)
            {
                search_result = true;
                break;
            }

            current = current->next;
        }

        if (search_result == false)
        {
            printf("The search value is not present in the list\n");
        }
    }

    return search_result;
}

/**
 * @brief Gets the length of the list.
 * @param head Pointer to the head of the list (const Node*).
 * @return The length of the list.
 */
int get_length(const Node* head)
{
    int list_length = 0;

    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        const Node* current = head;

        while (current != NULL)
        {
            list_length++;
            current = current->next;
        }
    }

    return list_length;
}

/**
 * @brief Traverses the list and prints the values of each node.
 * @param head Pointer to the head of the list (const Node*).
 */
void traverse_nodes(const Node* head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        const Node* current = head;

        printf("Traversing the list: \n");
        while (current != NULL)
        {
            printf("%d->", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

/**
 * @brief Removes all nodes with the specified target value from the list.
 * @param head Pointer to the head pointer of the list (Node**).
 * @param target The value to remove from the list.
 */
void remove_nodes(Node** head, const int target)
{
    if (*head == NULL)
    {
        printf("Nothing to remove, the list is empty\n");
    }
    else
    {
        /* Check for consecutive targets at the head */
        while (*head != NULL && (*head)->data == target)
        {
            Node* temp = *head;

            /* Note: 
            *  With pointer-to-pointer (Node**), the head pointer's address is modified,
            *  allowing the function to update the head pointer to point to the next node.
            *  If Node* head was passed instead of Node** head,
            *  the function would not be able to modify the head pointer,
            *  but only the node objects (->data and ->next) could be modified.
            */
            *head = (*head)->next;
            free(temp); 
        }

        Node* current = *head;
        while (current != NULL && current->next != NULL)
        {
            /* Check for consecutive targets */
            if (current->next->data == target)
            {
                Node* temp = current->next;
                current->next = current->next->next;
                free(temp);
            }
            else /* Point to next node only if couldn't find the target */
            {
                current = current->next;
            }
        }
    }
}

/**
 * @brief Destroys the list by freeing all nodes and setting the head to NULL.
 * @param head Pointer to the head pointer of the list (Node**).
 */
void destroy_list(Node** head)
{
    /* Note: 
    *  If Node* head was passed instead of Node** head,
    *  the function would have still freed the nodes, but
    *  would not be able to set head to NULL after freeing the nodes.  
    */
    if (*head == NULL)
    {
        printf("The list is already empty\n");
    }
    else
    {
        Node* current = *head;

        while (current != NULL)
        {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }

    *head = NULL;
}

/** Private function definitions **/

/**
 * @brief Creates a new node with the specified value.
 * @param value The value to store in the new node.
 * @return Pointer to the newly created node, or NULL if allocation fails.
 */
static Node* create_node(const int value)
{
    Node* new_node = malloc(sizeof(Node));

    /* Handle allocation failure */
    if (new_node == NULL)
    {
        printf("Error: Cannot allocate memory for a new node\n");
        return NULL;
    }

    new_node->data = value;
    new_node->next = NULL;

    return new_node;
}