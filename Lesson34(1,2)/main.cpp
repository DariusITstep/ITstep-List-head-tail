#include "List.h"

int main()
{
    List<int> list;

    cout << "===== EMPTY LIST =====" << endl;
    list.Show();

    // ADD TO HEAD
    cout << "\n===== ADD TO HEAD =====" << endl;

    list.AddToHead(1);
    list.AddToHead(2);
    list.AddToHead(3);

    list.Show();

    // ADD TO TAIL
    cout << "\n===== ADD TO TAIL =====" << endl;

    list.AddToTail(4);
    list.AddToTail(5);
    list.Show();

    // DELETE FROM HEAD
    cout << "\n===== DELETE FROM HEAD =====" << endl;
    list.DeleteFromHead();
    list.Show();

    // DELETE FROM TAIL
    cout << "\n===== DELETE FROM TAIL =====" << endl;
    list.DeleteFromTail();
    list.Show();

    // INSERT AT
    cout << "\n===== INSERT AT =====" << endl;
    cout << "Insert 777 at position 1" << endl;
    list.InsertAt(777, 1);
    list.Show();

    // DELETE AT
    cout << "\n===== DELETE AT =====" << endl;
    cout << "Delete element at position 2" << endl;
    list.DeleteAt(2);
    list.Show();

    // FIND
    cout << "\n===== FIND =====" << endl;
    cout << "Find 777 -> ";
    cout << list.Find(777) << endl;
    cout << "Find 999 -> ";
    cout << list.Find(999) << endl;

    // FIND AND REPLACE
    cout << "\n===== FIND AND REPLACE =====" << endl;
    list.AddToTail(777);
    list.AddToTail(777);
    list.Show();

    int replaced = list.FindAndReplace(777, 111);
    cout << "Replaced count: " << replaced  << endl;

    list.Show();

    // REVERSE
    cout << "\n===== REVERSE =====" << endl;
    list.Reverse();
    list.Show();

    // SIZE
    cout << "\n===== SIZE =====" << endl;
    cout << "Size: " << list.GetSize() << endl;

    // DELETE ALL
    cout << "\n===== DELETE ALL =====" << endl;
    list.DeleteAll();
    list.Show();

    cout << "Size: " << list.GetSize() << endl;

    // COPY CONSTRUCTOR
    cout << "\n===== COPY CONSTRUCTOR =====" << endl;
    List<int> a;

    a.AddToTail(1);
    a.AddToTail(2);
    a.AddToTail(3);

    List<int> b = a;

    cout << "List A: ";
    a.Show();

    cout << "List B: ";
    b.Show();

    // MOVE CONSTRUCTOR
    cout << "\n===== MOVE CONSTRUCTOR =====" << endl;
    List<int> c = std::move(a);

    cout << "List C: ";
    c.Show();

    cout << "List A after move: ";
    a.Show();

    return 0;
}