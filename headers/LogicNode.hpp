#pragma once

#include <vector>

class LogicNode {
public:
    virtual bool execute() = 0;
    LogicNode* input_nodes[2];
};