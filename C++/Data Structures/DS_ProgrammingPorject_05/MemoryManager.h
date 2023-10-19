#pragma once
class MemoryManager
{
public:
	MemoryManager(char* p_mem, int size);
	void* allocate(int size);
	void deallocate(void* p_delete);
	void dump();
private:
	char* p_memory;
	struct Node {

		Node* p_next;
		Node* p_prev;
		bool isFree;
		int sizeOfNode;
	};

	Node* p_head;
	Node* p_tail;

	bool canBeDeleted(void* p_delete);
	void deleteNode(Node* p_delete);
	void coalesceLeft(Node* p_incNode);
	void coalesceRight(Node* p_incNode);
};

