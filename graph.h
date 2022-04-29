#pragma once
#include <iostream>

template <class T>
class Node {
public:
	Node<T>* ptr[8];
	T value;
	int num_edges;
	int ID;
};

class square {
public:
	square() { row = -1; col = -1; }
	square(int r_, int c_) { row = r_; col = c_; }
	int row;
	int col;

	bool operator==(const square& sq);
};

bool square::operator==(const square& sq)
{
	return (row == sq.row) && (col == sq.col);
}


void print_node(Node<square>* n) 
{
	std::cout << "Node ID: " << n->ID << "\t(" << n->value.row << ", " << n->value.col << ")\n";
	std::cout << n->num_edges << " possible moves from here\n";
}

