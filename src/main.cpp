#include "../headers/Game.hpp"

#include "../headers/Nodes.hpp"

#include <iostream>

int main() {
    
    LogicNode* input1 = new TrueNode();
    LogicNode* input2 = new FalseNode();

    LogicNode* out = new AndNode();
    out->input_nodes.push_back(input1);
    out->input_nodes.push_back(input2);

    std::cout << out->execute() << std::endl;

    delete input1;
    delete input2;
    delete out;

    // Game game = Game();
    // game.init();
    // game.run();
    // game.cleanup();

    return 0;
}