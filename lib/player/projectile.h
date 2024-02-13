class Projectile {
    public:
        Projectile(float x, float y, float directionX, float directionY);

        void update(float deltaTime, const std::vector<sf::RectangleShape>& walls);
        void draw(sf::RenderWindow& window);

    private:
        sf::CircleShape m_shape;
        sf::Vector2f m_direction;
        float m_speed;
};

