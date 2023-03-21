#include <SFML/Graphics.hpp>
#include <vector>
#include "../../config/config.cpp"

// We return all of the walls here
std::vector<sf::RectangleShape> get_map(){

    sf::Color borderColor = sf::Color::White;
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

    sf::RectangleShape bottom_wall(sf::Vector2f(window_x, 20));
    bottom_wall.setFillColor(borderColor);
    bottom_wall.setOutlineColor(borderOutlineColor);
    bottom_wall.setOutlineThickness(1);
    bottom_wall.setPosition(0, window_y);    
    generated_walls.push_back(bottom_wall);

    return generated_walls;
}
