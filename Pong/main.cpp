#include <SFML/Graphics.hpp>
#include "Game.h"

#include <cstdlib>
#include <ctime>

#include "BreakoutLevel1.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 400), "Pong");

    Game game(window);
    sf::Clock clock;
    float accumulator = 0;
    const float dt = 0.01;

    srand(std::time(NULL));

    game.loadScene(new BreakoutLevel1);

    while(window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }

        accumulator += clock.restart().asSeconds();

        while(accumulator >= dt) {
            game.update(dt);
            accumulator -= dt;
        }

        game.draw();
    }

    return 0;
}
