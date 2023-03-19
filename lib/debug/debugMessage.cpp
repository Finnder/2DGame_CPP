#include <SFML/Graphics.hpp>
#include <iostream>


void debug_error(sf::String message){
    std::cout << ("\033[0;31m", message, "/033[0;31m") << std::endl;
}

void debug_warning(sf::String message){
    std::cout << ("\033[0;33m", message, "/033[0;33m") << std::endl;
}

void debug_special(sf::String message){
    std::cout << ("\033[0;35m", message, "/033[0;35m") << std::endl;
}