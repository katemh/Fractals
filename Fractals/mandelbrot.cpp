#include "mandelbrot.h"
#include "complex.h"

const int ESCAPE_RADIUS = 2;

Mandelbrot::Mandelbrot() : limit(ESCAPE_RADIUS)
{
    pixels.setPrimitiveType(sf::PrimitiveType::Points);
}

Mandelbrot::~Mandelbrot()
{

}

void Mandelbrot::pixelsToBrot()
{
    for (float x = 0.f; x < 640.f; ++x) {
        for (float y = 0.f; y < 400.f; ++y) {
            //"mathematical" value of this pixel? as a complex number
            Complex value((centerX + x) * scale, (centerY + y) * scale);
            int count = 0;  //count iterations of loop
            Complex temp = value;
            do {
                temp = temp^2 + value;  //Fc(x) = x^2 + c, Fc(Fc(x)) = ...
                value1 = value2;
                ++i;
            } while (i <= 255 && ((a1 * a1) + (b1 * b1) < limit));

            sf::Vertex pixel(sf::Vector2f(x, y), sf::Color(0, 0, 0, i));
            pixels.append(pixel);
        }
    }
}
