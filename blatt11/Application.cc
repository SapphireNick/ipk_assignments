#include "sdlwrapper.hh"
#include "body.hh"
#include "step.hh"
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
    canv.clear();

    while(!canv.windowClosed())
    {
        displayBodies(&canv, bodies);
        auto force = [](const auto& bodies, int i, double dt){
            return Point(0, 0);
        };
        eulerStep(force, bodies, 1, 0.001);
    }
}

void displayBodies(SDLCanvas* canvas, std::vector<Body> bodies)
{
    for (auto& body : bodies)
    {
        canvas->drawPixel(body.pos().x() + 0.5 * 1024, body.pos().y() + 0.5 * 768, body.colors());
    }
    canvas->display();
}