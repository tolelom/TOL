#include "parser.h"
#include "../exception/parserException/parserException.h"

Program* Parser::run(vector<Token*> inputTokens) {
    tokens = std::move(inputTokens);
    initialization();

    try {

    } catch (const ParserException& e) {
        e.print();
    }

    return program;
}


void Parser::initialization() {
    delete program;
    program = new Program;
    currentReadPoint = 0;
    nextReadPoint = 1;
    currentToken = tokens[currentReadPoint];
    nextToken = tokens[nextReadPoint];
}

void Parser::setNextToken() {
    currentReadPoint++;
    nextReadPoint++;
    currentToken = tokens[currentReadPoint];
    nextToken = tokens[nextReadPoint];
}

void Parser::skipToken(TokenType type) {
    if (currentToken->type != type) {
        throw TokenNotFound(type, currentToken);
    }
}