#include "List.h"
#include "Srack.h"
#include "Queue.h"

// УВАГА! 2 МЕЙНА, ДЛЯ РОБОТИ РОЗКОМЕНТУЙТЕ БУДЬ-ЯКИЙ 

//int main()
//{
//    List<int>* list;
//
//    // STACK
//    list = new Stack<int>();
//    cout << "stack: ";
//
//    list->push(1);
//    list->push(2);
//    list->push(3);
//    list->show();
//
//    cout << "pop: " << list->pop() << endl;  
//    cout << "new stack: ";
//    list->show();
//
//    delete list;
//    cout << endl;
//
//    // QUEUE
//    list = new Queue<int>();
//    cout << "Queue: ";
//
//    list->push(1);
//    list->push(2);
//    list->push(3);
//    list->show();
//
//    cout << "pop: " << list->pop() << endl;
//    cout << "new queue: ";
//    list->show();
//
//    delete list;
//}

// Альтернативний спосіб використання, не треба чистити в ручну, деструктори самі все зроблять
int main()
{
    Stack<double> stack1;

    cout << "stack: ";
    stack1.push(1.7);
    stack1.push(2.5);
    stack1.push(3.1);
    stack1.show();
    cout << "pop: " << stack1.pop() << endl;

    cout << "new stack: ";
    stack1.show();
    cout << endl;

    Queue<string> q1;

    cout << "queue: ";
    q1.push("One");
    q1.push("Two");
    q1.push("Three");
    q1.show();

    cout << "pop: " << q1.pop() << endl;
    cout << "new queue: ";
    q1.show();
}