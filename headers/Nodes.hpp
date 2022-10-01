#pragma once

#include "LogicNode.hpp"
#include "TrueNode.hpp"
#include "FalseNode.hpp"
#include "AndNode.hpp"
#include "NotNode.hpp"
#include "InputNode.hpp"

enum NodeType {
    TRUE,
    FALSE,
    AND,
    NOT,
    INPUT,
    ERROR_TYPE
};