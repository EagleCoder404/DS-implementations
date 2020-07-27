#include <iostream>
using namespace std;

bool check(string s)
{
    int char_freq[26];
    for(int i=0;i<26;i++)
        char_freq[i]=0;

    for(int i=0;i<s.length();i++)
    {
        char alphabet=s[i];
        aplhabet=(c>96)?c-97:c-65;
        
        if(char_freq[c])
            return false;
        else
            char_freq[c]+=1;      
    }
    return true;
}
int main()
{
    string s;
    cin>>s;
    cout<<check(s);
}