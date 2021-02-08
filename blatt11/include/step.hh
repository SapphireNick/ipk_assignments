#ifndef STEP_HH
#define STEP_HH

#include <vector>

template<typename Force, typename Body>
void eulerStep(const Force& force, std::vector<Body>& bodies,
               double t, double dt)
{
    for(std::size_t i = 0; i < bodies.size(); i++)
    {
        bodies[i].pos() = bodies[i].pos() * t + bodies[i].vel() * (t + dt);
        bodies[i].vel() = bodies[i].vel() * t + force(bodies, i, dt) * dt;
        t += dt;
    }
}

#endif // STEP_HH