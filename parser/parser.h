#ifndef TOL_PARSER_H
#define TOL_PARSER_H

#include <functional>
#include <map>
#include <memory>

#include "../token/token.h"
#include "../ast/program.h"
#include "../ast/statement/declaration_statement.h"
#include "../ast/statement/expression_statement.h"

enum class Precedence;

class Parser {
public:
    Program* Run(vector<Token*> tokens);
private:
    vector<Token*> tokens;
    Program* program;
    long long current_read_point;
    long long next_read_point;
    Token* current_token;
    Token* next_token;

    const static Precedence precedence;

    void initialization();
    void setNextToken();
    void skipToken(TokenType type);
    Statement* parseStatement();
    ExpressionStatement* parseExpressionStatement();
    DeclarationStatement* parseDeclarationStatement();

    Expression* parseExpression(Precedence precedence);
    Expression* parseIdentifierExpression();

    using PrefixParseFunction = Expression* (Parser::*)();
    // 이 방법을 적용한다면 parseExpression 함수들 리턴값이 Expression*일 필요가 없다.
    // using expressionInverter = std::function<std::unique_ptr<Expression*>()>;
    std::map<TokenType, PrefixParseFunction> prefixParseFunctionMap = {
        {TokenType::IDENTIFIER, &Parser::parseIdentifierExpression},
    };
};

enum class Precedence {
    LOWEST,
    EQUALS,         // ==
    LESSGREATER,    // <, >
    SUM,            // +
    PRODUCT,        // *
    PREFIX,         // -X, !X
    CALL,           // myFunction(x)
    INDEX,          // array[index]
};

#endif //TOL_PARSER_H
