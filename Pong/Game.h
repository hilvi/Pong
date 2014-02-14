#include <SFML/Graphics.hpp>
#include <vector>
#include "GameObject.h"
#include "Scene.h"

#pragma once
class Game
{
private:
    sf::RenderWindow &window;
    Scene *currentScene;
    Scene *newScene;
    static Game *instance;
    void checkCollisions();
public:
    float deltaTime;

    Game(sf::RenderWindow &window);

    void update(float deltaTime);
    void draw();

    static Scene *getCurrentScene();
    static void loadScene(Scene *scene);
    static sf::RenderWindow &getWindow();

    ~Game(void);
};

