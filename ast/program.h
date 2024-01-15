#ifndef TOL_PROGRAM_H
#define TOL_PROGRAM_H

#include <vector>
#include "node.h"
#include "statement/statement.h"

class Program : public Node {
public:
    vector<Statement*> statements;

    string String() override {
        string s;
        for (auto& statement : statements) {
            s += statement->String() + "\n";
        }
        return s;
    }
};


#endif //TOL_PROGRAM_H
