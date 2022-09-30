#include "../headers/NotNode.hpp"

NotNode::NotNode(LogicNode* input) {
    input_nodes[0] = input;
    input_nodes[1] = nullptr;
}

bool NotNode::execute() {
    return !input_nodes[0]->execute();
}