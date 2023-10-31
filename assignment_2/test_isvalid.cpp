#include <iostream>
#include <string>

#include "Stack.h"

using std::cout;
using std::cin;
using std::string;

bool valid(const std::string& expr);

int main()
{
    string expr;
    cout << "Enter an expression: ";
    cin >> expr;

    if (valid(expr)) cout << "Expression is valid\n";
    else cout << "Expression is NOT valid\n";

    return 0;
}

bool valid(const std::string& expr)
{
    Stack<char> paren_stack;
    char c;
    size_t str_sz = expr.size();
    for (size_t i = 0; i < str_sz; ++i)
    {
        c = expr[i];

        if (!isdigit(c) && c != '+' && c != '-' && c != '*' && c != '/'
                && c != '^' && c != '(' && c != ')' && c != '.')
            return false;

        if (c == '(')
            paren_stack.push(c);
        if (c == ')')
        {
            if (paren_stack.empty()) return false;
            if (paren_stack.top() != '(') return false;
            paren_stack.pop();
        }

        if (c == '*' || c == '/' || c == '^')
        {
            if (i == 0 || i == str_sz - 1)
                return false;
            if (expr[i - 1] == '*'
                    || expr[i - 1] == '/'
                    || expr[i - 1] == '^'
                    || expr[i - 1] == '+'
                    || expr[i - 1] == '-'
                    || expr[i + 1] == '*'
                    || expr[i + 1] == '/'
                    || expr[i + 1] == '^')
                return false;
        }

        if (c == '+' || c == '-')
        {
            if (i == str_sz - 1)
                return false;
            if (i == 0 && (!isdigit(expr[i + 1])
                    && expr[i + 1] != '+'
                    && expr[i + 1] != '-'))
                return false;
            if (!isdigit(expr[i - 1])
                    && (!isdigit(expr[i + 1]))
                    && expr[i + 1] != '+'
                    && expr[i + 1] != '-')
                return false;
        }

        if (c == '.')
        {
            if (i == 0 || i == str_sz - 1)
                return false;
            if (!isdigit(expr[i - 1]) || !isdigit(expr[i + 1]))
                return false;
        }
    }

    if (!paren_stack.empty())
        return false;

    return true;
}