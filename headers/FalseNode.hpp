#pragma once

#include "LogicNode.hpp"

class FalseNode: public LogicNode {
public:
    bool execute();    
};