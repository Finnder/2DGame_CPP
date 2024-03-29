#include <SFML/Graphics.hpp>
#include "./config/config.h"
#include "./lib/player/player.cpp"
#include "./lib/debug/debugMessage.cpp"
#include "./lib/envirement/map.cpp"
#include "./lib/ui/menu/menu.hpp"
#include <string>
#include <cmath>
#include <vector>


int main()
{
    // Create the game window
    sf::RenderWindow window(sf::VideoMode(window_x, window_y), windowTitle);

    sf::Clock clock;
    sf::Time deltaTime; 

    window.setFramerateLimit(120);


    sf::Font font;
    sf::String mainFont = "./assets/fonts/foundation.ttf";


    if (!font.loadFromFile(mainFont)){
        printf("Err: Loading Font, Loading Default");
    }

    Player player(window.getSize().x / 2, window.getSize().y / 2); // Starts player at center

    // BG
    sf::RectangleShape background;
    background.setFillColor(backgroundColor);
    background.setSize(sf::Vector2f(window_x, window_y));
    background.setOrigin(0, 0);

    // Environment
    std::vector<sf::RectangleShape> walls = get_map();

    // UI
    Menu menu;
    RoundedButton button(150, 50, 200, 200, "Play", font, 30);

    while (window.isOpen())
    {   
        deltaTime = clock.restart();
        float dt = deltaTime.asSeconds();

        sf::Event event;

        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed) { window.close(); }
            player.handleInput(event);
        }

        player.update(dt, walls);

        // Clear the window
        window.clear();

        window.draw(background);
        player.draw(window);
        window.draw(button);

        // Draw Walls
        for (const auto& wall : walls)
            window.draw(wall);


        // Display the window
        window.display();
    }
}

