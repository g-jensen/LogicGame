#pragma once

#include "../headers/Nodes.hpp"

#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

class Serialization {
public:
    static std::string serialize_component(LogicNode* last_node);
    static LogicNode* deserialize_component(std::string json);
private:
    static int get_count_from_type(LogicNode* node);
    static NodeType get_tag_from_type(LogicNode* node);
    static void serialize_component_recursive(LogicNode* node, std::vector<std::string>& component_strings);
    static int and_count;
    static int not_count;
    static int input_count;
    static int true_count;
    static int false_count;
};