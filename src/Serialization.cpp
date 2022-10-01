#include "../headers/Serialization.hpp"

int Serialization::and_count = 0;
int Serialization::not_count = 0;
int Serialization::input_count = 0;
int Serialization::true_count = 0;
int Serialization::false_count = 0;

int Serialization::get_count_from_type(LogicNode* node) {
    if (typeid(*node) == typeid(AndNode)) {
        return and_count;
    } else if (typeid(*node) == typeid(NotNode)) {
        return not_count;
    } else if (typeid(*node) == typeid(TrueNode)) {
        return true_count;
    } else if (typeid(*node) == typeid(FalseNode)) {
        return false_count;
    } else if (typeid(*node) == typeid(InputNode)) {
        return input_count;
    }
    return 0;
}

NodeType Serialization::get_tag_from_type(LogicNode* node) {
    if (typeid(*node) == typeid(AndNode)) {
        return NodeType::AND;
    } else if (typeid(*node) == typeid(NotNode)) {
        return NodeType::NOT;
    } else if (typeid(*node) == typeid(TrueNode)) {
        return NodeType::TRUE;
    } else if (typeid(*node) == typeid(FalseNode)) {
        return NodeType::FALSE;
    } else if (typeid(*node) == typeid(InputNode)) {
        return NodeType::INPUT;
    }
    return NodeType::ERROR_TYPE;
}

void Serialization::serialize_component_recursive(LogicNode* node, std::vector<std::string>& component_strings) {
    if (node == nullptr) {return;}

    NodeType node_type = get_tag_from_type(node);
    NodeType node_child1_type = get_tag_from_type(node->input_nodes[0]);
    NodeType node_child2_type = get_tag_from_type(node->input_nodes[1]);

    int node_child1_count = get_count_from_type(node->input_nodes[0]);
    int node_child2_count = get_count_from_type(node->input_nodes[1]);

    std::stringstream ss;

    if (node_type == NodeType::AND) { // AND
        and_count++;
        
        // "1_and": [""]
        ss << "\"" << and_count << "_and\": [\"" << node_child1_count+1 << "_" << node_child1_type << "\", \"" 
        << node_child2_count+1 << "_" << node_child2_type << "\"]";
        
        component_strings.push_back(ss.str());
        serialize_component_recursive(node->input_nodes[0], component_strings);
        serialize_component_recursive(node->input_nodes[1], component_strings);
    } else if (node_type == NodeType::NOT){ // NOT
        not_count++;
        
        ss << "\"" << not_count << "_and\": [\"" << node_child1_count+1 << "_" << node_child1_type << "\"]";

        component_strings.push_back(ss.str());
        serialize_component_recursive(node->input_nodes[0], component_strings);
    }
}

std::string Serialization::serialize_component(LogicNode* last_node) {
    std::vector<std::string> component_strings;
    serialize_component_recursive(last_node,component_strings);

    std::string output = "[\n";
    for (size_t i = 0; i < component_strings.size(); i++) {
        output += "{" + component_strings[i] + "}";
        if (i != component_strings.size()-1) {
            output += ",";
        }
        output += "\n";
    }
    output += "]";

    and_count = 0;
    not_count = 0;
    input_count = 0;

    return output;
}

LogicNode* Serialization::deserialize_component(std::string json) {
    return nullptr;
}