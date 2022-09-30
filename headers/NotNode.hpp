#pragma once

#include "LogicNode.hpp"

class NotNode: public LogicNode {
public:
    NotNode(LogicNode* input);
    bool execute();
};