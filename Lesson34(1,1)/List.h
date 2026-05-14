#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:

    T value;
    Node<T>* next;
    Node(const T& value) : value(value), next(nullptr) {}

};

template <typename T>
class List
{
private:

    Node<T>* head;
    Node<T>* tail;
    size_t size;

public:

    // DEFAULT
    List() : head(nullptr), tail(nullptr), size(0) {}

    // DESTRUCTOR
    ~List() { DeleteAll(); }

    // COPY CONSTRUCTOR
    List(const List<T>& other) : head(nullptr), tail(nullptr), size(0)
    {
        Node<T>* current = other.head;

        while (current != nullptr)
        {
            AddToTail(current->value);
            current = current->next;
        }
    }

    // MOVE CONSTRUCTOR
    List(List<T>&& other) noexcept : head(other.head), tail(other.tail), size(other.size)
    {
        other.head = nullptr;
        other.tail = nullptr;
        other.size = 0;
    }

    // COPY ASSIGNMENT
    List<T>& operator=(const List<T>& other)
    {
        if (this != &other)
        {
            DeleteAll();
            Node<T>* current = other.head;
            while (current != nullptr)
            {
                AddToTail(current->value);
                current = current->next;
            }
        }

        return *this;
    }

    // MOVE ASSIGNMENT
    List<T>& operator=(List<T>&& other) noexcept
    {
        if (this != &other)
        {
            DeleteAll();

            head = other.head;
            tail = other.tail;
            size = other.size;

            other.head = nullptr;
            other.tail = nullptr;
            other.size = 0;
        }

        return *this;
    }

    // ADD TO HEAD
    void AddToHead(const T& value)
    {
        Node<T>* newNode = new Node<T>(value);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }

        size++;
    }

    // ADD TO TAIL
    void AddToTail(const T& value)
    {
        Node<T>* newNode = new Node<T>(value);

        if (tail == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        size++;
    }

    // DELETE FROM HEAD
    void DeleteFromHead()
    {
        if (head == nullptr)
        {
            return;
        }

        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;

        if (head == nullptr)
        {
            tail = nullptr;
        }
    }

    // DELETE FROM TAIL
    void DeleteFromTail()
    {
        if (tail == nullptr) { return; }

        // ONE ELEMENT
        if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            size = 0;
            return;
        }

        Node<T>* current = head;

        while (current->next != tail)
        {
            current = current->next;
        }

        delete tail;

        tail = current;
        tail->next = nullptr;

        size--;
    }

    // DELETE ALL
    void DeleteAll()
    {
        while (head != nullptr)
        {
            DeleteFromHead();
        }
    }

    // SHOW
    void Show() const
    {
        Node<T>* current = head;

        while (current != nullptr)
        {
            cout << current->value << " ";
            current = current->next;
        }

        cout << endl;
    }

    // GET SIZE
    size_t GetSize() const { return size; }

    // IS EMPTY
    bool IsEmpty() const { return head == nullptr; }
};