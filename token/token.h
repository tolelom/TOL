#ifndef TOL_TOKEN_H
#define TOL_TOKEN_H

#include <iostream>
#include <string>
#include "token_type.h"

using namespace std;

class Token {
public:
    Token(TokenType type, std::string literal, long long line);

    TokenType type;
    string literal;
    long long line;

    static string PrintTokenType(TokenType type) {
        switch (type) {
            case TokenType::ILLEGAL:
                return "ILLEGAL";
            case TokenType::END_OF_FILE:
                return "END OF FILE";
            case TokenType::NEW_LINE:
                return "NEW LINE";
            case TokenType::TAB:
                return "TAB";
            case TokenType::SPACE:
                return "SPACE";
            case TokenType::IDENTIFIER:
                return "식별자";

            case TokenType::COLON:
                return "COLON";
            case TokenType::SEMICOLON:
                return "SEMICOLON";
            case TokenType::COMMA:
                return "COMMA";
            case TokenType::DOT:
                return "DOT";

            case TokenType::PLUS:
                return "PLUS";
            case TokenType::MINUS:
                return "MINUS";
            case TokenType::ASTERISK:
                return "ASTERISK";
            case TokenType::SLASH:
                return "SLASH";
            case TokenType::ASSIGN:
                return "ASSIGN";
            case TokenType::EQUAL:
                return "EQUAL";
            case TokenType::NOT_EQUAL:
                return "NOT EQUAL";
            case TokenType::BANG:
                return "BANG";

            case TokenType::LPAREN:
                return "LPAREN";
            case TokenType::RPAREN:
                return "RPAREN";
            case TokenType::LBRACE:
                return "LBRACE";
            case TokenType::RBRACE:
                return "RBRACE";
            case TokenType::LBRACKET:
                return "LBRACKET";
            case TokenType::RBRACKET:
                return "RBRACKET";

            case TokenType::LESS_THAN:
                return "LESS THAN";
            case TokenType::LESS_EQUAL:
                return "LESS EQUAL";
            case TokenType::GREATER_THAN:
                return "GREATER THAN";
            case TokenType::GREATER_EQUAL:
                return "GREATER EQUAL";

            case TokenType::RIGHTARROW:
                return "RIGHT ARROW";

            case TokenType::INTEGER:
                return "정수";
            case TokenType::INT:
                return "자료형 정수";
            case TokenType::STRING:
                return "문자";
            case TokenType::STR:
                return "자료형 문자열";
        }
    }
};

#endif //TOL_TOKEN_H
