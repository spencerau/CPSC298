// CPSC-298-6 "Programming in C++"
// In-class Programming Project: Linked List

/// @file LinkedList.cpp
/// @brief Implements a one-directional (or "one-way" or "unidirectional") linked
/// list. Defines a Node class with public member functions. The Node class
/// includes a class-level or static member function that displays the
/// list of Nodes (it does not act on a single Node). 

#include <iostream>

using namespace std;

template <typename T>

class Node {
public:
	Node(T iData);
	~Node() { }
public:
	// These are declared public so that they can be accessed 
	// without using member accessor functions.
	T m_iData;
	Node<T>* mp_nodeNext;

public:

	void displayList(Node<T>* p_nodeHead);
};

template <typename T>
Node<T>::Node(T iData) {
    m_iData = iData;
    mp_nodeNext = nullptr;
}

/// Display a list of Node objects to standard output given
/// the head of the list of Nodes. (This is a static 
/// member function; it behaves differently from ordinary
/// member functions. You cannot use this->m_iData within 
/// this fuction, for example.)
/// @param [in] p_nodeHead pointer to Node object that is the
/// head node of a list of Node objects. 
/// @return void
template <typename T>
void Node<T>::displayList(Node<T>* p_nodeHead)
{
    Node<T>* p_node = p_nodeHead;
    // Iterate over the list of Nodes beginning from the
    // head of the list. Print the data out for each node. 
    // Then, set p_node to point to the next node in the list.
    // Continue until mp_nodeNext is set to nullptr, indicating
    // the end of the list.
    // 
    while (p_node != nullptr) {
        //m_iData->printData();
        cout << "Node Data: " << p_node->m_iData << endl;
        p_node = p_node->mp_nodeNext;
    }
    cout << endl;
    return;
}