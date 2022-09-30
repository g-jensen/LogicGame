#include "../headers/NotNode.hpp"

NotNode::NotNode(LogicNode* input) {
    input_nodes[0] = input;
}

bool NotNode::execute() {
    return !input_nodes[0]->execute();
}