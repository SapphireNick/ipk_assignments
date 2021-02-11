#include "sdlwrapper.hh"
#include "point.hh"
#include "body.hh"
#include <vector>
#include <cstdlib>
#include <cmath>

int width{1600}, height{900};
double G{0.01}, M{}, g{0.0001};
bool rain{false}; //change to true for d)
std::array<int, 3> red{255, 0, 0}, green{0, 255, 0}, blue{64, 191, 255}, yellow{255, 255, 0};

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
	if (rain)
		for (auto&& b : bodies) {
			if (b.x().x() >= 0.5 * width) {
				b.x() = Point(-0.5 * width, b.x().y());
			}
			if (b.x().y() >= 0.5 * height ) {
				b.v() = Point(b.v().x(), 0);
				b.x() = Point(b.x().x(), -0.5 * height);
			}
		}
}

template<typename Body>
void displayBodies(SDLCanvas& canvas, std::vector<Body>& bodies)
{
	Point cm{};
	for (auto&& b : bodies) {
		cm += b.m() * b.x();
	}
	cm *= 1/M;

	for (auto&& b : bodies) {
		canvas.drawPixel(b.x().x() + 0.5 * width - cm.x(), b.x().y() + 0.5 * height - cm.y(), b.c());
	}
	canvas.display();
}

int main(int argc, char** argv)
{
	SDLCanvas canvas{"nbody", width, height};
	canvas.clear();

	std::vector<Body> bv1{
		{{0, 0}, {0, 0}, 1e3, red},
		{{100, 0}, {0, 0.3}, 10, green},
		{{-200, 0}, {0, 0.2}, 10, blue},
		{{0, 250}, {-0.25, 0}, 10, yellow},
	};
	std::vector<Body> bv2{
		{{150, 0}, {0, -0.2}, 1e3, red},
		{{-150, 0}, {0, 0.2}, 1e3, green},
		{{0, 150}, {0.2, 0}, 1e3, blue},
		{{0, -150}, {-0.2, 0}, 1e3, yellow},
	};
	std::vector<Body> bvr{};
	if (rain)
	{
		for (int i = 0; i < 10000; ++i) {
			double w{(double) (std::rand() % width)}, h{(double) (std::rand() % (height * height))};
			h = h * 1. / height;
			h *= h / height;
			bvr.push_back(Body({w - 0.5 * width, h - 0.5 * height}, {0.1, std::sqrt(2 * h * g)}, 0, blue));
		}
	}

	// change bv1 to bv2 for the second example
	std::vector<Body> bv{rain ? bvr : bv1};

	auto forced = [](const std::vector<Body>& bodies, int i, double dt) { return Point(0, g); }; // rain
  auto forcec = [](const std::vector<Body>& bodies, int i, double dt)
	{
		Point force{};
		for (int j = 0; j < bodies.size(); ++j) {
			if (i == j) continue;
			force += G * bodies[j].m() * (bodies[j].x() - bodies[i].x()).dist2();
		}
		return force;
	};
	auto force = rain ? forced : forcec;

	for (auto&& b : bv) {
		M += b.m();
	}
	if (!M) M = 1;

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
