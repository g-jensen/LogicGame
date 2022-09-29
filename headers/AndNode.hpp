#pragma once

#include "LogicNode.hpp"

class AndNode: public LogicNode {
public:
    bool execute();
    std::vector<LogicNode*> input_nodes;
};