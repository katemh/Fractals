#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <cmath>
#include <SFML/Graphics.hpp>

class Mandelbrot
{
public:
    Mandelbrot();
    ~Mandelbrot();
    void run();

private:
    int cx, cy;       //center x and iy coordinates
    float scale;        //scale factor
    const int limit;    //limit used to determine if c belongs to Mandelbrot set
    bool scan;
    sf::RenderWindow window;
    sf::View view;
    sf::VertexArray pixels;
    sf::Vector2f scanBy;

    void init();
    void processEvents();
    void render();

    void setCenter(sf::Vector2i new_center);
};

#endif // MANDELBROT_H
