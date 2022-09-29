#pragma once

#include "LogicNode.hpp"

class TrueNode: public LogicNode {
public:
    bool execute();    
    std::vector<LogicNode*> input_nodes;
};