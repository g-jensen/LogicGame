#include "../headers/utils.hpp"

void free_component(LogicNode* last_node) {
    if (last_node == nullptr) {return;}
    free_component(last_node->input_nodes[0]);
    free_component(last_node->input_nodes[1]);
    delete last_node;
}