/*
DSA Assignment 2

Salman Abdullah
221478 BSCS IIIC

11 October 2023
*/

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
    string choice;
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

        cout << "Do you want to continue? (y/n): ";
        getline(cin, choice);
        if (choice == "n") break;
    }
    return 0;
}