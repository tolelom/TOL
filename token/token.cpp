#include "token.h"

#include <utility>

Token::Token(TokenType type, std::string literal, long long line) : type(type), literal(std::move(literal)), line(line) {}

void Token::printTokenType() const {
    switch (type) {
        case TokenType::ILLEGAL:
            cout << "ILLEGAL";
            break;
        case TokenType::END_OF_FILE:
            cout << "END OF FILE";
            break;
        case TokenType::NEW_LINE:
            cout << "NEW LINE";
            break;
        case TokenType::TAB:
            cout << "TAB";
            break;
        case TokenType::SPACE:
            cout << "SPACE";
            break;

        case TokenType::IDENTIFIER:
            cout << "식별자";
            break;

        case TokenType::COLON:
            cout << "COLON";
            break;
        case TokenType::SEMICOLON:
            cout << "SEMICOLON";
            break;
        case TokenType::COMMA:
            cout << "COMMA";
            break;
        case TokenType::DOT:
            cout << "DOT";
            break;

        case TokenType::PLUS:
            cout << "PLUS";
            break;
        case TokenType::MINUS:
            cout << "MINUS";
            break;
        case TokenType::ASTERISK:
            cout << "ASTERISK";
            break;
        case TokenType::SLASH:
            cout << "SLASH";
            break;
        case TokenType::ASSIGN:
            cout << "ASSIGN";
            break;
        case TokenType::EQUAL:
            cout << "EQUAL";
            break;
        case TokenType::NOT_EQUAL:
            cout << "NOT EQUAL";
            break;
        case TokenType::BANG:
            cout << "BANG";
            break;

        case TokenType::LPAREN:
            cout << "LPAREN";
            break;
        case TokenType::RPAREN:
            cout << "RPAREN";
            break;
        case TokenType::LBRACE:
            cout << "LBRACE";
            break;
        case TokenType::RBRACE:
            cout << "RBRACE";
            break;
        case TokenType::LBRACKET:
            cout << "LBRACKET";
            break;
        case TokenType::RBRACKET:
            cout << "RBRACKET";
            break;

        case TokenType::LESS_THAN:
            cout << "LESS THAN";
            break;
        case TokenType::LESS_EQUAL:
            cout << "LESS EQUAL";
            break;
        case TokenType::GREATER_THAN:
            cout << "GREATER THAN";
            break;
        case TokenType::GREATER_EQUAL:
            cout << "GREATER EQUAL";
            break;

        case TokenType::RIGHTARROW:
            cout << "RIGHT ARROW";
            break;

        case TokenType::INTEGER:
            cout << "정수";
            break;
        case TokenType::INT:
            cout << "자료형 정수";
            break;
        case TokenType::STRING:
            cout << "문자";
            break;
        case TokenType::STR:
            cout << "자료형 문자열";
            break;
    }

    cout << ": " << line << endl;
}
