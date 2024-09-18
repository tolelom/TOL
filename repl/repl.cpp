#include "repl.h"


void Repl::LexerTest() {
    cout << "한글 프로그래밍 언어 TOL" << endl;
    cout << "제작: tolelom, leeju1013, jh-lee-kor" << endl;

    while (true) {
        cout << ">>> ";
        string code;
        getline(cin, code);

        vector<string> characters = utf8_converter.Run(code);
        vector<Token*> tokens = lexer.Run(characters);

        for (auto token : tokens) {
            cout << "Line " << token->line << ": " << token->literal << " " <<Token::PrintTokenType(token->type) << endl;
        }
    }
}


void Repl::Run() {
    cout << "한글 프로그래밍 언어 TOL" << endl;
    cout << "제작: tolelom, leeju1013, jh-lee-kor" << endl;

    while (true) {
        cout << ">>> ";
        string code;
        getline(cin, code);

        vector<string> characters = utf8_converter.Run(code);
        vector<Token*> tokens = lexer.Run(characters);
    }
}

