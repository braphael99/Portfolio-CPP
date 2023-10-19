#include <iostream>
#include <string>
#include "StringKeyHashTable.h"

using namespace std;

int main()
{
    cout<<"Hash Table Example"<<endl;
    
    StringKeyHashTable<string> students;
    
    students.insert("Mark", "Mark Mahoney 2.8");
    students.insert("Laura", "Laura Mahoney 3.9");
    students.insert("Buddy", "Buddy Mahoney 3.5");
    students.insert("Patrick", "Patrick Mahoney 3.5");
    
    string key = "Laura";
    string val;
    students.remove(key, val);
    if(students.retrieve(key, val))
    {
        cout<<val<<" was found"<<endl;
    }
    else
    {
        cout<<key<<" was NOT found"<<endl;
    }
    
    cout<<endl;
    vector<string> allKeys = students.getKeys();
    for(int i = 0;i < allKeys.size();i++)
    {
        cout<<allKeys[i]<<" : ";
        students.retrieve(allKeys[i], val);
        cout<<val<<endl;
    }
    
    cout<<endl;
    vector<string> allValues = students.getValues();
    for(int i = 0;i < allValues.size();i++)
    {
        cout<<"Value: "<<allValues[i]<<endl;
    }
    
    return 0;
}
 