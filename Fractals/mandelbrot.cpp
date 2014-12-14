#include "mandelbrot.h"
#include "complex.h"

const int ESCAPE_RADIUS = 2;        //escape radius
const float WINDOW_WIDTH = 640;     //in pixels
const float WINDOW_HEIGHT = 400;    //in pixels

Mandelbrot::Mandelbrot() : cx(WINDOW_WIDTH / 2), cy(WINDOW_HEIGHT / 2),
    scale(0.02f), limit(ESCAPE_RADIUS)
{
    //intentionally left blank
} //end constructor

Mandelbrot::~Mandelbrot()
{
    //use default destructor; no dynamic or ptr variables
} //end destructor

void Mandelbrot::run() {
    init();
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Mandelbrot::init()
{
    //create window
    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Mandelbrot Set");

    //initialize view and viewport with default center and scale values
    view.setCenter(cx, cy);
    view.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    view.setViewport(sf::FloatRect(0, 0, 1.f, 1.f));

    pixels.setPrimitiveType(sf::PrimitiveType::Points);

} //end init

void Mandelbrot::processEvents()
{
    sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
    sf::Vector2f mouse_update;
    sf::Event event;
    while(window->pollEvent(event)) {
       switch(event.type) {
       case sf::Event::Closed:
           window->close();
           break;
       case sf::Event::MouseButtonPressed: {
           if(event.mouseButton.button == sf::Mouse::Left) {
               mouse_position.x = event.mouseButton.x;
               mouse_position.y = event.mouseButton.y;
           }
           break;
       }
       case sf::Event::MouseMoved: {
           if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
              mouse_update.x = event.mouseMove.x - mouse_position.x;
              mouse_update.y = event.mouseMove.y - mouse_position.y;
              view.move(mouse_update);
           }
       }
       case sf::Event::KeyPressed: {
           switch(event.key.code) {
           //------------------------------------------------------ zoom in/out
           case sf::Keyboard::Subtract: //zoom out
               break;
           default:
               break;
           } //end switch
       }
       default:
           break;
       } //end switch
    } //end while-loop
}

void Mandelbrot::render()
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
