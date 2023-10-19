#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

template < class T >
class StringKeyHashTable
{
public:
    StringKeyHashTable();
    StringKeyHashTable(int initSize);
    ~StringKeyHashTable();
    void insert(const string& key, const T& value);
    bool retrieve(const string& key, T& value);
    bool remove(const string& key, T& value);
    vector<string> getKeys();
    vector<T> getValues();
    bool isEmpty();
    int size();
private:
    struct KeyValuePair
    {
        string key;
        T value;
    };
    
    vector < vector < KeyValuePair* > > table;
    int numElements;
    int sizeOfTable;
    
    int hash(const string& key);
    int findNextPrime(int primeCandidate);
    bool isPrime(int primeCandidate);
    void resize(int requestedSize);
};
//--
template < class T >
StringKeyHashTable< T >::StringKeyHashTable()
{
    numElements = 0;
    sizeOfTable = 101;
    table.resize(sizeOfTable);
}
//--
template < class T >
StringKeyHashTable< T >::StringKeyHashTable(int initSize)
{
    numElements = 0;
    sizeOfTable = findNextPrime(initSize);
    table.resize(sizeOfTable);
}
//--
template < class T >
StringKeyHashTable< T >::~StringKeyHashTable()
{
    for(int i = 0;i < table.size();i++)
    {
        for(int j = 0;j < table[i].size();j++)
        {
            delete table[i][j];
        }
    }
}
//--
template < class T >
void StringKeyHashTable< T >::insert(const string& key, const T& value)
{
    if(numElements >= int(.9 * (double)sizeOfTable))
    {
        resize(2 * sizeOfTable);
    }
    
    KeyValuePair* newKV = new KeyValuePair;
    newKV->key = key;
    newKV->value = value;
    
    int insertPos = hash(key);
    table[insertPos].push_back(newKV);
    
    numElements++;
}
//--
template < class T >
bool StringKeyHashTable< T >::retrieve(const string& key, T& value)
{
    int retrievePos = hash(key);
    bool retVal = false;
        
    for(int i = 0;i < table[retrievePos].size();i++)
    {
        if(key == table[retrievePos][i]->key)
        {
            value = table[retrievePos][i]->value;
            retVal = true;
            break;
        }
    }
    return retVal;
}
//--
template < class T >
bool StringKeyHashTable< T >::remove(const string& key, T& value)
{
    int retrievePos = hash(key);
    bool retVal = false;
        
    for(int i = 0;i < table[retrievePos].size();i++)
    {
        if(key == table[retrievePos][i]->key)
        {
            value = table[retrievePos][i]->value;
            delete table[retrievePos][i];
            table[retrievePos].erase(table[retrievePos].begin() + i);
            retVal = true;
            numElements--;
            break;
        }
    }
    return retVal;
}
//--
template < class T >
bool StringKeyHashTable< T >::isEmpty()
{
    return size() == 0;
}
//--
template < class T >
int StringKeyHashTable< T >::size()
{
    return numElements;
}
//--
template < class T >
int StringKeyHashTable< T >::hash(const string& key)
{
    unsigned int accumulator = 1;
    for(int i = 0;i < key.size();i++)
    {
        accumulator = (accumulator * 33) + int(key[i]);
    }
    return accumulator % sizeOfTable;
}
//--
template < class T >
int StringKeyHashTable< T >::findNextPrime(int primeCandidate)
{
    int retVal = primeCandidate;
    while(isPrime(retVal) == false)
    {
        retVal++;
    }
    return retVal;
}
//--
template < class T >
bool StringKeyHashTable< T >::isPrime(int primeCandidate)
{
    bool retVal = true;
    for(int i = 2;i < int(sqrt(primeCandidate) + 1.0);i++)
    {
        if(primeCandidate % i == 0)
        {
            retVal = false;
            break;
        }
    }
    return retVal;
}
//--
template < class T >
void StringKeyHashTable< T >::resize(int requestedSize)
{
    vector < KeyValuePair* > tempCopy;
    for(int i = 0;i < table.size();i++)
    {
        while(table[i].size() > 0)
        {
            tempCopy.push_back(table[i][table[i].size() - 1]);
            table[i].pop_back();
        }
    }
    
    int newSize = findNextPrime(requestedSize);
    table.resize(newSize);
    sizeOfTable = newSize;
    for(int i = 0;i < tempCopy.size();i++)
    {
        KeyValuePair* oldKVPair = tempCopy[i];
        int newPos = hash(oldKVPair->key);
        table[newPos].push_back(oldKVPair);
    }
}
//--
template < class T >
vector<string> StringKeyHashTable< T >::getKeys()
{
    vector<string> retVal;
    
    for(int i = 0;i < table.size();i++)
    {
        for(int j = 0;j < table[i].size();j++)
        {
            retVal.push_back(table[i][j]->key);
        }
    }
    return retVal;
}
//--
template < class T >
vector<T> StringKeyHashTable< T >::getValues()
{
    vector<T> retVal;
    
    for(int i = 0;i < table.size();i++)
    {
        for(int j = 0;j < table[i].size();j++)
        {
            retVal.push_back(table[i][j]->value);
        }
    }
    return retVal;
}
