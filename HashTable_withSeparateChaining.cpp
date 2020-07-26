#include <iostream>
#include <vector>
using namespace std;
class Entry
{
    public:
    int key;
    string value;
    Entry(int k,string v)
    {
        key=k;
        value=v;
    }
    
};

class HashTable
{
    private:

    vector<vector<Entry*>> table;
    int capacity;
    int threshold;

    public:

    HashTable(int capacity,float loadFactor)
    {
        table.resize(capacity);
        threshold=capacity*loadFactor;
        this->capacity=capacity;
    }
    int hash(int key)
    {
        return key%capacity;
    }

    int add(int key,string value)
    {
        int hashcode = hash(key);
        if(contains(hashcode,key))
            return -1;
        Entry *n = new Entry(key,value);
        table[hashcode].push_back(n);
        return hashcode;
    }
    void display()
    {
        for(int i=0;i<table.size();i++)
        {
            vector<Entry*> e = table[i];
            cout<<i<<"->";

            for(int j=0;j<e.size();j++)
                cout<<"["<<e[j]->key<<","<<e[j]->value<<"]"<<"->";

            cout<<"NULL\n";
        }
    }
    bool contains(int bucketNumber,int key)
    {
        vector<Entry*> bucket = table[bucketNumber];
        for(int i=0;i<bucket.size();i++)
            if(bucket[i]->key==key)
                return true;
        return false;
    }

    ~HashTable()
    {

    }
};

int main()
{
    HashTable a = HashTable(10,0.8);
   a.add(1,"a");
   a.add(45,"bb");
   a.add(22,"asd");
   a.add(100,"1233");
   a.add(200,"asdsd");
   a.display();
   return 0;
}