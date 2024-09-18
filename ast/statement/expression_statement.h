#ifndef EXPRESSION_STATEMENT_H
#define EXPRESSION_STATEMENT_H
#include "statement.h"
#include "../expression/expression.h"


class ExpressionStatement : public Statement {
public:
    Expression* expression;

    string String() override {
        if (expression == nullptr) {
            return "";
        }
        return expression->String();
    }
};


#endif //EXPRESSION_STATEMENT_H
