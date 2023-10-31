/*
InfixExpr.cpp

Definition of class InfixExpr delcared in InfixExpr.h
*/

#include <stdexcept>

#include "InfixExpr.h"
#include "Stack.h"

using std::string;
using std::move;
using std::invalid_argument;
using std::size_t;

InfixExpr::InfixExpr(const string& expr) : infix_expr_str{ expr }
{
    if (!valid()) throw invalid_argument(
        "InfixExpr constructor: invalid infix expression");

    to_postfix();
    to_queue();
    eval();
}

InfixExpr::InfixExpr(string&& expr) : infix_expr_str{ move(expr) }
{
    to_postfix();
    to_queue();
    eval();
}

bool InfixExpr::valid() const
{
    Stack<char> paren_stack;
    char c;
    size_t str_sz = infix_expr_str.size();
    for (size_t i = 0; i < str_sz; ++i)
    {
        c = infix_expr_str[i];

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
            if (infix_expr_str[i - 1] == '*'
                    || infix_expr_str[i - 1] == '/'
                    || infix_expr_str[i - 1] == '^'
                    || infix_expr_str[i - 1] == '+'
                    || infix_expr_str[i - 1] == '-'
                    || infix_expr_str[i + 1] == '*'
                    || infix_expr_str[i + 1] == '/'
                    || infix_expr_str[i + 1] == '^')
                return false;
        }

        if (c == '+' || c == '-')
        {
            if (i == str_sz - 1)
                return false;
            if (i == 0 && (!isdigit(infix_expr_str[i + 1])
                    && infix_expr_str[i + 1] != '+'
                    && infix_expr_str[i + 1] != '-'))
                return false;
            if (!isdigit(infix_expr_str[i - 1])
                    && (!isdigit(infix_expr_str[i + 1]))
                    && infix_expr_str[i + 1] != '+'
                    && infix_expr_str[i + 1] != '-')
                return false;
        }

        if (c == '.')
        {
            if (i == 0 || i == str_sz - 1)
                return false;
            if (!isdigit(infix_expr_str[i - 1])
                    || !isdigit(infix_expr_str[i + 1]))
                return false;
        }
    }

    if (!paren_stack.empty())
        return false;

    return true;
}

void InfixExpr::to_queue()
{
    ;
}

void InfixExpr::to_postfix()
{}

void InfixExpr::eval()
{}