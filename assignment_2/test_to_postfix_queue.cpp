#include "Queue.h"
#include "Stack.h"

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

void to_infix_queue(const string& expr, Queue<string>& q);
void to_postfix_queue(Queue<string>& infix_q, Queue<string>& postfix_q);

int main()
{
    Queue<string> infix_q;
    Queue<string> postfix_q;
    cout << "Enter an expression: ";
    string expr; getline(cin, expr);
    expr.erase(remove_if(expr.begin(), expr.end(), isspace), expr.end());
    to_infix_queue(expr, infix_q);
    to_postfix_queue(infix_q, postfix_q);
    cout << "Infix Expression Queue: "; infix_q.print();
    cout << "Postfix Expression Queue: "; postfix_q.print();
    return 0;
}

void to_infix_queue(const string& expr, Queue<string>& q)
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
            if (i == 0 || (!isdigit(expr[i - 1])
                    && expr[i - 1] != '('
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

void to_postfix_queue(Queue<string>& infix_q, Queue<string>& postfix_q)
{
    Stack<string> op_stack;
    string top_op;
    Queue<std::string> infix = infix_q;
    string token;
    while (!infix.empty())
    {
        token = infix.front();

        if (token.size() > 1 || isdigit(token[0]))
        {
            // Token is a number
            postfix_q.enqueue(token);
        }
        else
        {
            if (token == "+" || token == "-")
            {
                if (op_stack.empty())
                    op_stack.push(token);
                else
                {
                    top_op = op_stack.top();

                    if (top_op == "(")
                        op_stack.push(token);
                    else
                    {
                        while (top_op != "(" && op_stack.size() > 0)
                        {
                            postfix_q.enqueue(top_op);
                            op_stack.pop();
                            try
                            {
                                top_op = op_stack.top();   
                            }
                            catch(std::out_of_range)
                            {
                                break;
                            }
                        }
                        op_stack.push(token);
                    }
                }
            }
            else if (token == "*" || token == "/")
            {
                if (op_stack.empty())
                    op_stack.push(token);
                else
                {
                    top_op = op_stack.top();

                    if (top_op == "(")
                        op_stack.push(token);
                    else
                    {
                        if (top_op == "+" || top_op == "-")
                            op_stack.push(token);
                        else if (top_op == "*" || top_op == "/"
                                || top_op == "^")
                        {
                            while (top_op != "(" && top_op != "+"
                                    && top_op != "-" && op_stack.size() > 0)
                            {
                                postfix_q.enqueue(top_op);
                                op_stack.pop();
                                try
                                {
                                    top_op = op_stack.top();   
                                }
                                catch(std::out_of_range)
                                {
                                    break;
                                }
                            }
                            op_stack.push(token);
                        }
                    }
                }
            }
            else if (token == "^")
                op_stack.push(token);
            else if (token == "(")
                op_stack.push(token);
            else if (token == ")")
            {
                top_op = op_stack.top();

                while (top_op != "(")
                {
                    postfix_q.enqueue(top_op);
                    op_stack.pop();
                    top_op = op_stack.top();
                }

                // Discard left parenthesis
                op_stack.pop();
            }
        }

        // Move to the next token
        infix.dequeue();
    }

    // Push the remaining operators on the output queue
    while (!op_stack.empty())
    {
        postfix_q.enqueue(op_stack.top());
        op_stack.pop();
    }
}