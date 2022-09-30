#pragma once

#include "../headers/Nodes.hpp"

#include <string>
#include <vector>
#include <sstream>

class Serialization {
public:
    static std::string serialize_component(LogicNode* last_node);
private:
    static void serialize_component_recursive(LogicNode* node, std::vector<std::string>& component_strings);
    static int and_count;
    static int not_count;
    static int input_count;
};