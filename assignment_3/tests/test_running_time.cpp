/*
DSA Assignment 3

Ateeq Ur Rehman 221475
Salman Abdullah 221478

BS CS IIIC

3 December 2023
*/

/*
test_running_time.cpp

Test whether Treap operations consistently provide logarithmic
time performance, and compare these times with the STL set
*/

#include "../Treap.h"
#include "../UniformRandom.h"

#include <set>
#include <cmath>
#include <chrono>
#include <iostream>
#include <cstddef>

using namespace std;

int main()
{
    Treap<int> t1, t2, t3, t4;
    set<int> s1, s2, s3, s4;
    size_t n = 15000;
    cout << "Initializing Treap objects t1, t2, t3, and t4 with n = "
        << n << '\n';
    for (size_t i = 0; i < n; ++i)
    {
        t1.insert(i);
        t2.insert(i);
        t3.insert(i);
        t4.insert(i);
    }

    cout << "Initializing set objects s1, s2, s3, and s4 with n = "
        << n << '\n';

    for (size_t i = 0; i < n; ++i)
    {
        s1.insert(i);
        s2.insert(i);
        s3.insert(i);
        s4.insert(i);
    }
    cout << "--------------------------------------------------------------\n";

    // Test Treaps::contains() with four different treaps

    cout << "Running times for search operation with Treap\n";
    cout << "--------------------------------------------------------------\n";

    int ntests = 10000;
    int test_num;
    bool temp;
    UniformRandom rand_nums;

    // Test t1
    auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < ntests; ++i)
    {
        test_num = rand_nums.rand_int() % n + 1;
        temp = t1.contains(test_num);
    }

    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;

    cout << "Average time to run t1.contains() with " << ntests << " tests: "
        << std::chrono::duration <double, std::milli> (diff).count() / ntests
        << " ms\n";

    // Test t2
    start = std::chrono::steady_clock::now();

    for (int i = 0; i < ntests; ++i)
    {
        test_num = rand_nums.rand_int() % n + 1;
        temp = t2.contains(test_num);
    }

    end = std::chrono::steady_clock::now();
    diff = end - start;

    cout << "Average time to run t2.contains() with " << ntests << " tests: "
        << std::chrono::duration <double, std::milli> (diff).count() / ntests
        << " ms\n";

    // Test t3
    start = std::chrono::steady_clock::now();

    for (int i = 0; i < ntests; ++i)
    {
        test_num = rand_nums.rand_int() % n + 1;
        temp = t3.contains(test_num);
    }

    end = std::chrono::steady_clock::now();
    diff = end - start;

    cout << "Average time to run t3.contains() with " << ntests << " tests: "
        << std::chrono::duration <double, std::milli> (diff).count() / ntests
        << " ms\n";

    // Test t4
    start = std::chrono::steady_clock::now();

    for (int i = 0; i < ntests; ++i)
    {
        test_num = rand_nums.rand_int() % n + 1;
        temp = t4.contains(test_num);
    }

    end = std::chrono::steady_clock::now();
    diff = end - start;

    cout << "Average time to run t4.contains() with " << ntests << " tests: "
        << std::chrono::duration <double, std::milli> (diff).count() / ntests
        << " ms\n";

    cout << "--------------------------------------------------------------\n";

     // Test set::find() with four different sets

    cout << "Running times for search operation with STL set\n";
    cout << "--------------------------------------------------------------\n";

    // Test s1
    start = std::chrono::steady_clock::now();

    for (int i = 0; i < ntests; ++i)
    {
        test_num = rand_nums.rand_int() % n + 1;
        auto temp = s1.find(test_num);
    }

    end = std::chrono::steady_clock::now();
    diff = end - start;

    cout << "Average time to run s1.find() with " << ntests << " tests: "
        << std::chrono::duration <double, std::milli> (diff).count() / ntests
        << " ms\n";

    // Test s2
    start = std::chrono::steady_clock::now();

    for (int i = 0; i < ntests; ++i)
    {
        test_num = rand_nums.rand_int() % n + 1;
        auto temp = s2.find(test_num);
    }

    end = std::chrono::steady_clock::now();
    diff = end - start;

    cout << "Average time to run s2.find() with " << ntests << " tests: "
        << std::chrono::duration <double, std::milli> (diff).count() / ntests
        << " ms\n";

    // Test s3
    start = std::chrono::steady_clock::now();

    for (int i = 0; i < ntests; ++i)
    {
        test_num = rand_nums.rand_int() % n + 1;
        auto temp = s3.find(test_num);
    }

    end = std::chrono::steady_clock::now();
    diff = end - start;

    cout << "Average time to run s3.find() with " << ntests << " tests: "
        << std::chrono::duration <double, std::milli> (diff).count() / ntests
        << " ms\n";

    // Test s4
    start = std::chrono::steady_clock::now();

    for (int i = 0; i < ntests; ++i)
    {
        test_num = rand_nums.rand_int() % n + 1;
        auto temp = s4.find(test_num);
    }

    end = std::chrono::steady_clock::now();
    diff = end - start;

    cout << "Average time to run s4.find() with " << ntests << " tests: "
        << std::chrono::duration <double, std::milli> (diff).count() / ntests
        << " ms\n";

    cout << "--------------------------------------------------------------\n";

    // Test Treaps::remove() with four different treaps

    cout << "Running times for deletion operation with Treap\n";
    cout << "--------------------------------------------------------------\n";

    // Test t1
    start = std::chrono::steady_clock::now();

    for (int i = 0; i < ntests; ++i) t1.remove(i);

    end = std::chrono::steady_clock::now();
    diff = end - start;

    cout << "Average time to run t1.remove() with " << ntests << " tests: "
        << std::chrono::duration <double, std::milli> (diff).count() / ntests
        << " ms\n";

    // Test t2
    start = std::chrono::steady_clock::now();

    for (int i = 0; i < ntests; ++i) t2.remove(i);

    end = std::chrono::steady_clock::now();
    diff = end - start;

    cout << "Average time to run t2.remove() with " << ntests << " tests: "
        << std::chrono::duration <double, std::milli> (diff).count() / ntests
        << " ms\n";

    // Test t3
    start = std::chrono::steady_clock::now();

    for (int i = 0; i < ntests; ++i) t3.remove(i);

    end = std::chrono::steady_clock::now();
    diff = end - start;

    cout << "Average time to run t3.remove() with " << ntests << " tests: "
        << std::chrono::duration <double, std::milli> (diff).count() / ntests
        << " ms\n";

    // Test t4
    start = std::chrono::steady_clock::now();

    for (int i = 0; i < ntests; ++i) t4.remove(i);

    end = std::chrono::steady_clock::now();
    diff = end - start;

    cout << "Average time to run t4.remove() with " << ntests << " tests: "
        << std::chrono::duration <double, std::milli> (diff).count() / ntests
        << " ms\n";

    cout << "--------------------------------------------------------------\n";

     // Test set::find() with four different sets

    cout << "Running times for deletion operation with STL set\n";
    cout << "--------------------------------------------------------------\n";

    // Test s1
    start = std::chrono::steady_clock::now();

    for (int i = 0; i < ntests; ++i) auto temp = s1.erase(i);

    end = std::chrono::steady_clock::now();
    diff = end - start;

    cout << "Average time to run s1.erase() with " << ntests << " tests: "
        << std::chrono::duration <double, std::milli> (diff).count() / ntests
        << " ms\n";

    // Test s2
    start = std::chrono::steady_clock::now();

    for (int i = 0; i < ntests; ++i) auto temp = s2.erase(i);

    end = std::chrono::steady_clock::now();
    diff = end - start;

    cout << "Average time to run s2.erase() with " << ntests << " tests: "
        << std::chrono::duration <double, std::milli> (diff).count() / ntests
        << " ms\n";

    // Test s3
    start = std::chrono::steady_clock::now();

    for (int i = 0; i < ntests; ++i) auto temp = s3.erase(i);

    end = std::chrono::steady_clock::now();
    diff = end - start;

    cout << "Average time to run s3.erase() with " << ntests << " tests: "
        << std::chrono::duration <double, std::milli> (diff).count() / ntests
        << " ms\n";

    // Test s4
    start = std::chrono::steady_clock::now();

    for (int i = 0; i < ntests; ++i) auto temp = s4.erase(i);

    end = std::chrono::steady_clock::now();
    diff = end - start;

    cout << "Average time to run s4.erase() with " << ntests << " tests: "
        << std::chrono::duration <double, std::milli> (diff).count() / ntests
        << " ms\n";

    cout << "--------------------------------------------------------------\n";

    return 0;
}