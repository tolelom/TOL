#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "../node.h"

class Expression : public Node {
public:
    string String() override = 0;
};

#endif //EXPRESSION_H
