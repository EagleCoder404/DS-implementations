#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>
using namespace std;

int main() {
    priority_queue<int,vector<int>,greater<int>> a;
	int t,n,k,temp;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
	    scanf("%d",&n);
	    for(int j=0;j<n;j++)
	   {
	       scanf("%d",&temp);
	       a.push(temp);
	   }
	   scanf("%d",&k);
	   for(int l=0;l<k-1;l++)
	    a.pop();
	   printf("%d\n",a.top());
    }
	return 0;
}