#pragma once
#include <iostream>

template <class T>
class Node {
public:
	Node<T>() { num_edges = 0; ID = -1; }
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

//Shortest path
int distance(Node<square>* n1, Node<square>* n2) {
	return 0;
}


template <class T>
class graph {
public:
	graph() { create(); }
	graph(int n) { create(n); }
	~graph() { destroy(); }

	int size;
	Node<T>* head;
	Node<T>** vertex_list;

private:
	void create();
	void create(int);
	void destroy();
};

template<class T>
inline void graph<T>::create()
{
	head = NULL;
	vertex_list = NULL;
	size = 0;
}

template<class T>
inline void graph<T>::create(int n)
{
	size = n;
	vertex_list = new Node<T>*[n];

	for (int i = 0; i < n; i++) {
		vertex_list[i] = new Node<T>;
		vertex_list[i]->ID = i;
		vertex_list[i]->num_edges = 0;
		vertex_list[i]->ptr = NULL;
	}

	head = vertex_list[0];
}

template<class T>
inline void graph<T>::destroy()
{
	for (int i = 0; i < size; i++) {
		delete vertex_list[i];
	}
}
