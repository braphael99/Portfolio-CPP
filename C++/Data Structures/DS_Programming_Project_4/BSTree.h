#pragma once 

#include <iostream> 

using namespace std;

template < class T >
class BSTree
{
public:
    BSTree();
    ~BSTree();

    T max();
    T min();
    bool search(const T& d);
    int count(const T& d);
    int heightOfTree();
    double percentLeaf();
    double percentInterior();
    void remove(const T& d);

    void insert(const T& d);
    void printInOrder();
    void printPreorder();
    void printPostOrder();

private:
    struct Node
    {
        T data;
        Node* left;
        Node* right;
    };

    Node* root;
    int numberOfElements;

    T max(Node* p);
    T min(Node* p);
    void search(Node* p, const T& d, bool& isFound);
    void count(Node* p, const T& d, int& numOccurrences);
    void heightOfTree(Node* p, int currentHeight, int& maxHeight);
    void percentLeaf(Node* p, int& numLeaves);
    void remove(Node*& p, const T& d);

    void insert(Node*& p, const T& d);
    void printInOrderHelper(Node* p);
    void printPreorderHelper(Node* p);
    void printPostOrderHelper(Node* p);
    void removeAll(Node*& p);
};
//-- 
template < class T >
BSTree < T >::BSTree()
{
    root = 0;
    numberOfElements = 0;
}
//-- 
template < class T >
BSTree < T >::~BSTree()
{
    removeAll(root);
}
//-- 
template < class T >
void BSTree < T >::removeAll(Node*& p)
{
    if (p != 0)
    {
        removeAll(p->left);
        removeAll(p->right);
        cout << "\tDeleting " << p->data << endl;
        delete p;
    }
}
//-- 
template < class T >
void BSTree < T >::insert(const T& d)
{
    insert(root, d);
}
//-- 
template < class T >
void BSTree < T >::insert(Node*& p, const T& d)
{
    if (p == 0)
    {
        p = new Node;
        p->left = 0;
        p->right = 0;
        p->data = d;
        numberOfElements++;

        cout << "Inserting " << d << endl;
    }
    else if (d < p->data)
    {
        insert(p->left, d);
    }
    else
    {
        insert(p->right, d);
    }
}
//-- 
template < class T >
void BSTree < T >::printInOrder()
{
    printInOrderHelper(root);
    cout << endl;
}
//-- 
template < class T >
void BSTree < T >::printInOrderHelper(Node* p)
{
    if (p != 0)
    {
        printInOrderHelper(p->left);
        cout << p->data << " ";
        printInOrderHelper(p->right);
    }
}
//-- 
template < class T >
void BSTree < T >::printPreorder()
{
    printPreorderHelper(root);
    cout << endl;
}
//-- 
template < class T >
void BSTree < T >::printPreorderHelper(Node* p)
{
    if (p != 0)
    {
        cout << p->data << " ";
        printPreorderHelper(p->left);
        printPreorderHelper(p->right);
    }
}
//-- 
template < class T >
void BSTree < T >::printPostOrder()
{
    printPostOrderHelper(root);
    cout << endl;
}
//-- 
template < class T >
void BSTree < T >::printPostOrderHelper(Node* p)
{
    if (p != 0)
    {
        printPostOrderHelper(p->left);
        printPostOrderHelper(p->right);
        cout << p->data << " ";
    }
}
//--
template < class T >
T BSTree < T >::max(Node* p)
{
    Node* p_largest = p;

    while (p_largest->right != 0)
    {
        p_largest = p_largest->right;
    }

    return p_largest->data;
}
//--
template < class T >
T BSTree < T >::max()
{
    if (root == 0)
    {
        throw "Tree Empty";
    }

    return max(root);
}
//--
template < class T >
T BSTree < T >::min(Node* p)
{
    Node* p_smallest = p;

    while (p_smallest->left != 0)
    {
        p_smallest = p_smallest->left;
    }

    return p_smallest->data;
}
//--
template < class T >
T BSTree < T >::min()
{
    if (numberOfElements == 0)
    {
        throw "Tree Empty";
    }

    return min(root);
}
//--
template < class T >
void BSTree < T >::search(Node* p, const T& d, bool& isFound)
{
    if (p != 0 && isFound == false)
    {
        if (p->data == d)
        {
            isFound = true;
            return;
        }

        search(p->left, d, isFound);
        search(p->right, d, isFound);
    }
}
//--
template < class T >
bool BSTree < T >::search(const T& d)
{
    bool isFound = false;
    search(root, d, isFound);
    return isFound;
}
//--
template < class T >
void BSTree < T >::count(Node* p, const T& d, int& numOccurrences)
{
    if (p != 0)
    {
        if (p->data == d)
        {
            numOccurrences++;
        }

        count(p->left, d, numOccurrences);
        count(p->right, d, numOccurrences);
    }
}
//--
template < class T >
int BSTree < T >::count(const T& d)
{
    int numOccurrences = 0;
    count(root, d, numOccurrences);
    return numOccurrences;
}
//--
template < class T >
void BSTree < T >::heightOfTree(Node* p, int currentHeight, int& maxHeight)
{
    if (p != 0)
    {
        currentHeight++;

        if (currentHeight > maxHeight)
        {
            maxHeight = currentHeight;
        }

        heightOfTree(p->left, currentHeight, maxHeight);
        heightOfTree(p->right, currentHeight, maxHeight);
    }
}
//--
template < class T >
int BSTree < T >::heightOfTree()
{
    int maxHeight = 0;
    heightOfTree(root, 0, maxHeight);
    return maxHeight;
}
//--
template < class T >
void BSTree < T >::percentLeaf(Node* p, int& numLeaves)
{
    if (p != 0)
    {
        if (p->left == 0 && p->right == 0)
        {
            numLeaves++;
        }
        percentLeaf(p->right, numLeaves);
        percentLeaf(p->left, numLeaves);
    }
}
//--
template < class T >
double BSTree < T >::percentLeaf()
{
    int numLeaves = 0;
    percentLeaf(root, numLeaves);
    return (double)numLeaves / (double)numberOfElements;
}
//--
template < class T >
double BSTree < T >::percentInterior()
{
    return 1.0 - percentLeaf();
}
//--
template < class T >
void BSTree < T >::remove(Node*& p, const T& d)
{
    if (p != 0)
    {
        if (p->data == d)
        {
            if (p->left == 0 && p->right == 0)
            {
                //leaf
                delete p;
                p = 0;
            }
            else if (p->left == 0)
            {
                //one child: right
                Node* p_next = p->right;
                delete p;
                p = p_next;
            }
            else if (p->right == 0)
            {
                //one child: left
                Node* p_next = p->left;
                delete p;
                p = p_next;
            }
            else
            {
                //two children
                p->data = max(p->left);
                remove(p->left, p->data);
            }
            numberOfElements--;
        }
        else
        {
            remove(p->left, d);
            remove(p->right, d);
        }
    }
}
//--
template < class T >
void BSTree < T >::remove(const T& d)
{
    remove(root, d);
}

