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

        Treap();
        ~Treap();

        std::size_t size() const { return sz; }
        bool empty() const { return sz == 0; }

        bool contains(const Comparable& el) const
            { return contains(root, el); }

        void insert(const Comparable& el)
            { ++sz; return insert(root, el); }

        void insert(Comparable&& el)
            { ++sz; return insert(root, std::move(el)); }
    
        void remove(const Comparable& el)
            { --sz; return remove(root, el); }

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
        Node* find_min(Node* p) const;
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

    Node() : left{ nullptr }, right{ nullptr },
        priority{ ULONG_LONG_MAX }
    {}

    Node(const Comparable& el, Node* lt, Node* rt, std::size_t pr)
        : element{ el }, left{ lt }, right{ rt }, priority{ pr }
    {}

    Node(Comparable&& el, Node* lt, Node* rt, std::size_t pr)
        : element{ std::move(el) }, left{ lt }, right{ rt },
        priority{ pr }
    {}
};

template <class Comparable>
Treap<Comparable>::Treap() : root{ nullptr }, sz{ 0 }
{}

template <class Comparable>
Treap<Comparable>::~Treap()
{
    clear(root);
}

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
    if (!p) p = new Node(el, nullptr, nullptr,
        rand_nums.rand_int() % (sz * sz * sz));
    else if (el < p -> element) return insert(p -> left, el);
    else if (p -> element < el) return insert(p -> right, el);
    else ;  // Duplicate value
    restructure(p);
}

template <class Comparable>
void Treap<Comparable>::insert(Node*& p, Comparable&& el)
{
    if (!p) p = new Node(std::move(el), nullptr, nullptr,
        rand_nums.rand_int() % (sz * sz * sz));
    else if (el < p -> element) return insert(p -> left, el);
    else if (p -> element < el) return insert(p -> right, el);
    else ;  // Duplicate value
    restructure(p);
}

template <class Comparable>
void Treap<Comparable>::remove(Node*& p, const Comparable& el)
{
    if (!p) return;
    if (el < p -> element) remove(p -> left, el);
    else if (p -> element < el) remove(p -> right, el);
    else if ((p -> left) && (p -> right))
    {
        p -> element = find_min(p -> right) -> element;
        remove(p -> right, p -> element);
    }
    else
    {
        Node* old_node = p;
        p = (p -> left) ? p -> left : p -> right;
        delete old_node;
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

template <class Comparable>
typename Treap<Comparable>::Node* Treap<Comparable>::find_min(Node* p) const
{
    if (!p) return nullptr;
    if (!(p -> left)) return p;
    return find_min(p -> left);
}

template <class Comparable>
void Treap<Comparable>::rotate_left(Node*& p)
{
    Node* temp = p -> right;
    p -> right = temp -> left;
    temp -> left = p;
    p = temp;
}

template <class Comparable>
void Treap<Comparable>::rotate_right(Node*& p)
{
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