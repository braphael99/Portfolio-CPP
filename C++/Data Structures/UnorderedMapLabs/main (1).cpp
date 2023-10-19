#include <iostream>
#include "WordCounter.h"

using namespace std;

void printWords(const vector< pair < string, int > >& words);

int main()
{
    WordCounter wc("/path/to/a/file.txt");
    
    cout<<"Total Word Count: "<<wc.getTotalWordCount()<<endl;
    cout<<"Distinct Word Count: "<<wc.getDistinctWordCount()<<endl;
    
    printWords(wc.getMostUsedWords(10));
    printWords(wc.getMostUsedWords(10, 12));
    printWords(wc.getWordsExactFreq(31));
    
    return 0;
}
//--
void printWords(const vector< pair < string, int > >& words)
{
    for(int i = 0;i < words.size();i++)
    {
        cout<<"Word: '"<<words[i].first<<"' Frequency: "<<words[i].second<<endl;
    }
    cout<<endl;
}