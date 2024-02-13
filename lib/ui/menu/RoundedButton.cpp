
#include "RoundedButton.hpp"


RoundedButton::RoundedButton(float width, float height, float pos_x, float pos_y, const std::string& text, const sf::Font& font, unsigned int fontSize)
{
    m_rectangle.setSize(sf::Vector2f(width, height));
    m_rectangle.setFillColor(sf::Color(150, 150, 150));
    m_rectangle.setPosition(pos_x, pos_y);

    m_text.setString(text);
    m_text.setFont(font);
    m_text.setCharacterSize(fontSize);
    m_text.setFillColor(sf::Color::Black);

    sf::FloatRect textBounds = m_text.getLocalBounds();
    m_text.setOrigin(textBounds.left + textBounds.width / 2.f, textBounds.top + textBounds.height / 2.f);
    m_text.setPosition(pos_x + width / 2, pos_y + height / 2);
}

void RoundedButton::setFillColor(const sf::Color& color)
{
    m_rectangle.setFillColor(color);
}

bool RoundedButton::contains(float x, float y) const
{
    return m_rectangle.getGlobalBounds().contains(x, y);
}

void RoundedButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_rectangle, states);
    target.draw(m_text, states);
}
