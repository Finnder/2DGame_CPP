#include "RoundedButton.hpp"

RoundedButton::RoundedButton(float width, float height, const std::string& text, const sf::Font& font, unsigned int fontSize)
{
    m_rectangle.setSize(sf::Vector2f(width, height));
    m_rectangle.setFillColor(sf::Color(150, 150, 150));

    m_text.setString(text);
    m_text.setFont(font);
    m_text.setCharacterSize(fontSize);
    m_text.setFillColor(sf::Color::Black);

    sf::FloatRect textBounds = m_text.getLocalBounds();
    m_text.setOrigin(textBounds.left + textBounds.width / 2.f, textBounds.top + textBounds.height / 2.f);
    m_text.setPosition(width / 2.f, height / 2.f);
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
