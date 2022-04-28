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
};

void extend_node(Node<square>& node_) {

	// Check to make sure the square has been initialized
	if (node_.value.col >= 0 && node_.value.row >= 0) {
		int x1 = node_.value.row - 1;
		int y1 = node_.value.col - 2;
	}
}

void print_node(Node<square>* n) {
	std::cout << "Node ID: " << n->ID << "\t(" << n->value.row << ", " << n->value.col << ")\n";
	std::cout << n->num_edges << " possible moves from here\n";
}

void print_graph(Node<square>* head) {
	print_node(head);
}
