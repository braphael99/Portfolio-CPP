#pragma once
#include <iostream>
#include <string>
#include "DoublyLinkedList.h"
#include <exception>

using namespace std;

template <class T>
class Stack
{
public:
	Stack();
	~Stack();
	void push(const T& elem);
	T pop();
	T top();
	bool isEmpty();
	int size();
private:
	DoublyLinkedList<T> list;
};

template <class T>
Stack<T>::Stack() {

	//can leave empty?

}

template <class T>
Stack<T>::~Stack() {

	//can leave empty?

}

template <class T>
void Stack<T>::push(const T& elem) {

	list.insertAtFront(elem);

}

template <class T>
T Stack<T>::pop() {

	T temp;
	if (!isEmpty()) {
		list.removeFromFront(temp);

		
	}
	else {

		//StackUnderFlow ex;
		throw "Stack underflow";

	}

	return temp;
}

template <class T>
T Stack<T>::top() {

	//T temp = new T;
	if (isEmpty()) {
		
		//StackUnderFlow ex;
		throw "Stack Underflow";
		

	}
	else {

		return list.at(0);

	}


}

template <class T>
bool Stack<T>::isEmpty() {

	return list.isEmpty();

}

template <class T>
int Stack<T>::size() {

	return list.size();

}