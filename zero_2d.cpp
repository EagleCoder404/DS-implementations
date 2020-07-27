#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void solve(vector<vector<int>> mat)
{
    vector<int> row;
    row.resize(mat.size());
    vector<int> col;
    col.resize(mat[1].size());

    for(int i=0;mat.size();i++)
        for(int j=0;mat[i].size();j++)
            if(!mat[i][j])
                col[j]=row[i]=1;
        
    for(int i=0;i<row.size();i++)
    {
            
    }

}

int main()
{
    vector<vector<int>> mat;
}