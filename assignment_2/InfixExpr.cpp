/*
InfixExpr.cpp

Definition of class InfixExpr delcared in InfixExpr.h
*/

#include <stdexcept>
#include <algorithm>

#include "InfixExpr.h"
#include "Stack.h"

using std::string;
using std::move;
using std::invalid_argument;
using std::size_t;
using std::remove_if;

InfixExpr::InfixExpr(const string& expr)
{
    infix_expr_str = expr;
    remove_whitespace();

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
    size_t str_sz = infix_expr_str.size();
    string token;
    int token_sign = 1;
    char c;
    for (size_t i = 0; i < str_sz; ++i)
    {
        c = infix_expr_str[i];
        
        if (c == '(' || c == ')' || c == '*' || c == '/' || c == '^')
        {
            token = c;
            token_queue.enqueue(token);
        }
        else if (c == '+' || c == '-')
        {
            if (i == 0 || (!isdigit(infix_expr_str[i - 1])
                    && infix_expr_str[i - 1] != '('
                    && infix_expr_str[i - 1] != ')'))
            {
                // + or - is unary
                while (!isdigit(c))
                {
                    c == '+' ? token_sign *= 1 : token_sign *= -1;
                    c = infix_expr_str[++i];
                }

                token = "";  // Prepare for new token
                while (isdigit(c) || c == '.')
                {
                    token += c;
                    c = infix_expr_str[++i];
                }
                if (token_sign == -1) token = '-' + token;
                token_queue.enqueue(token);
                --i;  // For loop will increment again
            }
            else
            {
                // + or - is binary
                token = c;
                token_queue.enqueue(token);
            }
        }
        else
        {
            // Token is a number

            token = "";  // Prepare for new token
            while (isdigit(c) || c == '.')
            {
                token += c;
                c = infix_expr_str[++i];
            }
            token_queue.enqueue(token);
            --i;  // For loop will increment again
        }
    }
}

void InfixExpr::to_postfix()
{}

void InfixExpr::eval()
{}

void InfixExpr::remove_whitespace()
{
    infix_expr_str.erase(remove_if(infix_expr_str.begin(),
        infix_expr_str.end(), isspace), infix_expr_str.end());
}