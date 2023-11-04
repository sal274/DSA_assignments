#include "Queue.h"

#include <iostream>
#include <string>
#include <algorithm>

using std::cout;
using std::cin;
using std::string;
using std::remove_if;

void to_queue(string expr, Queue<string>& q);

int main()
{
    cout << "Enter an expression: ";
    string expr; getline(cin, expr);
    expr.erase(remove_if(expr.begin(), expr.end(), isspace), expr.end());
    Queue<string> q;
    to_queue(expr, q);
    cout << "Expression queue: "; q.print();
    return 0;
}

void to_queue(string expr, Queue<string>& q)
{
    size_t str_sz = expr.size();
    string token;
    int token_sign = 1;
    char c;
    for (size_t i = 0; i < str_sz; ++i)
    {
        c = expr[i];
        
        if (c == '(' || c == ')' || c == '*' || c == '/' || c == '^')
        {
            token = c;
            q.enqueue(token);
        }
        else if (c == '+' || c == '-')
        {
            if (i == 0 || (!isdigit(expr[i - 1]) && expr[i - 1] != '('
                    && expr[i - 1] != ')'))
            {
                // + or - is unary
                while (!isdigit(c))
                {
                    c == '+' ? token_sign *= 1 : token_sign *= -1;
                    c = expr[++i];
                }

                token = "";  // Prepare for new token
                while (isdigit(c) || c == '.')
                {
                    token += c;
                    c = expr[++i];
                }
                if (token_sign == -1) token = '-' + token;
                q.enqueue(token);
                --i;  // For loop will increment again
            }
            else
            {
                // + or - is binary
                token = c;
                q.enqueue(token);
            }
        }
        else
        {
            // Token is a number

            token = "";  // Prepare for new token
            while (isdigit(c) || c == '.')
            {
                token += c;
                c = expr[++i];
            }
            q.enqueue(token);
            --i;  // For loop will increment again
        }
    }
}