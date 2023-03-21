#include "projectile.cpp"

class Player {
public:
    Player(float x, float y);

    void update(float deltaTime, const std::vector<sf::RectangleShape>& walls);
    void handleInput(sf::Event event);
    void draw(sf::RenderWindow& window);

private:
    void createProjectile();

    sf::CircleShape m_shape;
    sf::Vector2f m_movement;
    sf::Vector2f m_velocity;
    std::vector<Projectile> m_projectiles;
};

