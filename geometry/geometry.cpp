#include "convex_hull.h"

// Problem statement: https://open.kattis.com/problems/convexhull
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

		auto polygon = geometry::convex_hull_construct(points);

		std::cout << polygon.size() << '\n';
		for (size_t i = 0; i < polygon.size(); ++i)
			std::cout << polygon[i] << '\n';
	}
}
