#ifndef IDENTIFIER_EXPRESSION_H
#define IDENTIFIER_EXPRESSION_H
#include "expression.h"


class IdentifierExpression : public Expression {
public:
    IdentifierExpression(Token* token) : token(token) {};
    string String() override;

    Token* token;
private:

};

#endif //IDENTIFIER_EXPRESSION_H
