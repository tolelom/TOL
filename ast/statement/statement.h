#ifndef TOL_STATEMENT_H
#define TOL_STATEMENT_H

#include "../node.h"

class Statement : public Node {
public:
    string String() override = 0;
};

#endif //TOL_STATEMENT_H
