#include <SFML/Graphics.hpp>
#include <vector>
#include "GameObject.h"
#include "Scene.h"

#pragma once
class Game
{
private:
    sf::RenderWindow &window;
    static Scene *currentScene;
    static Scene *newScene;
    void checkCollisions();
public:
    float deltaTime;

    Game ( sf::RenderWindow &window );

    void update ( float deltaTime );
    void draw();

    sf::RenderWindow &getWindow();
    static Scene *getCurrentScene();
    static void loadScene ( Scene *scene );

    ~Game ( void );
};

