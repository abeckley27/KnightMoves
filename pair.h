#pragma once
#include <iostream>

template <class T>
class pair {
public:
	pair() { x = -1; y = -1; }
	pair(T x_, T y_) { x = x_; y = y_; }
	T x;
	T y;

	void print() { std::cout << '(' << x << ", " << y << ")\n";}
};

