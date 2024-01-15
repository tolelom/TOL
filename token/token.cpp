#include "token.h"

#include <utility>

Token::Token(TokenType type, std::string literal, long long line) : type(type), literal(std::move(literal)), line(line) {}

