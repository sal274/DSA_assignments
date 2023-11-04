/*
InfixExpr.h

Declares class InfixExpr

Class InfixExpr represents an infix arithmetic expression
*/

#ifndef INFIXEXPR_H
#define INFIXEXPR_H

#include <string>
#include <utility>

#include "Queue.h"

class InfixExpr
{
    public:

        InfixExpr(const std::string& expr);
        InfixExpr(std::string&& expr);

        std::string postfix() const { return postfix_expr_str; }
        std::string infix() const { return postfix_expr_str; }
        double evaluate() const { return result; }

    private:

        std::string infix_expr_str;
        std::string postfix_expr_str;
        Queue<std::string> token_queue;
        double result;

        bool valid() const;
        void to_queue();
        void to_postfix();
        void eval();
        void remove_whitespace();
};

#endif