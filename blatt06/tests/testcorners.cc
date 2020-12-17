#include <cassert>
#include "../header/canvas.hh"

void test_canvas()
{
    Point center = Point(5, 5);
    double width = 10;
    double height = 10;
    int horPixels = 10;
    int vertPixels = 10;
    Canvas test_canvas = Canvas(center, width, height, horPixels, vertPixels);

    assert(test_canvas.coord(0, 0).x() == center.x() - (0.5 * width) &&
            test_canvas.coord(0, 0).y() == center.y() - (0.5 * height));
    assert(test_canvas.coord(9, 0).x() == center.x() + (0.5 * width) &&
            test_canvas.coord(9, 0).y() == center.y() - (0.5 * height));
    assert(test_canvas.coord(0, 9).x() == center.x() - (0.5 * width) &&
            test_canvas.coord(0, 9).y() == center.y() + (0.5 * height));
    assert(test_canvas.coord(9, 9).x() == center.x() + (0.5 + width) &&
            test_canvas.coord(9, 9).y() == center.y() + (0.5 + height));
}

int main()
{
    test_canvas();
}