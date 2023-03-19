#include <SFML/Graphics.hpp>
#include "./config/config.cpp"
#include "./lib/ui.cpp"
#include "./lib/player/player.cpp"
#include <string>
#include <cmath>


int main()
{
    // Create the game window
    sf::RenderWindow window(sf::VideoMode(window_x, window_y), windowTitle);


    sf::Clock clock;
    sf::Time deltaTime; 

    // Set the framerate limit to 60 frames per second
    window.setFramerateLimit(60);

    sf::Font font;
    sf::String mainFont = "./assets/fonts/foundation.ttf";

    if (!font.loadFromFile(mainFont)){
        printf("Err: Loading Font, Loading Default");
    }

    Player player(window.getSize().x / 2, window.getSize().y / 2); 
    
    
    while (window.isOpen())
    {   

        deltaTime = clock.restart();
        float dt = deltaTime.asSeconds();

        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            
            player.handleInput(event);
        }

        player.update(dt);

        // Clear the window
        window.clear();

        player.draw(window);

        create_button(window_x / 2, 100.f, window_y / 4, 50.f, 2.f, "Hello World", font, window);

        // Display the window
        window.display();
    }
}

