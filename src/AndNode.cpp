#include "../headers/AndNode.hpp"
#include <iostream>

bool AndNode::execute() {
    std::cout << "greg" << std::endl;
    bool a = input_nodes[0]->execute();
    bool b = input_nodes[1]->execute();
    //std::cout << (a ? "true" : "false") << "," << (b ? "true" : "false") <<std::endl;
    return true;
}