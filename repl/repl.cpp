#include "repl.h"


void Repl::lexerTest() {
    cout << "한글 프로그래밍 언어 TOL" << endl;
    cout << "제작: tolelom, leeju1013, jh-lee-kor" << endl;

    while (true) {
        cout << ">>> ";
        string code;
        getline(cin, code);

        vector<string> characters = utf8Converter.run(code);
        vector<Token*> tokens = lexer.run(characters);

        for (auto token : tokens) {
            token->printTokenType();
        }
    }
}


void Repl::run() {
    cout << "한글 프로그래밍 언어 TOL" << endl;
    cout << "제작: tolelom, leeju1013, jh-lee-kor" << endl;

    while (true) {
        cout << ">>> ";
        string code;
        getline(cin, code);

        vector<string> characters = utf8Converter.run(code);
        vector<Token*> tokens = lexer.run(characters);
    }
}

