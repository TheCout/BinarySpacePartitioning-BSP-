#pragma once
#include "Geometry.hpp"


#define FRONT 0
#define BACK 1
#define _CURRENT_STATUS FRONT


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