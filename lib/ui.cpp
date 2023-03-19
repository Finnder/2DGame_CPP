#include <SFML/Graphics.hpp>


// Custom Rounded Button - Text,Rounded
void create_button(float posX, float posY, float width, float height, float radius, sf::String btn_txt, sf::Font mainFont, sf::RenderWindow& window){

    // Create the button
    sf::ConvexShape button;
    button.setPointCount(8); // Set the number of points

    button.setFillColor(sf::Color::Blue);
    button.setOutlineThickness(2.f);
    button.setOutlineColor(sf::Color::White);

    // Calculate the positions of the points
    for (int i = 0; i < 4; ++i)
    {
        // Top left corner
        button.setPoint(0, sf::Vector2f(posX - width / 2.f + radius, posY - height / 2.f));
        button.setPoint(1, sf::Vector2f(posX + width / 2.f - radius, posY - height / 2.f));
        button.setPoint(2, sf::Vector2f(posX + width / 2.f, posY - height / 2.f + radius));
        button.setPoint(3, sf::Vector2f(posX + width / 2.f, posY + height / 2.f - radius));
        button.setPoint(4, sf::Vector2f(posX + width / 2.f - radius, posY + height / 2.f));
        button.setPoint(5, sf::Vector2f(posX - width / 2.f + radius, posY + height / 2.f));
        button.setPoint(6, sf::Vector2f(posX - width / 2.f, posY + height / 2.f - radius));
        button.setPoint(7, sf::Vector2f(posX - width / 2.f, posY - height / 2.f + radius));
    }

    sf::Text text(btn_txt, mainFont, 16);
    text.setFillColor(sf::Color::White);

    // Calculate the center of the shape
    sf::FloatRect shapeBounds = button.getGlobalBounds();
    sf::Vector2f shapeCenter(shapeBounds.left + shapeBounds.width / 2.f, shapeBounds.top + shapeBounds.height / 2.f);

    // Center the text within the shape
    sf::FloatRect textBounds = text.getLocalBounds();
    text.setOrigin(textBounds.left + textBounds.width / 2.f, textBounds.top + textBounds.height / 2.f);
    text.setPosition(shapeCenter);

    window.draw(button);
    window.draw(text);
}