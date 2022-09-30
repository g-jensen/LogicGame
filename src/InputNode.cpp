#include "../headers/InputNode.hpp"

InputNode::InputNode(bool value) {
    this->value = value;
    input_nodes[0] = nullptr;
    input_nodes[1] = nullptr;
}

bool InputNode::execute() {
    return value;
}