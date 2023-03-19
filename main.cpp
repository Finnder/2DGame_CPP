#include <SFML/Graphics.hpp>
#include "./config/config.cpp"
#include "./lib/player/player.cpp"
#include "./lib/ui/button/RoundedButton.cpp"
#include "./lib/debug/debugMessage.cpp"
#include <string>
#include <cmath>
#include <vector>


int main()
{
    // Create the game window
    sf::RenderWindow window(sf::VideoMode(window_x, window_y), windowTitle);


    sf::Clock clock;
    sf::Time deltaTime; 

    window.setFramerateLimit(60);

    sf::Font font;
    sf::String mainFont = "./assets/fonts/foundation.ttf";

    if (!font.loadFromFile(mainFont)){
        printf("Err: Loading Font, Loading Default");
    }

    Player player(window.getSize().x / 2, window.getSize().y / 2); // Starts player at center
    
    // UI
    RoundedButton play_button(200, 50, "PLAY", font);
    RoundedButton options_button(200, 50, "OPTIONS", font);
    RoundedButton quit_button(200, 50, "QUIT", font);
    
    play_button.setFillColor(sf::Color::Green);
    options_button.setFillColor(sf::Color::Cyan);
    quit_button.setFillColor(sf::Color::Red);

    play_button.setPosition(window.getSize().x / 2, 200);
    options_button.setPosition(window.getSize().x / 2, 270);
    quit_button.setPosition(window.getSize().x / 2, 340);


    // Environment
    std::vector<sf::RectangleShape> walls;
    sf::RectangleShape wall1(sf::Vector2f(100, 100));
    wall1.setFillColor(sf::Color::Blue);
    wall1.setPosition(300, 250);
    walls.push_back(wall1);

    sf::RectangleShape wall2(sf::Vector2f(100, 100));
    wall2.setFillColor(sf::Color::Blue);
    wall2.setPosition(500, 350);
    walls.push_back(wall2);

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

        player.draw(window);

        // Draw Walls
        for (const auto& wall : walls) {
            window.draw(wall);
        }

        //window.draw(play_button);
        //window.draw(options_button);
        //window.draw(quit_button);


        // Display the window
        window.display();
    }
}

