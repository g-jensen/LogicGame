#pragma once

#include <vector>

class LogicNode {
public:
    virtual bool execute() = 0;
    std::vector<LogicNode*> input_nodes;
};