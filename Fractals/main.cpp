#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode, "Fractals - Mandelbrot Set");
    window->setSize(sf::Vector2u(640, 400));

    while (window->isOpen) {
        sf::Event event;
        window->pollEvent(event);

    }

    cout << "Hello World!" << endl;
    return 0;
}

