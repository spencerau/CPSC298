#include "LinkedList.h"

int main()
{
	{
	// Allocate three node objects within heap memory.
	Node<int>* p_node1 = new Node<int>(10);
	Node<int>* p_node2 = new Node<int>(20);
	Node<int>* p_node3 = new Node<int>(30);
	
	// Set p_nodeHead to point to the head or leading node
	// in the list of nodes, in this case p_node1.
	Node<int>* p_nodeHead = p_node1;
	p_node1->mp_nodeNext = p_node2; // append p_node2 to the list of Node objects after p_node1.
	p_node2->mp_nodeNext = p_node3; // append p_node3 to the list of Node objects after p_node2.
	p_node3->mp_nodeNext = nullptr; // The end of the list is indicated by a mp_nodeNext value of nullptr.
	p_node1->displayList(p_nodeHead);  // display the list of nodes to standard output.
	}

	{
	// Allocate three node objects within heap memory.
	Node<double>* p_node4 = new Node<double>(10.1);
	Node<double>* p_node5 = new Node<double>(20.2);
	Node<double>* p_node6 = new Node<double>(30.3);
	// in the list of nodes, in this case p_node1.
	Node<double>* p_nodeHead = p_node4;
	p_node4->mp_nodeNext = p_node5; // append p_node3 to the list of Node objects after p_node2.
	p_node5->mp_nodeNext = p_node6; // The end of the list is indicated by a mp_nodeNext value of nullptr.
	p_node6->mp_nodeNext = nullptr; // The end of the list is indicated by a mp_nodeNext value of nullptr.
	p_node4->displayList(p_nodeHead);  // display the list of nodes to standard output.
	}
}


