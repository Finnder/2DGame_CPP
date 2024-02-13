#include <SFML/Graphics.hpp>
#include <vector>
#include "../../config/config.cpp"
#include "stdlib.h"

// We return all of the walls here
std::vector<sf::RectangleShape> get_map(){

    sf::Color borderColor = borderWallColor;
    sf::Color borderOutlineColor = sf::Color::Yellow;

    std::vector<sf::RectangleShape> generated_walls;

    //All Sides blocked

    // Top Wall
    sf::RectangleShape top_wall(sf::Vector2f(window_x, 20));
    top_wall.setFillColor(borderColor);
    top_wall.setOutlineColor(borderOutlineColor);
    top_wall.setOutlineThickness(1);
    top_wall.setPosition(0, 0);    
    generated_walls.push_back(top_wall);

    // Bottom Wall
    sf::RectangleShape bottom_wall(sf::Vector2f(window_x, 20));
    bottom_wall.setFillColor(borderColor);
    bottom_wall.setOutlineColor(borderOutlineColor);
    bottom_wall.setOutlineThickness(1);
    bottom_wall.setPosition(0, window_y - 20);    
    generated_walls.push_back(bottom_wall);

    // Middle Wall Area
    sf::RectangleShape middle_wall(sf::Vector2f(20, 100));
    middle_wall.setFillColor(borderColor);
    middle_wall.setOutlineColor(borderOutlineColor);
    middle_wall.setOutlineThickness(1);
    middle_wall.setPosition(10 + rand() % 100 + 1, 300);
    generated_walls.push_back(middle_wall);

    return generated_walls;
}
