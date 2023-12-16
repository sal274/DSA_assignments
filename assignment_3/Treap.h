/*
Treap.h
*/

#ifndef TREAP_H
#define TREAP_H

#include <cstddef>
#include <utility>
#include <iostream>

#include "UniformRandom.h"

template <class Comparable>
class Treap
{
    public:

        Treap() : root{ nullptr }, sz{ 0 }
            {}

        ~Treap()
            { clear(root); }

        Treap(const Treap& source) = delete;
        Treap(Treap&& source) = delete;
        Treap& operator=(const Treap& source) = delete;
        Treap& operator=(Treap&& source) = delete;

        std::size_t size() const
            { return sz; }
        
        bool empty() const
            { return sz == 0; }

        bool contains(const Comparable& el) const
            { return contains(root, el); }

        void insert(const Comparable& el)
            { insert(root, el); }

        void insert(Comparable&& el)
            { insert(root, std::move(el)); }
    
        void remove(const Comparable& el)
            { remove(root, el); }

        void clear()
            { clear(root); }

        // For debugging
        std::ostream& print(std::ostream& out) const
            { print(root, out); return out; }

    private:

        struct Node;
        Node* root;
        std::size_t sz;
        UniformRandom rand_nums;

        void rotate_left(Node*& p);
        void rotate_right(Node*& p);
        bool contains(Node* p, const Comparable& el) const;
        void insert(Node*& p, const Comparable& el);
        void insert(Node*& p, Comparable&& el);
        void remove(Node*& p, const Comparable& el);
        void restructure(Node*& p);
        void remove_min(Node*& p, Comparable& min_val);
        void clear(Node*& p);

        // For debugging
        std::ostream& print(Node* p, std::ostream&) const;
};

template <class Comparable>
struct Treap<Comparable>::Node
{
    Comparable element;

    Node* left;
    Node* right;

    std::size_t priority;

    Node(const Comparable& el, Node* lt, Node* rt, std::size_t pr)
        : element{ el }, left{ lt }, right{ rt }, priority{ pr }
    {}

    Node(Comparable&& el, Node* lt, Node* rt, std::size_t pr)
        : element{ std::move(el) }, left{ lt }, right{ rt },
        priority{ pr }
    {}
};

template <class Comparable>
void Treap<Comparable>::clear(Node*& p)
{
    if (p)
    {
        clear(p -> left);
        clear(p -> right);
        delete p;
    }
    p = nullptr;
}

template <class Comparable>
bool Treap<Comparable>::contains(Node* p, const Comparable& el) const
{
    if (!p) return false;
    else if (el < p -> element) return contains(p -> left, el);
    else if (p -> element < el) return contains(p -> right, el);
    else return true;
}

template <class Comparable>
void Treap<Comparable>::insert(Node*& p, const Comparable& el)
{
    if (!p)
    {
        p = new Node(el, nullptr, nullptr,
            rand_nums.rand_int() % (sz > 10000 ? (sz * sz) : 10000));
        ++sz;
    }
    else if (el < p -> element) insert(p -> left, el);
    else if (p -> element < el) insert(p -> right, el);
    else ;  // Duplicate value
    restructure(p);
}

template <class Comparable>
void Treap<Comparable>::insert(Node*& p, Comparable&& el)
{
    if (!p)
    {
        p = new Node(std::move(el), nullptr, nullptr,
            rand_nums.rand_int() % (sz > 10000 ? (sz * sz) : 10000));
        ++sz;
    }
    else if (el < p -> element) insert(p -> left, el);
    else if (p -> element < el) insert(p -> right, el);
    else ;  // Duplicate value
    restructure(p);
}

template <class Comparable>
void Treap<Comparable>::remove(Node*& p, const Comparable& el)
{
    if (!p) return;
    if (el < p -> element) remove(p -> left, el);
    else if (p -> element < el) remove(p -> right, el);
    else if ((p -> left) && (p -> right)) remove_min(p -> right, p -> element);
    else
    {
        Node* old_node = p;
        p = (p -> left) ? p -> left : p -> right;
        delete old_node;
        --sz;
    }
    restructure(p);
}

template <class Comparable>
void Treap<Comparable>::restructure(Node*& p)
{
    if (!p)
        return;
    if (p -> left && p -> left -> priority > p -> priority)
        rotate_right(p);
	else if (p -> right && p -> right -> priority > p -> priority)
        rotate_left(p);
}

// Remove and store the minimum value in the tree with root p in min_val
template <class Comparable>
void Treap<Comparable>::remove_min(Node*& p, Comparable& min_val)
{
    if (!(p -> left))
    {
        Node* old_node = p;
        min_val = std::move(old_node -> element);
        p = p -> right;
        delete old_node;
        --sz;
    }
    else remove_min(p -> left, min_val);
    restructure(p);
}

template <class Comparable>
void Treap<Comparable>::rotate_left(Node*& p)
{
    if (!p) return;
    Node* temp = p -> right;
    p -> right = temp -> left;
    temp -> left = p;
    p = temp;
}

template <class Comparable>
void Treap<Comparable>::rotate_right(Node*& p)
{
    if (!p) return;
    Node* temp = p -> left;
    p -> left = temp -> right;
    temp -> right = p;
    p = temp;
}

// For debugging
// Note: Comparable must have appropriate operator<< defined
template <class Comparable>
std::ostream& Treap<Comparable>::print(Node* p, std::ostream& out) const
{
    if (sz == 0)
    {
        out << "(empty)\n";
        return out;
    }

    if (p)
    {
        print(p -> left, out);
        out << "(Value = " << p -> element << ", Priority = " << p -> priority
            << ")\n";
        print(p -> right, out);
    }
    return out;
}

#endif