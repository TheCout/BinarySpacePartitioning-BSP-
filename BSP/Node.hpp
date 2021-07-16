#pragma once
#include "Geometry.hpp"


class Node {
public:
	_2fpolygon data;
	class Node* front;
	class Node* back;

	Node()
	{
		data = _2fpolygon();
	}

	Node(_2fpolygon _data)
	{
		data = _data;
		front = NULL;
		back = NULL;
	}
};