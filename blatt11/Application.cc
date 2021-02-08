#include "sdlwrapper.hh"
#include "body.hh"
#include <vector>
#include <string>

void displayBodies(SDLCanvas* canvas, std::vector<Body> bodies);

int main()
{
    SDLCanvas canv("MKV", 1024, 768);
    std::vector<Body> bodies =  {
        {{   0.,   0.}, {   0., 0.},  1e3, {255,   0,   0}},
        {{ 100.,   0.}, {   0., 0.3}, 10., {  0, 255,   0}},
        {{-200.,   0.}, {   0., 0.2}, 10., {  0,   0, 255}},
        {{   0., 250.}, {-0.25, 0.},  10., {255, 255,   0}},
    };

    while(!canv.windowClosed())
    {
        displayBodies(&canv, bodies);
    }
}

void displayBodies(SDLCanvas* canvas, std::vector<Body> bodies)
{
    for (auto& body : bodies)
    {
        canvas->drawPixel(body.pos().x(), body.pos().y(), body.colors());
    }
    canvas->display();
}