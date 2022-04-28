#pragma once
#include <iostream>

template <class T>
class pair {
public:
	pair() {}
	pair(T x_, T y_) { x = x_; y = y_; }
	T x;
	T y;

	void print() { std::cout << '(' << x << ", " << y << ")\n";}
};

