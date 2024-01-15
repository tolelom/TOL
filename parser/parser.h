#ifndef TOL_PARSER_H
#define TOL_PARSER_H


#include "../token/token.h"
#include "../ast/program.h"

class Parser {
public:
    Program* run(vector<Token*> tokens);
private:
    vector<Token*> tokens;
    Program* program;
    long long currentReadPoint;
    long long nextReadPoint;
    Token* currentToken;
    Token* nextToken;

    void initialization();
    void setNextToken();
    void skipToken(TokenType type);
};


#endif //TOL_PARSER_H
