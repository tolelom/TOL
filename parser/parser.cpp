#include "parser.h"
#include "../exception/parser_exception/parser_exception.h"

Program* Parser::Run(vector<Token*> inputTokens) {
    tokens = std::move(inputTokens);
    initialization();

    try {
        while (current_read_point < tokens.size()) {
            if (current_token->type == TokenType::END_OF_FILE) {
                break;
            }
            Statement* statement = parseStatement();
            program->statements.push_back(statement);
        }
    } catch (const ParserException& e) {
        e.Print();
    }

    return program;
}


void Parser::initialization() {
    delete program;
    program = new Program;
    current_read_point = 0;
    next_read_point = 1;
    current_token = tokens[current_read_point];
    next_token = tokens[next_read_point];
}

void Parser::setNextToken() {
    current_read_point++;
    next_read_point++;
    current_token = tokens[current_read_point];
    next_token = tokens[next_read_point];
}

void Parser::skipToken(TokenType type) {
    if (current_token->type != type) {
        throw UnexceptedTokenTypeException(current_token, type);
    }
}


Statement* Parser::parseStatement() {
    if (current_token->type == TokenType::LBRACKET) {
        return parseDeclarationStatement();
    }
    else {
        return parseExpressionStatement();
    }
}

ExpressionStatement *Parser::parseExpressionStatement() {
    ExpressionStatement* expression_statement = new ExpressionStatement;
    expression_statement->expression = parseExpression(Precedence::LOWEST);
    setNextToken();

    return expression_statement;
}


DeclarationStatement *Parser::parseDeclarationStatement() {
    skipToken(TokenType::LBRACKET);
    if (current_token->type != TokenType::INT) {
        throw InvalidDataTypeTokenException(current_token);
    }

    DeclarationStatement* declaration_statement = new DeclarationStatement;
    declaration_statement->data_type_token = current_token;
    setNextToken();

    // const check
    declaration_statement->is_const = (current_token->type == TokenType::BANG);
    if (current_token->type == TokenType::BANG) {
        skipToken(TokenType::BANG);
    }

    skipToken(TokenType::RBRACKET);
    skipToken(TokenType::SPACE);

    if (current_token->type != TokenType::IDENTIFIER) {
        throw UnexceptedTokenTypeException(current_token, TokenType::IDENTIFIER);
    }
    declaration_statement->name = dynamic_cast<IdentifierExpression*>(parseIdentifierExpression());
    skipToken(TokenType::IDENTIFIER);

    skipToken(TokenType::SPACE);
    skipToken(TokenType::ASSIGN);
    skipToken(TokenType::SPACE);

    declaration_statement->expression = parseExpression(Precedence::LOWEST);
    setNextToken();

    return declaration_statement;
}



Expression* Parser::parseExpression(Precedence precedence) {
    if (prefixParseFunctionMap.find(current_token->type) == prefixParseFunctionMap.end()) {
        throw NotFoundPrefixFunction(current_token);
    }

    PrefixParseFunction prefixFunction = prefixParseFunctionMap[current_token->type];
    Expression* leftExpression = (this->*prefixFunction)();


}

Expression* Parser::parseIdentifierExpression() {
    if (current_token->type != TokenType::IDENTIFIER) {
        throw UnexceptedTokenTypeException(current_token, TokenType::IDENTIFIER);
    }

    return new IdentifierExpression(current_token);
}