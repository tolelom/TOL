#ifndef TOL_PARSEREXCEPTION_H
#define TOL_PARSEREXCEPTION_H

#include "../exception.h"

class ParserException : public CustomException {

};


class TokenNotFound : public ParserException {
public:
    TokenNotFound(TokenType type, Token* token) : type(type), token(token) {};

    void print() const final {
        cout << token->line << "번 줄: 예상되는 토큰이 존재하지 않습니다. 예상 토큰: ";
        Token::printTokenType(type);
    }

private:
    TokenType type;
    Token* token;
    long long line;
};

#endif //TOL_PARSEREXCEPTION_H
