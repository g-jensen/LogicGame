#include "../headers/InputNode.hpp"

InputNode::InputNode(bool value) {
    this->value = value;
}

bool InputNode::execute() {
    return value;
}