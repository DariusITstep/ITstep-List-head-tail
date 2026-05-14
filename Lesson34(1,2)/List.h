#include <iostream>
using namespace std;

template <typename T>
struct Node
{

    T value;
    Node<T>* next;
    Node(const T& value) : value(value), next(nullptr) {}

};

// LIST
template <typename T>
class List
{
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:

    // DEFAULT CONSTRUCTOR
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


    // COPY OPERATOR
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


    // MOVE CONSTRUCTOR
    List(List<T>&& other) noexcept : head(other.head), tail(other.tail), size(other.size)
    {
        other.head = nullptr;
        other.tail = nullptr;
        other.size = 0;
    }


    // MOVE OPERATOR
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

        // якщо список пустий
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

        // якщо список пустий
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
        if (head == nullptr) { return; }

        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;

        // якщо список став пустим
        if (head == nullptr) { tail = nullptr; }
    }


    // DELETE FROM TAIL
    void DeleteFromTail()
    {
        if (tail == nullptr) { return; }

        // якщо 1 елемент
        if (head == tail)
        {
            delete head;

            head = nullptr;
            tail = nullptr;
            size = 0;

            return;
        }

        Node<T>* current = head;

        // шукаємо передостанній вузол
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
        cout << "HEAD -> ";

        Node<T>* current = head;

        while (current != nullptr)
        {
            cout << current->value;

            if (current->next != nullptr)
            {
                cout << " -> ";
            }

            current = current->next;
        }

        cout << " <- TAIL" << endl;
    }

    // GET SIZE
    int GetSize() const { return size; }

    // INSERT BY POSITION
    // вставка в задану позицію
    // позиції: 0 1 2 3 ...

    void InsertAt(const T& value, int position)
    {
        if (position < 0 || position > size)
        {
            return;
        }

        // вставка в голову
        if (position == 0)
        {
            AddToHead(value);
            return;
        }

        // вставка в хвіст
        if (position == size)
        {
            AddToTail(value);
            return;
        }

        Node<T>* current = head;

        // йдемо до вузла перед позицією
        for (int i = 0; i < position - 1; i++)
        {
            current = current->next;
        }

        Node<T>* newNode = new Node<T>(value);

        newNode->next = current->next;
        current->next = newNode;

        size++;
    }

    // DELETE BY POSITION
    void DeleteAt(int position)
    {
        if (position < 0 || position >= size) { return; }

        // видалення голови
        if (position == 0)
        {
            DeleteFromHead();
            return;
        }

        // видалення хвоста
        if (position == size - 1)
        {
            DeleteFromTail();
            return;
        }

        Node<T>* current = head;

        // вузол перед тим який треба видалити
        for (int i = 0; i < position - 1; i++)
        {
            current = current->next;
        }

        Node<T>* temp = current->next;

        current->next = temp->next;

        delete temp;

        size--;
    }


    // FIND ELEMENT
    // повертає позицію
    // якщо нема -> -1

    int Find(const T& value) const
    {
        Node<T>* current = head;

        int index = 0;

        while (current != nullptr)
        {
            if (current->value == value)
            {
                return index;
            }

            current = current->next;
            index++;
        }

        return -1;
    }


    // FIND AND REPLACE
    // повертає кількість замін
    // якщо нема -> -1

    int FindAndReplace(const T& oldValue, const T& newValue)
    {
        Node<T>* current = head;

        int replaced = 0;

        while (current != nullptr)
        {
            if (current->value == oldValue)
            {
                current->value = newValue;
                replaced++;
            }

            current = current->next;
        }

        if (replaced == 0)
        {
            return -1;
        }

        return replaced;
    }


    // REVERSE LIST

    void Reverse()
    {
        if (head == nullptr || head == tail) { return; }

        Node<T>* prev = nullptr;
        Node<T>* current = head;
        Node<T>* next = nullptr;

        // старий head стане tail
        tail = head;

        while (current != nullptr)
        {
            next = current->next;

            current->next = prev;

            prev = current;
            current = next;
        }

        head = prev;
    }
};