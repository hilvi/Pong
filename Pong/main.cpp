#include <SFML/Graphics.hpp>
#include "Game.h"

#include <cstdlib>
#include <ctime>


int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 400), "Pong");
    
	Game game(window);
	sf::Clock clock;

	std::srand(std::time(NULL));

    while (window.isOpen())
    {
		

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

		game.update(clock.restart().asSeconds());
		game.draw();
    }

    return 0;
}