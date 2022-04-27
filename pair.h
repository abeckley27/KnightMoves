#pragma once

template <class T>
class pair {
public:
	pair() {}
	pair(T x_, T y_) { x = x_; y = y_; }
	T x;
	T y;
};