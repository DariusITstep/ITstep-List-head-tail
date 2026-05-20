#pragma once

#include "List.h"

// STACK 
template<typename T>
class Stack : public List<T>
{
public:

    // PUSH FRONT
    void push(T value) override
    {
        Node<T>* newNode = new Node<T>(value);
        newNode->setNext(this->head);
        this->head = newNode;

        if (!this->tail)
        {
            this->tail = this->head;
        }
    }

    // POP FRONT
    T pop() override
    {
        if (this->isEmpty())
        {
            cout << "Stack empty\n";
            return T();                // (Костиль, в асортіменті поки немає trow, try, catch)
        }

        Node<T>* temp = this->head;

        T value = temp->getData();

        this->head = this->head->getNext();

        if (!this->head)
        {
            this->tail = nullptr;
        }

        delete temp;

        return value;
    }
};