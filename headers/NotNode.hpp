#pragma once

#include "LogicNode.hpp"

class NotNode: public LogicNode {
public:
    bool execute();
};