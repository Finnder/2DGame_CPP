#include "projectile.h"

// Config
const float projectileRadius = 5.f;
const sf::Color projectileColor = sf::Color::Red;
const float projectileSpeed = 300.f;


Projectile::Projectile(float x, float y, float directionX, float directionY) {
    m_shape.setRadius(projectileRadius);
    m_shape.setPosition(x, y);
    m_shape.setFillColor(projectileColor);
    m_direction = sf::Vector2f(directionX, directionY);
    m_speed = projectileSpeed;
}

void Projectile::update(float deltaTime, const std::vector<sf::RectangleShape>& walls) {
    sf::Vector2f position = m_shape.getPosition();
    sf::Vector2f newPosition = position + m_direction * m_speed * deltaTime;
    m_shape.setPosition(newPosition);

    // Check for collisions with walls
    for (const auto& wall : walls) {
        sf::FloatRect wallBounds = wall.getGlobalBounds();
        sf::FloatRect projectileBounds = m_shape.getGlobalBounds();

        if (projectileBounds.intersects(wallBounds)) {
            // Collision detected, hide the projectile
            m_shape.setPosition(-2000.f, -2000.f);
            break;
        }
    }
}

void Projectile::draw(sf::RenderWindow& window) {
    window.draw(m_shape);
}
