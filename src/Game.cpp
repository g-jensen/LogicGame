#include "../headers/Game.hpp"

void Game::init() {
    ;
}

void Game::run() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Logic Game");
    sf::Event event;
    
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);

        // window.draw(...);

        window.display();
    }
}

void Game::cleanup() {
    ;
}