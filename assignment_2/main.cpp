/*
main.cpp

Driver program for InfixExpr class declared in InfixExpr.h
*/

#include "InfixExpr.h"

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

int main()
{
    InfixExpr expr;
    string expr_str;
    while (true)
    {
        cout << "Enter an infix expression: ";
        getline(cin, expr_str);

        try
        {
            expr.assign(expr_str);
        }
        catch(std::invalid_argument)
        {
            cout << "Please enter a valid infix expression\n";
            continue;
        }

        cout << "In postfix: " << expr.postfix() << '\n';
        cout << "Result: " << expr.evaluate() << '\n';
    }
    return 0;
}