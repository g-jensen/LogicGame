#pragma once

#include "LogicNode.hpp"

class InputNode: public LogicNode {
public:
    InputNode(bool value);
    bool execute();
    bool value;
};