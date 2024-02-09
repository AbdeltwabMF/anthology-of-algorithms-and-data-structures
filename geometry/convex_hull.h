#pragma once

#include "types.h"

#include <vector>
#include <algorithm>
#include <cmath>

namespace geometry
{
	[[nodiscard]] static inline std::vector<ivec2>
	convex_hull_construct(std::vector<ivec2> points)
	{
		// lowest y-coordinate and leftmost point
		ivec2 pivot = *std::min_element(points.begin(), points.end());

		std::sort(
			points.begin(),
			points.end(),
			[&pivot](const ivec2& a, const ivec2& b)
			{
				auto area = (a - pivot) * (b - pivot);
				auto a_smaller = ::abs(pivot.x - a.x) + ::abs(pivot.y - a.y) < ::abs(pivot.x - b.x) + ::abs(pivot.y - b.y);
				return (area != 0) * (area > 0) + (area == 0) * a_smaller;
			}
		);

		std::vector<ivec2> polygon;
		polygon.reserve(points.size());

		for (size_t i = 0; i < points.size(); ++i)
		{
			while (polygon.size() >= 2)
			{
				auto a = polygon.end()[-2];
				auto b = polygon.end()[-1];
				auto& c = points[i];

				if ((b - a) * (c - a) > 0)
					break;

				// remove last point if it results in a clockwise orientation or if the points are collinear
				polygon.pop_back();
			}
			polygon.push_back(points[i]);
		}

		polygon.shrink_to_fit();
		return polygon;
	}
}