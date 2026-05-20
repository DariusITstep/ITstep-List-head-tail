#pragma once

#include "List.h"

// QUEUE
template<typename T>
class Queue : public List<T>
{
public:

    // PUSH BACK
    void push(T value) override
    {
        Node<T>* newNode = new Node<T>(value);

        if (this->isEmpty())
        {
            this->head = this->tail = newNode;
        }
        else
        {
            this->tail->setNext(newNode);

            this->tail = newNode;
        }
    }

    // POP FRONT
    T pop() override
    {
        if (this->isEmpty())
        {
            cout << "Queue empty\n";
            return T();                 // (Костиль, в асортіменті поки немає trow, try, catch)
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