#include "List.h"

int main()
{
    List<int> lst;

    cout << "EMPTY: ";
    lst.Show();

    lst.AddToHead(1);
    lst.AddToHead(2);
    lst.AddToHead(3);

    cout << "ADD TO HEAD: ";
    lst.Show();

    lst.AddToTail(4);
    lst.AddToTail(5);

    cout << "ADD TO TAIL: ";
    lst.Show();

    lst.DeleteFromHead();

    cout << "DELETE FROM HEAD: ";
    lst.Show();

    lst.DeleteFromTail();

    cout << "DELETE FROM TAIL: ";
    lst.Show();

    cout << "SIZE: " << lst.GetSize() << endl;

    // COPY CONSTRUCTOR
    List<int> copyList(lst);

    cout << "COPY LIST: ";
    copyList.Show();

    // MOVE CONSTRUCTOR
    List<int> moveList(std::move(lst));

    cout << "MOVE LIST: ";
    moveList.Show();

    cout << "OLD LIST AFTER MOVE: ";
    lst.Show();

    // COPY ASSIGNMENT
    List<int> assignList;

    assignList = copyList;

    cout << "COPY ASSIGNMENT: ";
    assignList.Show();

    // MOVE ASSIGNMENT
    List<int> moveAssignList;

    moveAssignList = std::move(copyList);

    cout << "MOVE ASSIGNMENT: ";
    moveAssignList.Show();

    cout << "COPY LIST AFTER MOVE: ";
    copyList.Show();

    moveAssignList.DeleteAll();

    cout << "DELETE ALL: ";
    moveAssignList.Show();
}