#include <iostream>
using namespace std;


bool solve(string s1,string s2)
{
    int n=s1.length();
    for(int i=0;i<n;i++)
    {
        string test =  s1.substr(i,n-i) + s1.substr(0,i);
        if(!test.compare(s2))
            return true;
    }
    return false;
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<solve(s1,s2)<<endl;
    return 0;
}