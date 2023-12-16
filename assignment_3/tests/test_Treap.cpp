/*
test_Treap.cpp
*/

#include <iostream>

#include "../Treap.h"

using std::cout;

int main()
{
    Treap<int> treap;
    for (int i = 10; i > 0; --i) treap.insert(i);
    cout << treap.size() << '\n';
    treap.print(cout);
    if (treap.contains(100)) cout << "Contains 100\n";
    else cout << "Does not contain 100\n";

    treap.remove(6);
    treap.print(cout);
    if (treap.contains(6)) cout << "Something is wrong\n";
    treap.insert(6);
    treap.print(cout);
    if (treap.contains(6)) cout << "It might be working\n";
    return 0;
}