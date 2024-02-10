#pragma once

#include <iostream>

struct ivec2
{
	int64_t x, y;

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

	inline ivec2& operator-=(const ivec2& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	inline int64_t operator*(const ivec2& other) const
	{
		return x * other.y - y * other.x;
	}

	inline int64_t dot(const ivec2& other) const
	{
		return x * other.x + y * other.y;
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
