#ifndef STEP_HH
#define STEP_HH

#include <vector>
#include <iostream>

template<typename Force, typename Body>
void eulerStep(const Force& force, std::vector<Body>& bodies,
               double t, double dt)
{
    double total_mass = 0;
    Point center_of_grav = Point();
    for (auto& b : bodies)
    {
        total_mass += b.mass();
    }

    for (std::size_t i = 0; i < bodies.size(); i++)
    {
        bodies[i].acc() = force(bodies, i, dt);
    }

    for(std::size_t i = 0; i < bodies.size(); i++)
    {
        for(auto& b : bodies) center_of_grav += b.mass() * b.pos();
        center_of_grav *= 1/total_mass;

        bodies[i].pos() = (bodies[i].pos() + bodies[i].vel() * dt) - center_of_grav;
        bodies[i].vel() = bodies[i].vel() + bodies[i].acc() * dt;
    }
}

#endif // STEP_HH