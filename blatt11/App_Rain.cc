#include "sdlwrapper.hh"
#include "io.hh"
#include "body.hh"
#include "step.hh"
#include <vector>
#include <string>

void displayBodies(SDLCanvas* canvas, std::vector<Body> bodies);

int main()
{
    SDLCanvas canv("MKV", 1024, 768);

    const double grav_const = 0.01;

    std::vector<Body> bodies;
    std::vector<double> xPos = uniform_distribution(random_seed(), 10000, -0.5 * 1024, 0.5 * 1024);
    std::vector<double> yPos = uniform_distribution(random_seed(), 10000, 0, 768);
    for(auto& e : yPos)
    {
        e *= e / 768;
    }

    for(int i = 0; i < 10000; i++)
    {
        bodies.push_back(Body({xPos[i], yPos[i] - 0.5 * 768}, {0, std::sqrt(2 * yPos[i] * grav_const)}, 1, {200, 225, 255}));
    }

    canv.clear();

    double total_mass = 0;
    for(auto& b : bodies) total_mass += b.mass();

    while(!canv.windowClosed())
    {
        displayBodies(&canv, bodies);

        auto force = [grav_const](const auto& bodies, int i, double dt){
            return Point(0, grav_const);
        };

        eulerStep(force, bodies, 1, 0.1);

        for(auto& body : bodies)
        {
            if(body.pos().y() >= 0.5 * 768)
            {
                double x = body.pos().x();
                body.pos() = {x, -0.5*768};
                body.vel() = {0, 0};
            }
        }

        canv.clear(std::array<int, 3>{0, 0, 0});
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