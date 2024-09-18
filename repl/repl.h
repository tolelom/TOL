#ifndef TOL_REPL_H
#define TOL_REPL_H

#include <iostream>
#include <string>
#include "../utf8_converter/utf8_converter.h"
#include "../lexer/lexer.h"

using namespace std;

class Repl {
public:
    void LexerTest();
    void ParserTest();
    void Run();
private:
    Utf8Converter utf8_converter;
    Lexer lexer;

};


#endif //TOL_REPL_H
