#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	void insert(const T& elem);
	bool first(T& elem); //call when you first want to iterate
	bool next(T& elem); //returns true as long as we arent at the last node
	int size();
	bool isEmpty();

private:
    struct Node {

        T data :
        Node* p_next;

    };

	Node* p_head;
	Node* p_current;

	int numElements;

};

template < class T >
LinkedList<T>::LinkedList(){

    p_head = 0;
    p_current = 0;
    numElements = 0;

}

template < class T >
LinkedList<T>::~LinkedList(){

    Node* p_delete;
    while (!isEmpty())
    {
        p_delete = p_head;
        p_head = p_head->p_next;
        delete p_delete;
        numElements--;
    }
    cout << "Deleting a LinkedList" << endl;

}

template < class T >
void LinkedList<T>::insert(const T& elem){

    Node* p_newNode = new Node;
    p_newNode->data = elem;
    p_newNode->p_next = p_head;
    p_head = p_newNode;
    numElements++;

}

template < class T >
bool LinkedList<T>::first(T& elem){

    bool retVal = false;

    if (!isEmpty())
    {
        retVal = true;
        p_current = p_head;
        elem = p_current->data;
    }

    return retVal;

}

template < class T >
bool LinkedList<T>::next(T& elem){

    bool retVal = false;

    if (p_current && p_current->p_next != 0)
    {
        p_current = p_current->p_next;
        elem = p_current->data;
        retVal = true;
    }

    return retVal;

}

template < class T >
int LinkedList<T>::size(){

    return numElements;

}

template < class T >
bool LinkedList<T>::isEmpty(){

    return size() == 0;

}