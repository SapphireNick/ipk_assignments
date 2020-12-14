#include <cassert>
#include "../header/canvas.hh"

void test_canvas()
{
    Canvas test_canvas = Canvas(Point(5, 5), 10, 10, 10, 10);

    assert(test_canvas.coord(0, 0).x() == 0 && 
            test_canvas.coord(0, 0).y() == 0);
    assert(test_canvas.coord(9, 0).x() == 9 &&
            test_canvas.coord(9, 0).y() == 0);
    assert(test_canvas.coord(0, 9).x() == 0 &&
            test_canvas.coord(0, 9).y() == 9);
    assert(test_canvas.coord(9, 9).x() == 9 &&
            test_canvas.coord(9, 9).y() == 9);
}

int main()
{
    test_canvas();
}