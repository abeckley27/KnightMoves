#include <iostream>
#include "pair.h"
#include "graph.h"

using namespace std;

int main(int argc, char* argv[]) {

	int i;

	Node<square> head;
	head.value = square(0, 0);
	head.num_edges = 2;
	
	for (i = 0; i < head.num_edges; i++) {
		head.ptr[i] = new Node<square>;
		//Todo: figure out how to deallocate the nodes
	}

	head.ptr[0]->value = square(1, 2);
	head.ptr[1]->value = square(2, 1);
	print_node(head);

	/*
	For general purpose initialization, I need to check which moves are valid
	Would be nice to order the possible offsets and check them in a loop

	x offset can be plus or minus 1 or 2
	y offset can be plus or minus the other 
	8 possible moves
	*/

	// Set up array of possible moves
	pair<int>* moves = new pair<int>[8];
	moves[0] = pair<int>(-2, -1);
	moves[1] = pair<int>(-2, 1);
	moves[2] = pair<int>(-1, -2);
	moves[3] = pair<int>(-1, 2);

	//Set up the node for the (1, 2) square
	Node<square>* ptr = head.ptr[0];
	int r = ptr->value.row;
	int c = ptr->value.col;
	
	print_node(*ptr);


	return 0;
}