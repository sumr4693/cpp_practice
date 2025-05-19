#pragma once

#include <iostream>
#include <memory>

template <typename T>
class Node {
public:
    T data;
    std::unique_ptr<Node<T>> next;

    Node(T val) : data{val}, next{nullptr}
    {}
};

template <typename T>
class linked_list
{
public:
    linked_list() = default;
    linked_list(T root);

    virtual void insert_value(T value);
    virtual void remove_value(T value);
    virtual void traverse_list();
    virtual void reverse_list();

private:
    std::unique_ptr<Node<T>> head;
    Node<T>* tail;

    void create_node(T value);
};

#include "singly_linked_list.tcc"