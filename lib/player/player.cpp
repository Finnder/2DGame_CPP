#include "player.h"
#include <cmath>
#include <vector>



// Movement
float playerSpeed = 1000.f;
float smoothingFactor = 0.2f;
float acceleration = 10000.f;
float deceleration = 2000.f; // Lower means more slide, higher means less and quicker stop

// temp
bool can_shoot = false;


float copy_sign(float x, float y) {
    return (y < 0.f) ? -std::abs(x) : std::abs(x);
}

Player::Player(float x, float y) {
    m_shape.setRadius(20.f);
    m_shape.setPosition(x, y);
    m_shape.setFillColor(playerColor);
}

void Player::createProjectile() {
    float x = m_shape.getPosition().x + m_shape.getRadius();
    float y = m_shape.getPosition().y + m_shape.getRadius();
    m_projectiles.emplace_back(x, y, m_movement.x, m_movement.y);
}

void Player::update(float deltaTime, const std::vector<sf::RectangleShape>& walls) {

    sf::Vector2f position = m_shape.getPosition();
    sf::Vector2f previousPosition = position;

    // Update movement velocity based on acceleration and deceleration
    if (m_movement.x != 0.f) {
        m_velocity.x += acceleration * m_movement.x * deltaTime;
    } else {
        m_velocity.x -= copy_sign(deceleration * deltaTime, m_velocity.x);
        if (std::abs(m_velocity.x) < 1.f) {
            m_velocity.x = 0.f;
        }
    }

    if (m_movement.y != 0.f) {
        m_velocity.y += acceleration * m_movement.y * deltaTime;
    } else {
        m_velocity.y -= copy_sign(deceleration * deltaTime, m_velocity.y);
        if (std::abs(m_velocity.y) < 1.f) {
            m_velocity.y = 0.f;
        }
    }

    // Clamp velocity to playerSpeed
    float speed = std::sqrt(m_velocity.x * m_velocity.x + m_velocity.y * m_velocity.y);

    if (speed > playerSpeed) {
        m_velocity.x *= playerSpeed / speed;
        m_velocity.y *= playerSpeed / speed;
    }

    // Apply smoothing and update position
    sf::Vector2f targetPosition = position + m_velocity * deltaTime;
    position.x = position.x + smoothingFactor * (targetPosition.x - position.x);
    position.y = position.y + smoothingFactor * (targetPosition.y - position.y);
    m_shape.setPosition(position);

    // Collision Checking
    for (const auto& wall : walls) {
        sf::FloatRect wallBounds = wall.getGlobalBounds();
        sf::FloatRect playerBounds = m_shape.getGlobalBounds();

        if (playerBounds.intersects(wallBounds)) {
            // Collision detected, revert the player's position to the previous position
            m_shape.setPosition(previousPosition);
            break; // No need to check further collisions as the player's position is already reverted
        }
    } 


     // Update projectiles
    for (auto& projectile : m_projectiles) {
        projectile.update(deltaTime, walls);
    }
}


void Player::handleInput(sf::Event event) {

   if (event.type == sf::Event::KeyPressed) {

       // Space - Shoots Projectile
        if (event.key.code == sf::Keyboard::Space) {
            if (can_shoot){
                createProjectile();
            }
        }

        if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W) {
            m_movement.y = -1.f;
            can_shoot = true;
        }
         
        if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S) {
            m_movement.y = 1.f;
            can_shoot = true;
        }

        if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A) {
            m_movement.x = -1.f;
            can_shoot = true;
        }
         
        if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D) {
            m_movement.x = 1.f;
            can_shoot = true;
        }
    } else if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::S) {
            m_movement.y = 0.f;
        } if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::D) {
            m_movement.x = 0.f;
        }
    } 
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(m_shape);

    for (auto& projectile : m_projectiles) {
        projectile.draw(window);
    }
}
