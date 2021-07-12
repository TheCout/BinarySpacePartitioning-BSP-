#pragma once
#include <iostream>
#include <vector>


template<typename tn>
struct  vec2 {
	tn x, y;

	vec2() : x(0.0f), y(0.0f) {}
	vec2(tn x, tn y) : x(x), y(y) {}

	vec2<float> distance(vec2<tn> point) const
	{
		float x_distance = point.x > x ? point.x - x : x - point.x;
		float y_distance = point.y > y ? point.y - y : y - point.y;
		return vec2<float>(x_distance, y_distance);
	}
};

template<typename tn>
struct vec3 {
	tn x, y, z;

	vec3() : x(0.0f), y(0.0f), z(0.0f) {}
	vec3(tn x, tn y, tn z) : x(x), y(y), z(z) {}

	vec3<float> distance(vec3<tn> point) const
	{
		float x_distance = point.x > x ? point.x - x : x - point.x;
		float y_distance = point.y > y ? point.y - y : y - point.y;
		float z_distance = point.y > y ? point.y - y : y - point.y;
		return vec3<float>(x_distance, y_distance, z_distance);
	}
};

template<class tn>
struct line {
	tn a, b;

	line() : a(tn()), b(tn()) {}
	line(tn t0, tn t1) : a(t0), b(t1) {}
};

template<typename tn>
struct plane {
	tn l0, l1, l2, l3;

	plane() : l0(tn()), l1(tn()), l2(tn()), l3(tn()) {}
	plane(tn l0, tn l1, tn l2, tn l3) : l0(l0), l1(l1), l2(l2), l3(l3) {}
};


//Type definitions
typedef vec2<int> vec2i;
typedef vec2<float> vec2f;

typedef vec3<int> vec3i;
typedef vec3<float> vec3f;

typedef line<vec2i> line2i;
typedef line<vec2f> line2f;
typedef line<vec3i> line3i;
typedef line<vec3f> line3f;

typedef plane<line2i> plane2i;
typedef plane<line2f> plane2f;
typedef plane<line3i> plane3i;
typedef plane<line3f> plane3f;


typedef std::vector<plane2i> _2iplanes;
typedef std::vector<plane2f> _2fplanes;
typedef std::vector<plane3i> _3iplanes;
typedef std::vector<plane3f> _3fplanes;

typedef std::vector<vec2i> _2ipolygon;
typedef std::vector<vec2f> _2fpolygon;
typedef std::vector<vec3i> _3ipolygon;
typedef std::vector<vec3f> _3fpolygon;

typedef std::vector<_2ipolygon> _2ipolygons;
typedef std::vector<_2fpolygon> _2fpolygons;
typedef std::vector<_3ipolygon> _3ipolygons;
typedef std::vector<_3fpolygon> _3fpolygons;