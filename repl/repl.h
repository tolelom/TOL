#ifndef TOL_REPL_H
#define TOL_REPL_H

#include <iostream>
#include <string>
#include "../utf8Converter/utf8Converter.h"
#include "../lexer/lexer.h"

using namespace std;

class Repl {
public:
    void lexerTest();
    void parserTest();
    void run();
private:
    Utf8Converter utf8Converter;
    Lexer lexer;

};


#endif //TOL_REPL_H
