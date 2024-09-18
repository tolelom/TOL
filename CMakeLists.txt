cmake_minimum_required(VERSION 3.26)
project(TOL)

set(CMAKE_CXX_STANDARD 23)

add_executable(TOL main.cpp
        repl/repl.cpp
        repl/repl.h
        lexer/lexer.cpp
        lexer/lexer.h
        token/token.h
        token/token_type.h
        token/token.cpp
        utf8_converter/utf8_converter.cpp
        utf8_converter/utf8_converter.h
        exception/exception.h
        exception/lexer_exception/lexer_exception.h
        parser/parser.cpp
        parser/parser.h
        ast/node.h
        ast/program.h
        ast/statement/statement.h
        exception/parser_exception/parser_exception.h
        ast/statement/declaration_statement.h
        ast/expression/identifier_expression.h
        ast/expression/expression.h
        ast/statement/expression_statement.h
)
