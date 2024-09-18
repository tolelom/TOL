#ifndef TOL_PARSEREXCEPTION_H
#define TOL_PARSEREXCEPTION_H

#include "../exception.h"

class ParserException : public CustomException {

};


class UnexceptedTokenTypeException : public ParserException {
public:
    UnexceptedTokenTypeException(Token* token, TokenType type) : token(token), type(type) {};

    void Print() const final {
        cout << token->line << "번 줄: 예상되는 토큰이 존재하지 않습니다. 예상 토큰: ";
        Token::PrintTokenType(type);
    }

private:
    TokenType type;
    Token* token;
};


class InvalidDataTypeTokenException : public ParserException {
public:
    InvalidDataTypeTokenException(Token* token) : token(token) {};

    void Print() const final {
        cout << token->line << "번 줄: 존재하지 않은 데이터 타입입니다. 현재 타입: ";
        Token::PrintTokenType(token->type);
    }

private:
    Token* token;
};

#endif //TOL_PARSEREXCEPTION_H

class NotFoundPrefixFunction : public ParserException {
public:
    NotFoundPrefixFunction(Token* token) : token(token) {};

    void Print() const final {
        cout << token->line << "번 줄: prefix function을 찾을 수 없습니다. 현재 타입: ";
        Token::PrintTokenType(token->type);
    }
private:
    Token* token;
};