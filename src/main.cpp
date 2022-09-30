#include "../headers/Game.hpp"

#include "../headers/Nodes.hpp"

#include <iostream>

int main() {
    
    LogicNode* input1 = new FalseNode();
    LogicNode* input2 = new TrueNode();

    LogicNode* not_input1 = new NotNode();
    not_input1->input_nodes[0] = input1;
    LogicNode* not_input2 = new NotNode();
    not_input2->input_nodes[0] = input2;

    LogicNode* conjunction = new AndNode();
    
    conjunction->input_nodes[0] = not_input1;
    conjunction->input_nodes[1] = not_input2;

    LogicNode* not_conjunction = new NotNode();
    not_conjunction->input_nodes[0] = conjunction;

    std::cout << not_conjunction->execute() << std::endl;

    delete input1;
    delete input2;
    delete not_input1;
    delete not_input2;
    delete conjunction;
    delete not_conjunction;

    // Game game = Game();
    // game.init();
    // game.run();
    // game.cleanup();

    return 0;
}