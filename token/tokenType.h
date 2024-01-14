#ifndef TOL_TOKENTYPE_H
#define TOL_TOKENTYPE_H

enum class TokenType {
    ILLEGAL,
    END_OF_FILE,
    NEW_LINE,
    TAB,
    SPACE,

    IDENTIFIER,

    COLON,          // :
    SEMICOLON,      // ;
    COMMA,          // ,
    DOT,            // .

    PLUS,           // +
    MINUS,          // -
    ASTERISK,       // *
    SLASH,          // /
    ASSIGN,         // =
    EQUAL,          // ==
    NOT_EQUAL,      // !=
    BANG,           // !

    LPAREN,         // (
    RPAREN,         // )
    LBRACE,         // {
    RBRACE,         // }
    LBRACKET,       // [
    RBRACKET,       // ]

    LESS_THAN,      // <
    LESS_EQUAL,     // <=
    GREATER_THAN,   // >
    GREATER_EQUAL,  // >=

    RIGHTARROW, // ->



    INTEGER,    // 1, 2, 3
    INT,        // 정수
    STRING,     // 사과, 배
    STR,        // 문자열




};


#endif //TOL_TOKENTYPE_H
