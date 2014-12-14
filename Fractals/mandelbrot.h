#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <cmath>
#include <SFML/Graphics.hpp>

class Mandelbrot
{
public:
    Mandelbrot();
    ~Mandelbrot();


private:
    float cx, cy;   //center x and iy coordinates
    float scale;    //scale factor
    const float limit;    //limit used to determine if c belongs to Mandelbrot set
    sf::VertexArray pixels;
};

#endif // MANDELBROT_H
