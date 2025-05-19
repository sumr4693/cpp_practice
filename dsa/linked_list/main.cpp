#include "singly_linked_list.hpp"

int main()
{
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

    return 0;
}