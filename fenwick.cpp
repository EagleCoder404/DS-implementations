#include <iostream>
#include <vector>

using namespace std;

class BinaryIndexTree
{
    private:
        vector<int> tree;
    public:

        int lsb(int x)
        {
            return x & -x;
        }

        //values[] should be 1 based vector
        BinaryIndexTree(vector<int> values)
        {
            
            for(int i=0;i<values.size();i++)
                tree.push_back(values[i]);

            for(int i=1;i<values.size();i++)
            {
                int parent = lsb(i)+i;
                if( parent < values.size() )
                    tree[parent] += tree[i];
            }

        }
        int prefixSum(int i)
        {
            int sum=0;
            while(i>0)
            {
                sum+=tree[i];
                i &= ~lsb(i);
            }
            return sum;
        }
        void display()
        {
            for(int i=0;i<tree.size();i++)
            cout<<tree[i]<<" ";
            cout<<endl;
        }

};

int main()
{
    vector<int> i {0,1,2,3,4};

    BinaryIndexTree test(i);

    cout<<test.prefixSum(4)<<endl;
    test.display();
    return 0;
}
