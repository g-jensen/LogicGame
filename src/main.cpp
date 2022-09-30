#include "../headers/Game.hpp"

#include "../headers/Nodes.hpp"

#include <iostream>

int main() {
    
    LogicNode* input1 = new FalseNode();
    LogicNode* input2 = new TrueNode();

    LogicNode* not_input1 = new NotNode(input1);
    LogicNode* not_input2 = new NotNode(input2);

    LogicNode* conjunction = new AndNode(not_input1,not_input2);

    LogicNode* not_conjunction = new NotNode(conjunction);

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