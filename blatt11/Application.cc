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

    Point center_of_grav = Point();

    double total_mass = 0;
    for(auto& b : bodies) total_mass += b.mass();

    const double grav_const = 0.01;

    while(!canv.windowClosed())
    {
        displayBodies(&canv, bodies);

        auto force = [grav_const](const auto& bodies, int i, double dt){
            Point tmp = Point(0, 0);
            double x, y, dist, mass = 0;

            for (std::size_t j = 0; j < bodies.size(); j++)
            {
                if(i == (int) j) continue;

                dist = std::sqrt(std::pow((bodies[j].pos() + bodies[i].pos()).x(), 2) + std::pow((bodies[j].pos() + bodies[i].pos()).y(), 2));
                x = (bodies[j].pos().x() - bodies[i].pos().x()) * (1 / std::pow(dist, 3));
                y = (bodies[j].pos().y() - bodies[i].pos().y()) * (1 / std::pow(dist, 3));
                mass += bodies[j].mass();
                tmp += Point(x, y);
            }
            return (grav_const * (mass-bodies[i].mass()) * tmp);
        };

        eulerStep(force, bodies, 1, 1);

        for(auto& body : bodies)
        {
            center_of_grav += body.mass() * body.pos();
        }
        center_of_grav *= 1 / total_mass;

        for(auto& b : bodies)
        {
            b.pos() -= center_of_grav;
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