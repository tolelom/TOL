#include "lexer.h"

#include <utility>


vector<Token*> Lexer::run(vector<string> characters) {
    this->characters = std::move(characters);
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
            long long indentCount = countIndentAndSkipTab();
            if (indentLevel < indentCount) {
                tokens.push_back(new Token{TokenType::NEW_LINE, characters[currentReadPoint], line});
//                tokens.push_back(new Token{})
            }
            else if (indentCount < indentLevel) {
                tokens.push_back(new Token{TokenType::NEW_LINE, characters[currentReadPoint], line});

            }
            else {
                tokens.push_back(new Token{TokenType::NEW_LINE, characters[currentReadPoint], line});

            }
            indentLevel = indentCount;
            line++;
        }
        else if (characters[currentReadPoint] == "\t") {
            tokens.push_back((new Token{TokenType::TAB, characters[currentReadPoint], line}));
        }
        else if (characters[currentReadPoint] == " ") {
            if (canMakeSpaceToTab()) {
                tokens.push_back(new Token{TokenType::TAB, "\t", line});
                skipCharacter();
                skipCharacter();
                skipCharacter();
                // TODO: tabcount
            } else {
                tokens.push_back(new Token{TokenType::SPACE, characters[currentReadPoint], line});
            }
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
            if (nextReadPoint < characters.size() && characters[nextReadPoint] == ">") {
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
            if (nextReadPoint < characters.size() && characters[nextReadPoint] == "=") {
                tokens.push_back(new Token{TokenType::EQUAL, characters[currentReadPoint] + characters[nextReadPoint], line});
                skipCharacter();
            } else {
            tokens.push_back(new Token{TokenType::ASSIGN, characters[currentReadPoint], line});
            }
        }
        else if (characters[currentReadPoint] == "!") {
            if (nextReadPoint < characters.size() && characters[nextReadPoint] == "=") {
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
            if (nextReadPoint < characters.size() && characters[nextReadPoint] == "=") {
                tokens.push_back(new Token{TokenType::LESS_EQUAL, characters[currentReadPoint] + characters[nextReadPoint], line});
                skipCharacter();
            } else {
                tokens.push_back(new Token{TokenType::LESS_THAN, characters[currentReadPoint], line});
            }
        }
        else if (characters[currentReadPoint] == ">") {
            if (nextReadPoint < characters.size() && characters[nextReadPoint] == "=") {
                tokens.push_back(new Token{TokenType::GREATER_EQUAL, characters[currentReadPoint] + characters[nextReadPoint], line});
                skipCharacter();
            } else {
                tokens.push_back(new Token{TokenType::GREATER_THAN, characters[currentReadPoint], line});
            }
        }


        else if (isNumber(characters[currentReadPoint])) {
            string number = readNumber();
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

bool Lexer::canMakeSpaceToTab() {
    for (long long counter = 1; currentReadPoint + counter < characters.size() && characters[currentReadPoint + counter] == " "; counter++) {
        if (counter == 4) {
            return true;
        }
    }
    return false;
}

long long Lexer::countIndentAndSkipTab() {
    long long count = 0;
    while (nextReadPoint < characters.size() && characters[nextReadPoint] == "\t") {
        skipCharacter();
        count++;
    }
    return count;
}