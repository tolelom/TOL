#include "lexer.h"


vector<Token*> Lexer::run(vector<string> characters) {
    this->characters = characters;
    initialization();

    try {
        tokenizing();
    }
    catch (const LexerException& e) {
        e.print();
    }

    return tokens;
}

void Lexer::initialization() {
    currentReadPoint = 0;
    nextReadPoint = 1;
    indentLevel = 0;
    line = 1;

    tokens.clear();
}

void Lexer::tokenizing() {
    while (currentReadPoint < characters.size()) {
        if (characters[currentReadPoint] == "\n") {
            tokens.push_back(new Token{TokenType::NEW_LINE, characters[currentReadPoint], line});
        }
        else if (characters[currentReadPoint] == "\t") {
            tokens.push_back((new Token{TokenType::TAB, characters[currentReadPoint], line}));
        }
        else if (characters[currentReadPoint] == " ") {
            tokens.push_back(new Token{TokenType::SPACE, characters[currentReadPoint], line});
        }

        else if (characters[currentReadPoint] == ":") {
            tokens.push_back(new Token{TokenType::COLON, characters[currentReadPoint], line});
        }
        else if (characters[currentReadPoint] == ";") {
            tokens.push_back(new Token{TokenType::SEMICOLON, characters[currentReadPoint], line});
        }
        else if (characters[currentReadPoint] == ",") {
            tokens.push_back(new Token{TokenType::COMMA, characters[currentReadPoint], line});
        }
        else if (characters[currentReadPoint] == ".") {
            tokens.push_back(new Token{TokenType::DOT, characters[currentReadPoint], line});
        }


        else if (characters[currentReadPoint] == "+") {
            tokens.push_back(new Token{TokenType::PLUS, characters[currentReadPoint], line});
        }
        else if (characters[currentReadPoint] == "-") {
            if (characters[nextReadPoint] == ">") {
                tokens.push_back(new Token{TokenType::RIGHTARROW, characters[currentReadPoint] + characters[nextReadPoint], line});
                skipCharacter();
            } else {
                tokens.push_back(new Token{TokenType::MINUS, characters[currentReadPoint], line});
            }
        }
        else if (characters[currentReadPoint] == "*") {
            tokens.push_back(new Token{TokenType::ASTERISK, characters[currentReadPoint], line});
        }
        else if (characters[currentReadPoint] == "/") {
            tokens.push_back(new Token{TokenType::SLASH, characters[currentReadPoint], line});
        }
        else if (characters[currentReadPoint] == "=") {
            if (characters[nextReadPoint] == "=") {
                tokens.push_back(new Token{TokenType::EQUAL, characters[currentReadPoint] + characters[nextReadPoint], line});
                skipCharacter();
            } else {
            tokens.push_back(new Token{TokenType::ASSIGN, characters[currentReadPoint], line});
            }
        }
        else if (characters[currentReadPoint] == "!") {
            if (characters[nextReadPoint] == "=") {
                tokens.push_back(new Token{TokenType::NOT_EQUAL, characters[currentReadPoint] + characters[nextReadPoint], line});
                skipCharacter();
            } else {
                tokens.push_back(new Token{TokenType::BANG, characters[currentReadPoint], line});
            }
        }

        else if (characters[currentReadPoint] == "(") {
            tokens.push_back(new Token{TokenType::LPAREN, characters[currentReadPoint], line});
        }
        else if (characters[currentReadPoint] == ")") {
            tokens.push_back(new Token{TokenType::RPAREN, characters[currentReadPoint], line});
        }
        else if (characters[currentReadPoint] == "{") {
            tokens.push_back(new Token{TokenType::LBRACE, characters[currentReadPoint], line});
        }
        else if (characters[currentReadPoint] == "}") {
            tokens.push_back(new Token{TokenType::RBRACE, characters[currentReadPoint], line});
        }
        else if (characters[currentReadPoint] == "[") {
            tokens.push_back(new Token{TokenType::LBRACKET, characters[currentReadPoint], line});
        }
        else if (characters[currentReadPoint] == "]") {
            tokens.push_back(new Token{TokenType::RBRACKET, characters[currentReadPoint], line});
        }

        else if (characters[currentReadPoint] == "<") {
            if (characters[nextReadPoint] == "=") {
                tokens.push_back(new Token{TokenType::LESS_EQUAL, characters[currentReadPoint] + characters[nextReadPoint], line});
                skipCharacter();
            } else {
                tokens.push_back(new Token{TokenType::LESS_THAN, characters[currentReadPoint], line});
            }
        }
        else if (characters[currentReadPoint] == ">") {
            if (characters[nextReadPoint] == "=") {
                tokens.push_back(new Token{TokenType::GREATER_EQUAL, characters[currentReadPoint] + characters[nextReadPoint], line});
                skipCharacter();
            } else {
                tokens.push_back(new Token{TokenType::GREATER_THAN, characters[currentReadPoint], line});
            }
        }


        else if (isNumber(characters[currentReadPoint])) {
            string number = readLetter();
            tokens.push_back(new Token{TokenType::INTEGER, number, line});
        }
        else if (isLetter(characters[currentReadPoint])) {
            string letter = readLetter();
            if (keywords.find(letter) != keywords.end()) {
                tokens.push_back(new Token{keywords.find(letter)->second, letter, line});
            } else {
                tokens.push_back(new Token{TokenType::IDENTIFIER, letter, line});
            }
        }
        else {
            tokens.push_back(new Token{TokenType::ILLEGAL, characters[currentReadPoint], line});
        }
        skipCharacter();
    }
}

void Lexer::skipCharacter() {
    currentReadPoint++;
    nextReadPoint++;
}

bool Lexer::isNumber(const string& character) {
    return ("0" <= character && character <= "9");
}

bool Lexer::isLetter(const string& character) {
    return ("a" <= character && character <= "z") || ("A" <= character && character <= "Z") || character == "_" || ("가" <= character && character <= "힣") || ("0" <= character && character <= "9");
}

string Lexer::readNumber() {
    string number = characters[currentReadPoint];
    while (nextReadPoint < characters.size() && isNumber(characters[nextReadPoint])) {
        skipCharacter();
        number += characters[currentReadPoint];
    }
    return number;
}

string Lexer::readLetter() {
    string letter = characters[currentReadPoint];
    while (nextReadPoint < characters.size() && isLetter(characters[nextReadPoint])) {
        skipCharacter();
        letter += characters[currentReadPoint];
    }
    return letter;
}