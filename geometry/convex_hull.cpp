#include <iostream>
#include <vector>
#include <algorithm>

// Problem statement: https://open.kattis.com/problems/convexhull

struct ivec2
{
	int x, y;

	bool operator<(const ivec2& other) const
	{
    return (this->y != other.y) ? (this->y < other.y) : (this->x < other.x);
	}

	bool operator==(const ivec2& other) const
	{
		return (this->x == other.x) && (this->y == other.y);
	}
};

int8_t orientation(const ivec2& a, const ivec2& b, const ivec2& c)
{
	int area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	return (area < 0) * -1 + (area > 0);
}

std::vector<ivec2> construct_convex_hull(std::vector<ivec2>& points)
{
	ivec2 pivot = *std::min_element(points.begin(), points.end());

	std::sort(
		points.begin(),
		points.end(),
		[&pivot](const ivec2& a, const ivec2& b)
		{
			auto orient = orientation(pivot, a, b);
			if (orient == 0)
				return
				(pivot.x - a.x) * (pivot.x - a.x) + (pivot.y - a.y) * (pivot.y - a.y) <
				(pivot.x - b.x) * (pivot.x - b.x) + (pivot.y - b.y) * (pivot.y - b.y);
			else
				return orient > 0;
		}
	);

	std::vector<ivec2> convex_hull;
	convex_hull.reserve(points.size());

	for (size_t i = 0; i < points.size(); ++i)
	{
		while (convex_hull.size() >= 2 && orientation(convex_hull.end()[-2], convex_hull.end()[-1], points[i]) != 1)
		{
			convex_hull.pop_back();
		}
		convex_hull.push_back(points[i]);
	}

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
		ivec2 point{};
		for (size_t i = 0; i < n; ++i)
		{
			std::cin >> point.x >> point.y;
			points[i] = point;
		}

		auto res = construct_convex_hull(points);
		std::cout << res.size() << '\n';
		for (size_t i = 0; i < res.size(); ++i)
		{
			std::cout << res[i].x << " " << res[i].y << '\n';
		}
	}
}