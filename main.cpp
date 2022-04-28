#include <iostream>
#include <vector>
#include "pair.h"
#include "graph.h"

int main(int argc, char* argv[]) {

	int i;
	Node<square> head;
	head.value = square(0, 0);
	head.num_edges = 2;
	head.ID = 0;

	// A list of the addresses for all the nodes.
	// The index is the ID for the node the address points to
	std::vector<void*> vertexID = {&head};
	
	for (i = 0; i < head.num_edges; i++) {
		head.ptr[i] = new Node<square>;
		head.ptr[i]->ID = 1 + i;
		vertexID.push_back(head.ptr[i]);
		//Todo: figure out how to deallocate the nodes
	}

	head.ptr[0]->value = square(1, 2);
	head.ptr[1]->value = square(2, 1);
	print_node(&head);

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
	moves[4] = pair<int>(1, -2);
	moves[5] = pair<int>(1, 2);
	moves[6] = pair<int>(2, -1);
	moves[7] = pair<int>(2, 1);
	//for (i = 0; i < 8; i++) { moves[i].print(); }

	//Set up the node for the (1, 2) square
	Node<square>* vertexptr = head.ptr[0];
	vertexptr->num_edges = 0;
	int r = vertexptr->value.row;
	int c = vertexptr->value.col;
	int newx, newy;
	for (i = 0; i < 8; i++) {
		newx = r + moves[i].x;
		newy = c + moves[i].y;
		if (newx >= 0 && newy >= 0 && newx <= 7 && newy <= 7) { 
			vertexptr->ptr[i] = new Node<square>;
			vertexptr->ptr[i]->value = square(newx, newy);
			vertexptr->ptr[i]->num_edges = 0;
			vertexID.push_back(vertexptr->ptr[i]);
			vertexptr->ptr[i]->ID = vertexID.size();
			vertexptr->num_edges++;
		}
	}

	print_node(vertexptr);
	//print_graph(vertexptr);
	/*
	prints the whole graph
	for (i = 0; i < vertexID.size(); i++) { 
		std::cout << vertexID[i] << '\t';
		print_node( (Node<square>*)vertexID[i] );
	}
	*/

	return 0;
}