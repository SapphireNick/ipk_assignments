#include "sdlwrapper.hh"
#include "point.hh"
#include "body.hh"
#include <vector>

int width{1600}, height{900};

template<typename Force, typename Body>
void eulerStep(const Force& force, std::vector<Body>& bodies, double t, double dt)
{
	for (int i = 0; i < bodies.size(); ++i) {
		bodies[i].a() = force(bodies, i, dt);
	}
	for (auto&& b : bodies) {
		b.x() = b.x() + b.v() * dt;
		b.v() = b.v() + b.a() * dt;
	}
}

template<typename Body>
void displayBodies(SDLCanvas& canvas, std::vector<Body>& bodies)
{
	for (auto&& b : bodies) {
		canvas.drawPixel(b.x().x() + 0.5 * width, b.x().y() + 0.5 * height, b.c());
	}
	canvas.display();
}

int main(int argc, char** argv)
{
	SDLCanvas canvas{"nbody", width, height};
	canvas.clear();

	std::vector<Body> bv{
		{{0, 0}, {0, 0}, 1e3, {255, 0, 0}},
		{{100, 0}, {0, 0.3}, 10, {0, 255, 0}},
		{{-200, 0}, {0, 0.2}, 10, {0, 0, 255}},
		{{0, 250}, {-0.25, 0}, 10, {255, 255, 0}},
	};

	auto force = [](const auto& bodies, int i, double dt)
	{
		//TODO
		double force = 0;
		return force;
	};

	int t{};
	while (!canvas.windowClosed())
	{
		canvas.clear({32, 32, 32});
		displayBodies(canvas, bv);
		eulerStep(force, bv, t, 1);
		++t;
	}

	return 0;
}
