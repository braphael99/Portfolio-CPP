#pragma once 
#include <iostream>

using namespace std;

template < class T >
class DoublyLinkedList
{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insertAtFront(const T& elem);
    void insertAtRear(const T& elem);
    bool removeFromFront(T& elem); //true if an item is removed, elem holds that value
    bool removeFromRear(T& elem); //true if an item is removed, elem holds that value
    bool remove(); //remove the element that the current pointer points to
    bool remove(const T& elem); //remove all occurrences of the element that is passed in.
    int size();
    bool first(T& elem);
    bool last(T& elem);
    bool next(T& elem);
    bool previous(T& elem);
    bool isEmpty();
    bool find(const T& elem); //returns a true/false value indicating if an element is present in the list
    T at(int pos); //a method that simulates accessing the list like an array.
    T& operator[] (int pos); //call at()
private:
    struct Node
    {
        Node* p_prev;
        T data;
        Node* p_next;

    };

    Node* p_head;
    Node* p_tail;
    Node* p_current;
    int numElements;
};
//--
template < class T >
DoublyLinkedList<T>::DoublyLinkedList()
{
    p_head = 0;
    p_tail = 0;
    p_current = 0;
    numElements = 0;
}
//--
template < class T >
DoublyLinkedList<T>::~DoublyLinkedList()
{
    Node* p_delete;
    while (!isEmpty())
    {
        p_delete = p_head;
        p_head = p_head->p_next;
        delete p_delete;
        numElements--;
    }
    //cout << "Deleting a DoublyLinkedList" << endl;
}
//--
template < class T >
bool DoublyLinkedList<T>::first(T& elem)
{
    bool retVal = false;

    if (!isEmpty())
    {
        retVal = true;
        p_current = p_head;
        elem = p_current->data;
    }

    return retVal;
}
//--

template < class T >
bool DoublyLinkedList<T>::last(T& elem) {

    bool retVal = false;

    if (!isEmpty())
    {
        p_current = p_tail;
        elem = p_current->data;
        retVal = true;
    }

    return retVal;


}


template < class T >
bool DoublyLinkedList<T>::next(T& elem)
{
    bool retVal = false;

    if (p_current != 0 && p_current->p_next != 0)
    {
        p_current = p_current->p_next;
        elem = p_current->data;
        retVal = true;
    }

    return retVal;
}
//--

template < class T >
bool DoublyLinkedList<T>::previous(T& elem) {

    bool retVal = false;

    if (p_current != 0 && p_current->p_prev != 0)
    {
        p_current = p_current->p_prev;
        elem = p_current->data;
        retVal = true;
    }

    return retVal;


}

template < class T >
void DoublyLinkedList<T>::insertAtFront(const T& elem) {

    Node* p_newNode = new Node;
    p_newNode->data = elem;
    p_newNode->p_next = p_head;
    p_newNode->p_prev = 0;

    if (size() == 0) {

        p_newNode->p_next = 0;
        p_head = p_newNode;
        p_tail = p_newNode;

    }
    else {

        p_head->p_prev = p_newNode;

    }

    p_head = p_newNode;
    numElements++;
}

template < class T >
void DoublyLinkedList<T>::insertAtRear(const T& elem) {

    Node* p_newNode = new Node;
    p_newNode->data = elem;
    p_newNode->p_prev = p_tail;
    p_newNode->p_next = 0;

    if (size() == 0) {

        p_newNode->p_prev = 0;
        p_head = p_newNode;
        p_tail = p_newNode;

    }
    else {

        p_tail->p_next = p_newNode;

    }

    p_tail = p_newNode;
    numElements++;


}

template < class T >
bool DoublyLinkedList<T>::removeFromFront(T& elem) {

    bool retVal = false;

    Node* p_delete = 0;

    if (!isEmpty()) {

        p_delete = p_head;
        elem = p_delete->data;
        p_head = p_delete->p_next;
        p_head->p_prev = 0;
        p_current = p_head;

        retVal = true;

        if (size() == 1) {

            p_tail = 0;

        }
        else {
            p_head->p_prev = 0;
        }

    }

    delete p_delete;
    p_delete = 0;

    numElements--;


    return retVal;

}//true if an item is removed, elem holds that value

template < class T >
bool DoublyLinkedList<T>::removeFromRear(T& elem) {

    bool retVal = false;

    Node* p_delete = 0;

    if (size() > 1) {

        p_delete = p_tail;
        elem = p_delete->data;
        p_tail = p_delete->p_prev;
        p_current = p_tail;

        p_tail->p_next = 0;
        retVal = true;

    }
    else if (size() == 1) {

        delete p_head;
        p_head = 0;
        p_tail = 0;
        p_current = 0;

    }

    delete p_delete;
    p_delete = 0;
    numElements--;


    return retVal;

}//true if an item is removed, elem holds that value

//work on
template < class T >
bool DoublyLinkedList<T>::remove() {

    bool retVal = false;

    if (!isEmpty() && p_current != 0) {

        if (p_current == p_head && p_current == p_tail) {

            delete p_current;
            p_current = 0;

            retVal = true;
            numElements--;

        }
        else if (p_current == p_head) {

            //if (p_current->p_prev == 0) {

            T test;
            removeFromFront(test);
            retVal = true;

            //}

        }
        else if (p_current == p_tail) {

            //if (p_current->p_next == 0) {

            T test;
            removeFromRear(test);
            retVal = true;

            //}

        }
        else {

            Node* p_temp = p_current;

            p_temp = p_current->p_prev; //temp == node to left
            p_temp->p_next = p_current->p_next; //next in current in now next in previous

            p_temp = p_current->p_next; //temp == node to right
            p_temp->p_prev = p_current->p_prev;//previous in curr is prev in next

            delete p_current;

            p_current = p_temp; //current is now next

            retVal = true;
            numElements--;
        }

    }

    return retVal;

}//remove the element that the current pointer points to
template < class T >
bool DoublyLinkedList<T>::remove(const T& elem) {

    bool retVal = false;

    for (int i = 0; i < numElements; i++) {

        if (find(elem)) {

            remove();
            retVal = true;

        }

    }

    return retVal;

}//remove all occurrences of the element that is passed in.

template < class T >
int DoublyLinkedList<T>::size()
{
    return numElements;
}
//--
template < class T >
bool DoublyLinkedList<T>::isEmpty()
{
    return size() == 0;
}

template < class T >
bool DoublyLinkedList<T>::find(const T& elem) {

    bool retVal = false;
    p_current = p_head;

    for (int i = 0; i < numElements; i++) {

        //problem with current in the remove method, where is p_current getting lost?
        if (elem == at(i)) {

            retVal = true;
            break;

        }
        else {

            p_current = p_current->p_next;

        }
    }

    return retVal;


}//returns a true/false value indicating if an element is present in the list

template < class T >
T DoublyLinkedList<T>::at(int pos) {

    T test;
    first(test);
    int counter = 0;

    if (!isEmpty() && pos <= numElements) {
        while (counter < pos) {

            p_current = p_current->p_next;
            counter++;

        }

        return p_current->data;

    }
    else {

        throw "Bad position";

    }

}//a method that simulates accessing the list like an array.


template < class T >
T& DoublyLinkedList<T>::operator[] (int pos) {

    return at(pos);

}
