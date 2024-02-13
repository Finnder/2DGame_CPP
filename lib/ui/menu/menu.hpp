#include "RoundedButton.hpp"

class Menu {
    public:
        Menu();

        void addButton(RoundedButton& button);
        void draw(sf::RenderWindow& window);

    private:
        sf::RectangleShape m_shape;
};
