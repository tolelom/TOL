cmake_minimum_required(VERSION 3.26)
project(TOL)

set(CMAKE_CXX_STANDARD 23)

add_executable(TOL main.cpp
        repl/repl.cpp
        repl/repl.h
        lexer/lexer.cpp
        lexer/lexer.h
        token/token.h
        token/tokenType.h
        token/token.cpp
        utf8Converter/utf8Converter.cpp
        utf8Converter/utf8Converter.h
        exception/exception.h
        exception/lexerException/lexerException.h)
