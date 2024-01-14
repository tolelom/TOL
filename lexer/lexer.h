#ifndef TOL_LEXER_H
#define TOL_LEXER_H

#include <map>
#include <vector>
#include <string>
#include "../token/token.h"
#include "../exception/lexerException/lexerException.h"

using namespace std;

class Lexer {
public:
    vector<Token*> run(vector<string> characters);

private:
    vector<string> characters;
    vector<Token*> tokens;
    long long currentReadPoint;
    long long nextReadPoint;
    long long indentLevel;
    long long line;

    void initialization();
    void tokenizing();

    void skipCharacter();
    bool isLetter(const string& character);
    bool isNumber(const string& character);
    string readNumber();
    string readLetter();

    map<string, TokenType> keywords = {
            {"정수", TokenType::INT},

    };
};


#endif //TOL_LEXER_H
