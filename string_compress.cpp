#include <iostream>
#include <map>
#include <string>
using namespace std;

string compress(string o)
{
    map<int,int> char_freq;
    int i,j;
    for(i=0;i<o.length();)
    {
        char_freq[i]+=1;
        for(j=i+1;(j<o.length()) && (o[j]==o[i]);j++)
            char_freq[i]+=1;
        i=j;
    }
    if(char_freq.size()*2 > o.length())
        return o;
    else
    {
        string result="";
        for(auto x:char_freq)
        {
            result+=o[x.first];
            result+=to_string(x.second);
        }
        return result;
    }
}
int main()
{
    cout<<""<<compress("aaannnnnaaab")<<endl;
}