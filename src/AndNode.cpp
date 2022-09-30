#include "../headers/AndNode.hpp"

AndNode::AndNode(LogicNode* input1, LogicNode* input2) {
    input_nodes[0] = input1;
    input_nodes[1] = input2;
}

bool AndNode::execute() {
    bool a = input_nodes[0]->execute();
    bool b = input_nodes[1]->execute();
    return a && b;
}