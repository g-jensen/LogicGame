#include "../headers/Serialization.hpp"

int Serialization::and_count = 0;
int Serialization::not_count = 0;
int Serialization::input_count = 0;

void Serialization::serialize_component_recursive(LogicNode* node, std::vector<std::string>& component_strings) {
    if (node == nullptr) {return;}

    std::stringstream ss;

    if (typeid(*node->input_nodes[0]) == typeid(InputNode)) {
        if (typeid(*node) == typeid(AndNode)) {
            ss << "\"" << and_count+1 << "_and\": [\"" << input_count+1 << "_INPUT\"]";
        } else if (typeid(*node) == typeid(NotNode)) {
            ss << "\"" << not_count+1 << "_and\": [\"" << input_count+1 << "_INPUT\"]";
        }
        input_count++;
        component_strings.push_back(ss.str());
        
        return;
    }

    if (typeid(*node) == typeid(AndNode)) {
        and_count++;
        
        ss << "\"" << and_count << "_and\": [\"";
        if (typeid(*node->input_nodes[0]) == typeid(AndNode)) {
            if (typeid(*node->input_nodes[1]) == typeid(AndNode)) {
                ss << and_count+1 << "_and\", " << and_count+2 << "_and\"]";
            } else if (typeid(*node->input_nodes[1]) == typeid(NotNode)) {
                ss << and_count+1 << "_and\", " << not_count+1 << "_not\"]";
            }
        } else if (typeid(*node->input_nodes[0]) == typeid(NotNode)) {
            if (typeid(*node->input_nodes[1]) == typeid(AndNode)) {
                ss << not_count+1 << "_not\", " << and_count+1 << "_and\"]";
            } else if (typeid(*node->input_nodes[1]) == typeid(NotNode)) {
                ss << not_count+1 << "_not\", " << not_count+2 << "_not\"]";
            }
        }
        
        component_strings.push_back(ss.str());
        serialize_component_recursive(node->input_nodes[0], component_strings);
        serialize_component_recursive(node->input_nodes[1], component_strings);
    } else if (typeid(*node) == typeid(NotNode)){
        not_count++;

        ss << "\"" << not_count << "_not\": [\"";
        if (typeid(*node->input_nodes[0]) == typeid(AndNode)) {
            ss << and_count+1 << "_and\"]";
        } else if (typeid(*node->input_nodes[0]) == typeid(NotNode)) {
            ss << not_count+1 << "_not\"]";
        }

        component_strings.push_back(ss.str());
        serialize_component_recursive(node->input_nodes[0], component_strings);
    }
}

std::string Serialization::serialize_component(LogicNode* last_node) {
    std::vector<std::string> component_strings;
    serialize_component_recursive(last_node,component_strings);

    std::string output = "{\n";
    for (size_t i = 0; i < component_strings.size(); i++) {
        output += component_strings[i];
        if (i != component_strings.size()-1) {
            output += ",";
        }
        output += "\n";
    }
    output += "}";

    and_count = 0;
    not_count = 0;
    input_count = 0;

    return output;
}