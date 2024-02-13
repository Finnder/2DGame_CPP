#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class RoundedButton : public sf::Drawable, public sf::Transformable {
public:
    RoundedButton(float width, float height, float size_x, float size_y, const std::string& text, const sf::Font& font, unsigned int fontSize = 30);

    void setFillColor(const sf::Color& color);
    bool contains(float x, float y) const;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::RectangleShape m_rectangle;
    sf::Text m_text;
};
