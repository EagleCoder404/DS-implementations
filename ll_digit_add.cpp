#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

void solve(vector<int> h1,vector<int> h2)
{
    int i=0,j=0,n=h1.size(),m=h2.size(),carry=0,sum=0;
    vector<int> ans;
    while(i<n && j<m)
    {
        int l,r;

        l=(i==n)?0:h1[i];
        r=(j==m)?0:h2[j];


        sum=l+r+carry;
        carry=0;
        if(sum>=10)
        {
            carry=1;
            sum-=10;
        }
        ans.push_back(sum);
        sum=0;
        i++;j++;
    }
    if(carry)
        ans.push_back(1);
    
    while(!ans.empty())
    {
        cout<<ans.back()<<" ";
        ans.pop_back();
    }
    cout<<endl;


}

int main()
{
    vector<int> h1 {9,9,9};
    vector<int> h2 {9,9,9};

    solve(h1,h2);
    return 0;
}