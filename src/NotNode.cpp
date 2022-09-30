#include "../headers/NotNode.hpp"

bool NotNode::execute() {
    return !input_nodes[0]->execute();
}