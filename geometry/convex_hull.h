#pragma once

#include "types.h"

#include <vector>
#include <algorithm>

namespace geometry
{
	[[nodiscard]] static inline std::vector<ivec2>
	convex_hull_construct(std::vector<ivec2> points, bool strictly_convex = true)
	{
		// lowest y-coordinate and leftmost point
		ivec2 pivot = *std::min_element(points.begin(), points.end());

		std::sort(
			points.begin(),
			points.end(),
			[&pivot](const ivec2& a, const ivec2& b)
			{
				auto area = (a - pivot) * (b - pivot);
				if (area == 0)
				{
					auto pivot_a = a - pivot;
					auto pivot_b = b - pivot;
					return pivot_a.dot(pivot_a) < pivot_b.dot(pivot_b);
				}
				else
				{
					return area > 0;
				}
			}
		);

		if (!strictly_convex)
		{
			int reverse_index = (int)points.size() - 2;
			while (reverse_index > 0 && (points.back() - pivot) * (points[reverse_index] - pivot) == 0)
				reverse_index--;
			std::reverse(points.begin() + reverse_index + 1, points.end());
		}

		std::vector<ivec2> polygon;
		polygon.reserve(points.size());

		for (size_t i = 0; i < points.size(); ++i)
		{
			while (polygon.size() >= 2)
			{
				auto a = polygon.end()[-2];
				auto b = polygon.end()[-1];
				auto area = (b - a) * (points[i] - a);
				if (area > 0 || (area == 0 && !strictly_convex))
					break;

				// remove last point if it results in a clockwise orientation or if the points are collinear
				polygon.pop_back();
			}
			polygon.push_back(points[i]);
		}

		if (strictly_convex && polygon.size() == 2 && polygon[0] == polygon[1])
			polygon.pop_back();

		polygon.shrink_to_fit();
		return polygon;
	}
}