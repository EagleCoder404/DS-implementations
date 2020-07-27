#include <iostream>
#include <vector>

using namespace std;
bool sol(string in)
{
    int cc[26];
    vector<int> ua;

    for(int i=0;i<26;i++)
        cc[i]=0;
    int n=in.length();
    for(int i=0;i<in.length();i++)
    {
        char c= in[i];
        if(c!=' ')
        {
        
            char charcode = (c>96)? c-97:c-65;
            if(!cc[charcode])
            {
                cc[charcode]+=1;
                ua.push_back(charcode);
            }
            else
            {
                cc[charcode]+=1;
            }
        }
        else
            n-=1;
    }


    bool odd_found=0,mode=0;
    int oe;

    if(n&1)
        mode=1;    


    for(int i=0;i<ua.size();i++)
    {
        oe=cc[ua[i]]&1;
        if(mode)
        {
            if(oe==1)
            {
                if(odd_found)
                    return false;
                odd_found=1;
            }
        }
        else
        {
            if(oe==1)
                return false;
        }
    }
    return true;
}

int main()
{
    cout<<sol("ha sha sss");
    return 0;
}