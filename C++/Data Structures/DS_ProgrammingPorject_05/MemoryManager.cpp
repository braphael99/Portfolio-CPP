#include "MemoryManager.h"
#include <iostream>

using namespace std;

MemoryManager::MemoryManager(char* p_mem, int size) {

	p_memory = p_mem;

	p_head = (Node*)p_memory;
	p_head->p_next = (Node*)(p_memory + (size - sizeof(Node)));
	p_head->p_prev = 0;
	p_head->isFree = true;
	p_head->sizeOfNode = size - (2 * sizeof(Node));

	p_tail = p_head->p_next;
	p_tail->p_next = 0;
	p_tail->p_prev = p_head;
	p_tail->isFree = false;
	p_tail->sizeOfNode = 0;

}
void* MemoryManager::allocate(int size) {

	Node* p_curr;
	Node* p_biggest = 0;
	p_curr = p_head;
	p_biggest = p_head;
	int sizeOfBiggest = 0;

	//largest slot first algorithm use biggest free block over first available free block
	while (p_curr != p_tail) {

		if (p_curr->sizeOfNode > sizeOfBiggest && p_curr->isFree == true) {

			p_biggest = p_curr;
			sizeOfBiggest = p_curr->sizeOfNode;

		}

		p_curr = p_curr->p_next;

	}

	if (p_biggest->isFree == false || p_biggest->sizeOfNode < size) {

		p_biggest = 0;

	}

	if (p_biggest == 0) {

		return p_biggest;

	}
	else {

		Node* newNode = (Node*)(((char*)p_biggest) + sizeof(Node) + size);

		newNode->isFree = true;
		newNode->sizeOfNode = p_biggest->sizeOfNode - size - sizeof(Node);

		p_biggest->isFree = false;
		p_biggest->sizeOfNode = size;

		newNode->p_next = p_biggest->p_next;
		newNode->p_prev = p_biggest;

		p_biggest->p_next->p_prev = newNode;
		p_biggest->p_next = newNode;

		cout << "Successfully Created Node with size of " << size << "\n";
		
		return (void*)((char*)p_biggest + sizeof(Node));
	}
}

void MemoryManager::deallocate(void* p_delete) {

	//check if the passed in pointer was actually used to allocate
	//we do not want two free nodes next to each other
	//check left and right nodes
	//"canBeDeleted" helper method

	if (canBeDeleted(p_delete) == false) {
		cout << "Deallocation error: 404 node not found" << endl;
	}
	else {

		cout << "found and deallocated node\n";

	}


}

void MemoryManager::dump() {

	Node* p_curr;
	p_curr = p_head;
	//walk through nodes and tell us free or used and the size of the block
	while (p_curr->p_next != 0) {

		if (p_curr->isFree) {

			cout << "Current Node is Free and has " << p_curr->sizeOfNode << " free bytes\n";

		}
		else {

			cout << "Current Node is Used and has " << p_curr->sizeOfNode << " bytes\n";

		}

		p_curr = p_curr->p_next;

	}


}

bool MemoryManager::canBeDeleted(void* p_delete) {

	Node* p_current;

	bool retVal = false;
	p_current = p_head;
	while (p_current != p_tail) {
		if ((char*)p_current + sizeof(Node) == p_delete) {
			retVal = true;
			deleteNode((Node*)p_current);
			coalesceRight(p_current);
			coalesceLeft(p_current);
			break;
		}
		p_current = p_current->p_next;
	}
	return retVal;
	

}

void MemoryManager::deleteNode(Node* p_delete) {

	if (p_delete != 0) {

			p_delete->isFree = true;

			cout << "successful deletion of a node\n";

	}

}
void MemoryManager::coalesceLeft(Node* p_incNode) {

	cout << "coalescing left...\n";

	Node* p_temp = p_incNode->p_prev;


	if (p_incNode != p_head && p_incNode->p_prev->isFree) {

			p_incNode->sizeOfNode = p_incNode->sizeOfNode + p_incNode->p_prev->sizeOfNode + sizeof(Node);

			p_incNode->p_prev->p_next = p_incNode->p_next;
			p_incNode->p_next->p_prev = p_incNode->p_prev;
			
			cout << "coalesced left.\n";
	}
	else {

			cout << "did not coalesce\n";

	}

	

}
void MemoryManager::coalesceRight(Node* p_incNode) {

	cout << "coalescing right...\n";

		if (p_incNode->p_next->isFree) {

			p_incNode->sizeOfNode = p_incNode->sizeOfNode +  p_incNode->p_next->sizeOfNode + sizeof(Node);

			p_incNode->p_next = p_incNode->p_next->p_next;
			p_incNode->p_next->p_prev = p_incNode;

			cout << "coalesced right.\n";
		}
		else {

			cout << "did not coalesce\n";

		}

}