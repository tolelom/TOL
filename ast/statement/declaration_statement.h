#ifndef DECLARATIONSTATEMENT_H
#define DECLARATIONSTATEMENT_H


#include "statement.h"
#include "../expression/identifier_expression.h"

class DeclarationStatement : public Statement {
public:
    string String() override;

    Token* data_type_token;
    IdentifierExpression* name;
    Expression* expression;
    bool is_const;
};


#endif //DECLARATIONSTATEMENT_H
