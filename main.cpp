#include <SFML/Graphics.hpp>
#include "./config/config.cpp"
#include <string>

int main()
{
    // Create the game window
    sf::RenderWindow window(sf::VideoMode(window_x, window_y), windowTitle);

    // Set the framerate limit to 60 frames per second
    window.setFramerateLimit(60);

    // Create the player sprite
    sf::RectangleShape player(sf::Vector2f(50, 50));
    player.setFillColor(sf::Color::Red);
    player.setPosition(400, 300);

    float speed = 4.f;

    // Game loop
    while (window.isOpen())
    {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Handle player movement
        sf::Vector2f movement(0.f, 0.f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            movement.y -= speed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            movement.y += speed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            movement.x -= speed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            movement.x += speed;
        }

        player.move(movement);

        // Clear the window
        window.clear();

        // Draw the player
        window.draw(player);

        // Display the window
        window.display();
    }
}

