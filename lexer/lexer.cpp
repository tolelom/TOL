#include "lexer.h"

#include <utility>


vector<Token*> Lexer::Run(vector<string> characters) {
    this->characters = std::move(characters);
    initialization();

    try {
        tokenizing();
    }
    catch (const LexerException& e) {
        e.Print();
    }

    return tokens;
}

void Lexer::initialization() {
    current_read_point = 0;
    next_read_point = 1;
    indent_level = 0;
    line = 1;

    tokens.clear();
}

void Lexer::tokenizing() {
    while (current_read_point < characters.size()) {
        if (characters[current_read_point] == "\n") {
            long long indentCount = countIndentAndSkipTab();
            if (indent_level < indentCount) {
                tokens.push_back(new Token{TokenType::NEW_LINE, characters[current_read_point], line});
//                tokens.push_back(new Token{})
            }
            else if (indentCount < indent_level) {
                tokens.push_back(new Token{TokenType::NEW_LINE, characters[current_read_point], line});

            }
            else {
                tokens.push_back(new Token{TokenType::NEW_LINE, characters[current_read_point], line});

            }
            indent_level = indentCount;
            line++;
        }
        else if (characters[current_read_point] == "\t") {
            tokens.push_back((new Token{TokenType::TAB, characters[current_read_point], line}));
        }
        else if (characters[current_read_point] == " ") {
            if (canMakeSpaceToTab()) {
                tokens.push_back(new Token{TokenType::TAB, "\t", line});
                skipCharacter();
                skipCharacter();
                skipCharacter();
                // TODO: tabcount
            } else {
                tokens.push_back(new Token{TokenType::SPACE, characters[current_read_point], line});
            }
        }

        else if (characters[current_read_point] == ":") {
            tokens.push_back(new Token{TokenType::COLON, characters[current_read_point], line});
        }
        else if (characters[current_read_point] == ";") {
            tokens.push_back(new Token{TokenType::SEMICOLON, characters[current_read_point], line});
        }
        else if (characters[current_read_point] == ",") {
            tokens.push_back(new Token{TokenType::COMMA, characters[current_read_point], line});
        }
        else if (characters[current_read_point] == ".") {
            tokens.push_back(new Token{TokenType::DOT, characters[current_read_point], line});
        }


        else if (characters[current_read_point] == "+") {
            tokens.push_back(new Token{TokenType::PLUS, characters[current_read_point], line});
        }
        else if (characters[current_read_point] == "-") {
            if (next_read_point < characters.size() && characters[next_read_point] == ">") {
                tokens.push_back(new Token{TokenType::RIGHTARROW, characters[current_read_point] + characters[next_read_point], line});
                skipCharacter();
            } else {
                tokens.push_back(new Token{TokenType::MINUS, characters[current_read_point], line});
            }
        }
        else if (characters[current_read_point] == "*") {
            tokens.push_back(new Token{TokenType::ASTERISK, characters[current_read_point], line});
        }
        else if (characters[current_read_point] == "/") {
            tokens.push_back(new Token{TokenType::SLASH, characters[current_read_point], line});
        }
        else if (characters[current_read_point] == "=") {
            if (next_read_point < characters.size() && characters[next_read_point] == "=") {
                tokens.push_back(new Token{TokenType::EQUAL, characters[current_read_point] + characters[next_read_point], line});
                skipCharacter();
            } else {
            tokens.push_back(new Token{TokenType::ASSIGN, characters[current_read_point], line});
            }
        }
        else if (characters[current_read_point] == "!") {
            if (next_read_point < characters.size() && characters[next_read_point] == "=") {
                tokens.push_back(new Token{TokenType::NOT_EQUAL, characters[current_read_point] + characters[next_read_point], line});
                skipCharacter();
            } else {
                tokens.push_back(new Token{TokenType::BANG, characters[current_read_point], line});
            }
        }

        else if (characters[current_read_point] == "(") {
            tokens.push_back(new Token{TokenType::LPAREN, characters[current_read_point], line});
        }
        else if (characters[current_read_point] == ")") {
            tokens.push_back(new Token{TokenType::RPAREN, characters[current_read_point], line});
        }
        else if (characters[current_read_point] == "{") {
            tokens.push_back(new Token{TokenType::LBRACE, characters[current_read_point], line});
        }
        else if (characters[current_read_point] == "}") {
            tokens.push_back(new Token{TokenType::RBRACE, characters[current_read_point], line});
        }
        else if (characters[current_read_point] == "[") {
            tokens.push_back(new Token{TokenType::LBRACKET, characters[current_read_point], line});
        }
        else if (characters[current_read_point] == "]") {
            tokens.push_back(new Token{TokenType::RBRACKET, characters[current_read_point], line});
        }

        else if (characters[current_read_point] == "<") {
            if (next_read_point < characters.size() && characters[next_read_point] == "=") {
                tokens.push_back(new Token{TokenType::LESS_EQUAL, characters[current_read_point] + characters[next_read_point], line});
                skipCharacter();
            } else {
                tokens.push_back(new Token{TokenType::LESS_THAN, characters[current_read_point], line});
            }
        }
        else if (characters[current_read_point] == ">") {
            if (next_read_point < characters.size() && characters[next_read_point] == "=") {
                tokens.push_back(new Token{TokenType::GREATER_EQUAL, characters[current_read_point] + characters[next_read_point], line});
                skipCharacter();
            } else {
                tokens.push_back(new Token{TokenType::GREATER_THAN, characters[current_read_point], line});
            }
        }


        else if (isNumber(characters[current_read_point])) {
            string number = readNumber();
            tokens.push_back(new Token{TokenType::INTEGER, number, line});
        }
        else if (isLetter(characters[current_read_point])) {
            string letter = readLetter();
            if (keywords.find(letter) != keywords.end()) {
                tokens.push_back(new Token{keywords.find(letter)->second, letter, line});
            } else {
                tokens.push_back(new Token{TokenType::IDENTIFIER, letter, line});
            }
        }
        else {
            tokens.push_back(new Token{TokenType::ILLEGAL, characters[current_read_point], line});
        }
        skipCharacter();
    }
}

void Lexer::skipCharacter() {
    current_read_point++;
    next_read_point++;
}

bool Lexer::isNumber(const string& character) {
    return ("0" <= character && character <= "9");
}

bool Lexer::isLetter(const string& character) {
    return ("a" <= character && character <= "z") || ("A" <= character && character <= "Z") || character == "_" || ("가" <= character && character <= "힣") || ("0" <= character && character <= "9");
}

string Lexer::readNumber() {
    string number = characters[current_read_point];
    while (next_read_point < characters.size() && isNumber(characters[next_read_point])) {
        skipCharacter();
        number += characters[current_read_point];
    }
    return number;
}

string Lexer::readLetter() {
    string letter = characters[current_read_point];
    while (next_read_point < characters.size() && isLetter(characters[next_read_point])) {
        skipCharacter();
        letter += characters[current_read_point];
    }
    return letter;
}

bool Lexer::canMakeSpaceToTab() {
    for (long long counter = 1; current_read_point + counter < characters.size() && characters[current_read_point + counter] == " "; counter++) {
        if (counter == 4) {
            return true;
        }
    }
    return false;
}

long long Lexer::countIndentAndSkipTab() {
    long long count = 0;
    while (next_read_point < characters.size() && characters[next_read_point] == "\t") {
        skipCharacter();
        count++;
    }
    return count;
}