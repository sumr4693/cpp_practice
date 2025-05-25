template <typename T>
linked_list<T>::linked_list(T root)
{
    create_node(root);
}

template <typename T>
void linked_list<T>::create_node(T value)
{
    if (head == nullptr)
    {
        head = std::make_unique<Node<T>>(value);
        tail = head.get();
    }
    else
    {
        tail->next = std::make_unique<Node<T>>(value);
        tail = tail->next.get();
    }
}

template <typename T>
void linked_list<T>::insert_value(T value)
{
    create_node(value);
}

template <typename T>
void linked_list<T>::remove_value(T target)
{
    /* This function assumes that the linked list has repeated target values and attempts to remove them all */
    
    std::cout << "Remove function invoked, searching for target: " << target << std::endl;

    // If target is the head
    if (head->data == target)
    {
        head = std::move(head->next);
    }

    // If target is the tail
    if (tail->data == target)
    {
        tail = std::move(nullptr);
    }

    Node<T>* current = head.get();

    // current is of Node<T>* type, whereas current->next is of unique_ptr<Node<T>> type
    // So, cannot move from current->next to current
    // That is why, checking for current->next's data and removing it (if matches) by moving current->next->next to current->next
    // Since both of them has unique_ptr<Node<T>> types
    // Also, what if head->data is the target?
    // That's why we have head->data that is checked above, since current->data is not checked here
    while (current && current->next)
    {
        if (current->next->data == target)
        {
            current->next = std::move(current->next->next);
        }
        else
        {
            current = current->next.get();
        }
    }

    if (current == nullptr)
    {
        std::cout << "Target not found" << std::endl;
    }
}

template <typename T>
void linked_list<T>::traverse_list()
{
    Node<T>* current = head.get();

    if (current == nullptr)
    {
        std::cout << "List is empty, can't traverse" << std::endl;
    }
    else
    {
        std::cout << "Traversing the list: " << std::endl;

        while (current)
        {
            std::cout << current->data << "->";
            current = current->next.get();
        }

        std::cout << std::endl;
    }
}

template <typename T>
void linked_list<T>::reverse_list()
{
    std::unique_ptr<Node<T>> previous = nullptr;
    std::unique_ptr<Node<T>> current = nullptr;

    if (head.get() == nullptr)
    {
        std::cout << "List is empty, can't reverse" << std::endl;
    }
    else
    {
        while (head)
        {
            current = std::move(head);
            head = std::move(current->next);
            current->next = std::move(previous);
            previous = std::move(current);
        }

        head = std::move(previous);

        std::cout << "Printing the reversed list: " << std::endl;

        traverse_list();
    }
}