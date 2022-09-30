#include "../headers/Game.hpp"
#include "../headers/Nodes.hpp"
#include "../headers/Serialization.hpp"
#include "../headers/utils.hpp"

#include <iostream>
#include <fstream>

#include "../nlohmann-json/single_include/nlohmann/json.hpp"
using json = nlohmann::json;

int main() {
    
    std::ifstream f("test.json");
    json data = json::parse(f);
    std::cout << data[0] << std::endl;

    LogicNode* input1 = new InputNode(true);
    LogicNode* input2 = new InputNode(false);

    LogicNode* not_input1 = new NotNode(input1);
    LogicNode* not_input2 = new NotNode(input2);

    LogicNode* conjunction = new AndNode(not_input1,not_input2);

    LogicNode* not_conjunction = new NotNode(conjunction);

    std::cout << not_conjunction->execute() << std::endl;

    std::cout << Serialization::serialize_component(not_conjunction) << std::endl;

    free_component(not_conjunction);

    // Game game = Game();
    // game.init();
    // game.run();
    // game.cleanup();

    return 0;
}