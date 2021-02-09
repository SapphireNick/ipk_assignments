#ifndef STEP_HH
#define STEP_HH

#include <vector>
#include <iostream>

template<typename Force, typename Body>
void eulerStep(const Force& force, std::vector<Body>& bodies,
               double t, double dt)
{
    for (std::size_t i = 0; i < bodies.size(); i++)
    {
        bodies[i].acc() = force(bodies, i, dt);
    }

    for(std::size_t i = 0; i < bodies.size(); i++)
    {
        bodies[i].pos() = bodies[i].pos() + bodies[i].vel() * dt;
        bodies[i].vel() = bodies[i].vel() + bodies[i].acc() * dt;
    }
}

#endif // STEP_HH