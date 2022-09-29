#include "../headers/FalseNode.hpp"

#include <iostream>

bool FalseNode::execute() {
    std::cout << "false" << std::endl;
    return false;
}