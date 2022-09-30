#pragma once

#include "LogicNode.hpp"

class AndNode: public LogicNode {
public:
    AndNode(LogicNode* input1, LogicNode* input2);
    bool execute();
};