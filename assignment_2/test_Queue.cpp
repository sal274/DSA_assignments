#include "Queue.h"

#include <iostream>

using std::cout;

int main()
{
    Queue<int> q;
    cout << "Empty queue: "; q.print();
    
    q.enqueue(4); cout << "Enqueue 4: "; q.print();
    q.enqueue(10); cout << "Enqueue 10: "; q.print();
    q.enqueue(14); cout << "Enqueue 14: "; q.print();

    q.dequeue(); cout << "Dequeue: "; q.print();
    q.enqueue(4); cout << "Enqueue 4: "; q.print();
    cout << "Front: " << q.front() << '\n';
    cout << "Back: " << q.back() << '\n';
    q.dequeue(); cout << "Dequeue: "; q.print();
    cout << "Front: " << q.front() << '\n';
    cout << "Back: " << q.back() << '\n';
    q.dequeue(); cout << "Dequeue: "; q.print();
    cout << "Front: " << q.front() << '\n';
    cout << "Back: " << q.back() << '\n';

    cout << "Enqueue 1 - 10: ";
    for (int i = 1; i <= 10; ++i)
        q.enqueue(i);
    q.print();

    Queue<int> q1 = q;
    cout << "Queue<int> q1 = q: "; q1.print();

    Queue<int> q3;
    q3 = q;

    cout << "q3 = q: "; q3.print();

    if (q.empty()) cout << "q is empty\n";
    else cout << "q is NOT empty\n";

    cout << "q.size(): " << q.size() << '\n';
    return 0;
}