#pragma once

#include "LogicNode.hpp"

class FalseNode: public LogicNode {
public:
    bool execute();    
    std::vector<LogicNode*> input_nodes;
};