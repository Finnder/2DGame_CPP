#pragma once

#include <SFML/Graphics.hpp>
#include <vector>


class Player {
public:
    Player(float x, float y);

    void update(float deltaTime, const std::vector<sf::RectangleShape>& walls);
    void handleInput(sf::Event event);
    void draw(sf::RenderWindow& window);

private:
    sf::CircleShape m_shape;
    sf::Vector2f m_velocity{ 0.f, 0.f }; 
    sf::Vector2f m_movement{ 0.f, 0.f };
};
