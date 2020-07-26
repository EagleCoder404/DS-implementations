#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Node
{
    public:
    Node *left;
    Node *right;
    int data;
    Node(Node *l,Node *r,int d)
    {
        left=l;
        right=r;
        data=d;
    }
};

class BST
{
    private:
        Node *root;
    public:
    BST()
    {
        root=NULL;
    }
    Node* getRoot()
    {
        return root;
    }
    void add(int x)
    {
        if(root==NULL)
        {
            root = new Node(NULL,NULL,x);
        }
        else
        {
            Node *cur=root,*prev=NULL;
            while(cur!=NULL)
            {
                prev=cur;
                if(x<cur->data)
                    cur=cur->left;
                else
                    cur=cur->right;
            }
            if(x < prev->data)
                prev->left = new Node(NULL,NULL,x);
            else
                prev->right = new Node(NULL,NULL,x);
        }      
    }

    void rinorder(Node* c)
    {
        if(c==NULL)
            return;
        else
        {
            
            rinorder(c->left);
            cout<<c->data<<" ";
            rinorder(c->right);
        }
    }

    void ipreorder(Node *c)
    {
        stack<Node*> nodes;
        nodes.push(c);
        while(!nodes.empty())
        {
            Node* cur = nodes.top();
            cout<<cur->data<<" ";
            nodes.pop();
            if(cur->left!=NULL)
                nodes.push(cur->left);
            if(cur->right!=NULL)
                nodes.push(cur->right);
        }
    }
    void iinorder(Node *c)
    {
        stack<Node*> nodes;
        Node* cur = c;
        nodes.push(cur);
        cur = cur->left;
        while(!nodes.empty())
        {
            if(cur!=NULL)
            {    
                nodes.push(cur);
                cur=cur->left;
                break;
            }
            else
            {
                cur = nodes.top();
                cout<<cur->data<<" ";
                nodes.pop();
                cur=cur->right;
            }
        }
    }

};

int main()
{
    BST a = BST();
    a.add(6);
    a.add(5);
    a.add(4);
    a.add(10);
    a.add(11);

    a.rinorder(a.getRoot());
    return 0;
}