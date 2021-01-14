#include <cassert>
#include "../header/point.hh"

int main()
{
    std::array<double, 1> dim1point = {2};
    std::array<double, 3> dim3pointdouble = {0.6, 4.6, 1};
    std::array<int, 3> dim3int = {3, 5, 1};

    Point<double, 1> P1DIM = Point<double, 1>(dim1point);
    Point<double, 3> P3DOUBLE = Point<double, 3>(dim3pointdouble);
    Point<int, 3> P3INT = Point<int, 3>(dim3int);

    assert(P1DIM[0] == 2);
    for(int i = 0; i < 3; i++)
    {
        assert(P3DOUBLE[i] == dim3pointdouble[i]);
        assert(P3INT[i] == dim3int[i]);
    }

    assert(P1DIM.norm() == 2);
    assert(P3DOUBLE.norm() - 4.7455242 < 0.5);
    assert(P3INT.norm() - sqrt(35) < 0.5);

    return 0;
}

