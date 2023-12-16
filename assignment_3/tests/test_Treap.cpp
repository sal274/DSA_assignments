/*
test_Treap.cpp
*/

#include <iostream>

#include "Treap.h"

using std::cout;

int main()
{
    Treap<int> treap;
    for (int i = 10; i > 0; --i) treap.insert(i);
    cout << treap.size() << '\n';
    treap.print(cout);
    for (int i = 1; i <= 10; ++i) treap.remove(i);
    cout << treap.size() << '\n';
    return 0;
}