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
    string literal;
    long long line;

    static string printTokenType(TokenType type) {
        switch (type) {
            case TokenType::ILLEGAL:
                return "ILLEGAL";
                break;
            case TokenType::END_OF_FILE:
                return "END OF FILE";
                break;
            case TokenType::NEW_LINE:
                return "NEW LINE";
                break;
            case TokenType::TAB:
                return "TAB";
                break;
            case TokenType::SPACE:
                return "SPACE";
                break;

            case TokenType::IDENTIFIER:
                return "식별자";
                break;

            case TokenType::COLON:
                return "COLON";
                break;
            case TokenType::SEMICOLON:
                return "SEMICOLON";
                break;
            case TokenType::COMMA:
                return "COMMA";
                break;
            case TokenType::DOT:
                return "DOT";
                break;

            case TokenType::PLUS:
                return "PLUS";
                break;
            case TokenType::MINUS:
                return "MINUS";
                break;
            case TokenType::ASTERISK:
                return "ASTERISK";
                break;
            case TokenType::SLASH:
                return "SLASH";
                break;
            case TokenType::ASSIGN:
                return "ASSIGN";
                break;
            case TokenType::EQUAL:
                return "EQUAL";
                break;
            case TokenType::NOT_EQUAL:
                return "NOT EQUAL";
                break;
            case TokenType::BANG:
                return "BANG";
                break;

            case TokenType::LPAREN:
                return "LPAREN";
                break;
            case TokenType::RPAREN:
                return "RPAREN";
                break;
            case TokenType::LBRACE:
                return "LBRACE";
                break;
            case TokenType::RBRACE:
                return "RBRACE";
                break;
            case TokenType::LBRACKET:
                return "LBRACKET";
                break;
            case TokenType::RBRACKET:
                return "RBRACKET";
                break;

            case TokenType::LESS_THAN:
                return "LESS THAN";
                break;
            case TokenType::LESS_EQUAL:
                return "LESS EQUAL";
                break;
            case TokenType::GREATER_THAN:
                return "GREATER THAN";
                break;
            case TokenType::GREATER_EQUAL:
                return "GREATER EQUAL";
                break;

            case TokenType::RIGHTARROW:
                return "RIGHT ARROW";
                break;

            case TokenType::INTEGER:
                return "정수";
                break;
            case TokenType::INT:
                return "자료형 정수";
                break;
            case TokenType::STRING:
                return "문자";
                break;
            case TokenType::STR:
                return "자료형 문자열";
                break;
        }
    }
};

#endif //TOL_TOKEN_H
