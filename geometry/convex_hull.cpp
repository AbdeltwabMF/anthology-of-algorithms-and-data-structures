#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// Problem statement: https://open.kattis.com/problems/convexhull

struct ivec2
{
	int x, y;

	inline bool operator<(const ivec2& other) const
	{
		return (y != other.y) ? (y < other.y) : (x < other.x);
	}

	inline bool operator==(const ivec2& other) const
	{
		return (x == other.x) && (y == other.y);
	}

	inline ivec2 operator-(const ivec2& other) const
	{
		return ivec2{x - other.x, y - other.y};
	}

	inline int64_t operator*(const ivec2& other) const
	{
		return (int64_t)x * other.y - (int64_t)y * other.x;
	}
};

std::ostream& operator<<(std::ostream& out, const ivec2& vec)
{
	out << vec.x << " " << vec.y;
	return out;
}

std::istream& operator>>(std::istream& in, ivec2& vec)
{
	in >> vec.x >> vec.y;
	return in;
}

std::vector<ivec2> construct_convex_hull(std::vector<ivec2>& points)
{
	// lowest y-coordinate and leftmost point
	ivec2 pivot = *std::min_element(points.begin(), points.end());

	std::sort(
		points.begin(),
		points.end(),
		[&pivot](const ivec2& a, const ivec2& b)
		{
			auto area = (a - pivot) * (b - pivot);
			if (area != 0)
				return area > 0; // positive area makes a counter-clockwise orientation

			// break the tie by comparing the Manhattan distance with respect to the pivot
			return ::abs(pivot.x - a.x) + ::abs(pivot.y - a.y) < ::abs(pivot.x - b.x) + ::abs(pivot.y - b.y);
		}
	);

	std::vector<ivec2> convex_hull;
	convex_hull.reserve(points.size());

	for (size_t i = 0; i < points.size(); ++i)
	{
		while (convex_hull.size() >= 2)
		{
			auto a = convex_hull.end()[-2];
			auto b = convex_hull.end()[-1];
			auto& c = points[i];

			if ((b - a) * (c - a) > 0)
				break;

			// remove last point if it results in a clockwise orientation or if the points are collinear
			convex_hull.pop_back();
		}
		convex_hull.push_back(points[i]);
	}

	// corner case: The convex hull consists of two identical points
	if (convex_hull.size() == 2 && convex_hull[0] == convex_hull[1])
		convex_hull.pop_back();

	convex_hull.shrink_to_fit();
	return convex_hull;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<ivec2> points;
	points.reserve(10'000 + 9);

	int n{};
	while (std::cin >> n && n)
	{
		points.resize(n);
		for (size_t i = 0; i < n; ++i)
			std::cin >> points[i];

		auto res = construct_convex_hull(points);

		std::cout << res.size() << '\n';
		for (size_t i = 0; i < res.size(); ++i)
			std::cout << res[i] << '\n';
	}
}