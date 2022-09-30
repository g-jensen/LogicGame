#include "../headers/AndNode.hpp"

bool AndNode::execute() {
    bool a = input_nodes[0]->execute();
    bool b = input_nodes[1]->execute();
    return a && b;
}