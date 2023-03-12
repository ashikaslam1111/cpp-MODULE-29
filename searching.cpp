#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int id;
    int value;
    node* left;
    node* right;
    node* parent;
};
class bainaryTree
{
public:
    node* root;
    bainaryTree()
    {
        root=NULL;
    }
    node* creat_new_nosde(int id,int value)
    {
        node* newnode=new node;
        newnode->id=id;
        newnode->value=value;
        newnode->left=NULL;
        newnode->right=NULL;
        newnode->parent=NULL;
        return newnode;
    }
    void searchh(int value)
    {
        queue<node*> q;
        q.push(root);
        while(!q.empty())
        {
            node* a=q.front();
            q.pop();
            if(a->value==value)cout<<a->id<<" ";
            if(a->left != NULL)
            {
                q.push(a->left);
            }
            if(a->right != NULL)
            {
                q.push(a->right);
            }
        }
    }
    void insertion(int id,int value)
    {
        node* newn =creat_new_nosde(id,value);
        if(root ==NULL)
        {
            root=newn;
            return;
        }
        queue<node*> q;
        q.push(root);
        while(!q.empty())
        {
            node* a=q.front();
            q.pop();
            if(a->left != NULL)
            {
                q.push(a->left);
            }
            else
            {
                a->left=newn;
                newn->parent=a;
                return;
            }
            if(a->right != NULL)
            {
                q.push(a->right);
            }
            else
            {
                a->right=newn;
                newn->parent=a;
                return;
            }
        }
    }
};
int main()
{
    bainaryTree n;
    n.insertion(0,5);
    n.insertion(1,5);
    n.insertion(2,10);
    n.insertion(3,12);
    n.insertion(4,10);
    n.searchh(10);
    return 0;
}

