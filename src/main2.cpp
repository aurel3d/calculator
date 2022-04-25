#include <vector>

struct Shape2D
{
};

template<typename T, typename Count>
struct Point
{
	std::array<T, Count> values = {};
};

template<typename T>
struct Point2D : public Point<T, 2>
{
	Point2D(const T& x, const T& y)
	{
		values[0] = x;
		values[1] = y;
	}

	const T& x() const
	{
		return values[0];
	}

	const T& y() const
	{
		return values[1];
	}
};

typedef Point2D<double> Point2Dd;
typedef Point2D<float> Point2Df;

template<typename Count>
struct Polygon : public Shape2D
{
	std::array<Point2Dd, Count> points = {};
};