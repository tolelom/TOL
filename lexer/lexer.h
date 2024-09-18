#ifndef TOL_LEXER_H
#define TOL_LEXER_H

#include <map>
#include <vector>
#include <string>
#include "../token/token.h"
#include "../exception/lexer_exception/lexer_exception.h"

using namespace std;

class Lexer {
public:
    vector<Token*> Run(vector<string> characters);

private:
    vector<string> characters;
    vector<Token*> tokens;
    long long current_read_point;
    long long next_read_point;
    long long indent_level;
    long long line;

    void initialization();
    void tokenizing();

    void skipCharacter();
    static bool isLetter(const string& character);
    static bool isNumber(const string& character);
    string readNumber();
    string readLetter();
    bool canMakeSpaceToTab();
    long long countIndentAndSkipTab();

    map<string, TokenType> keywords = {
            {"정수", TokenType::INT},

    };
};


#endif //TOL_LEXER_H
