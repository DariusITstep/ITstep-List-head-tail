#pragma once

#include <iostream>

using namespace std;

// NODE 
template<typename T>
class Node
{
private:

    T data;
    Node<T>* next;

public:

    // DEFAULT
    Node(T value) : data(value), next(nullptr) {}    

    // GETTERS 
    T& getData() { return data; }
    Node<T>* getNext() { return next; }

    // SETTERS
    void setData(T value) { data = value; }
    void setNext(Node<T>* node) { next = node; }
};

// BASE LIST 
template<typename T>
class List
{
protected:

    Node<T>* head;
    Node<T>* tail;

    void copyFrom(const List<T>& other)
    {
        Node<T>* current = other.head;
        while (current)
        {
            push(current->getData());
            current = current->getNext();
        }
    }

    void clear()
    {
        while (head)
        {
            Node<T>* temp = head;
            head = head->getNext();
            delete temp;
        }
        tail = nullptr;
    }

public:

    // DEFAULT
    List() : head(nullptr), tail(nullptr) {}    

    // COPY
    List(const List<T>& other) : head(nullptr), tail(nullptr)
    {
        copyFrom(other);
    }

    // MOVE
    List(List<T>&& other) : head(other.head), tail(other.tail)
    {
        other.head = nullptr;
        other.tail = nullptr;
    }

    // COPY =
    List<T>& operator=(const List<T>& other)
    {
        if (this != &other)
        {
            clear();
            copyFrom(other);
        }
        return *this;
    }

    // MOVE =
    List<T>& operator=(List<T>&& other)
    {
        if (this != &other)
        {
            clear();
            head = other.head;
            tail = other.tail;
            other.head = nullptr;
            other.tail = nullptr;
        }
        return *this;
    }

    // DESTRUCTOR
    virtual ~List() { clear(); }

    // VIRTUAL (Трохи забіг наперед, ці методи використовують лише override дочірніх stack і queue)
    virtual void push(T value) = 0;
    virtual T pop() = 0;

    // METHODS 
    bool isEmpty() { return head == nullptr; }

    void show() const
    {
        Node<T>* current = head;
        while (current)
        {
            cout << current->getData() << " ";
            current = current->getNext();
        }
        cout << endl;
    }
};