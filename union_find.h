#include <iostream>
#include <vector>
using namespace std;
class UnionFind
{
    private:
        vector<int> id;
        vector<int> sz;
        int nc;
    public:
        UnionFind(int);
        int find(int);
        bool connected(int,int);
        int compSize(int);
        bool unify(int,int);
        int compCount();
        void disp();
};