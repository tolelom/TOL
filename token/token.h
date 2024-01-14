#ifndef TOL_TOKEN_H
#define TOL_TOKEN_H

#include <iostream>
#include <string>
#include "tokenType.h"

using namespace std;

class Token {
public:
    Token(TokenType type, std::string literal, long long line);

    TokenType type;
    std::string literal;
    long long line;

    void printTokenType() const;
};

#endif //TOL_TOKEN_H
