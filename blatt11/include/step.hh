#ifndef STEP_HH
#define STEP_HH

#include <vector>

template<typename Force, typename Body>
void eulerStep(const Force& force, std::vector<Body>& bodies,
               double t, double dt)
{
    for (std::size_t i = 0; i < bodies.size(); i++)
    {
        bodies[i].acc() = force(bodies, i, dt);
    }

    for(auto& body : bodies)
    {
        body.pos() = body.pos() + body.vel() * dt;
        body.vel() = body.vel() + body.acc() * dt;
    }
}

#endif // STEP_HH