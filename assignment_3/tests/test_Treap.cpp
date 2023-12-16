/*
DSA Assignment 3

Ateeq Ur Rehman 221475
Salman Abdullah 221478

BS CS IIIC

3 December 2023
*/

/*
test_Treap.cpp

Test the public member functions of the Treap class
*/

#include "../Treap.h"

#include <iostream>

using namespace std;

int main()
{
    Treap<int> t;

    cout << "Print empty treap:\n";
    t.print(cout);
    cout << "Size: " << t.size() << '\n';

    cout << "\nInsert 4:\n";
    t.insert(4);
    t.print(cout);
    cout << "Size: " << t.size() << '\n';

    cout << "\nDelete 4:\n";
    t.remove(4);
    t.print(cout);
    cout << "Size: " << t.size() << '\n';

    cout << "\nInsert 4:\n";
    t.insert(4);
    t.print(cout);
    cout << "Size: " << t.size() << '\n';

    cout << "\nDelete 100:\n";
    t.remove(100);
    t.print(cout);
    cout << "Size: " << t.size() << '\n';

    cout << "\nInsert 4:\n";
    t.insert(4);
    t.print(cout);
    cout << "Size: " << t.size() << '\n';

    cout << "\nInsert 8:\n";
    t.insert(8);
    t.print(cout);
    cout << "Size: " << t.size() << '\n';

    cout << "\nInsert 12:\n";
    t.insert(12);
    t.print(cout);
    cout << "Size: " << t.size() << '\n';

    cout << "\nInsert 0:\n";
    t.insert(0);
    t.print(cout);
    cout << "Size: " << t.size() << '\n';

    cout << "\nDelete 8:\n";
    t.remove(8);
    t.print(cout);
    cout << "Size: " << t.size() << '\n';

    cout << "\nDelete 4:\n";
    t.remove(4);
    t.print(cout);
    cout << "Size: " << t.size() << '\n';
    return 0;
}