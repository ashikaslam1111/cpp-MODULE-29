#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int id;
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
    node* creat_new_nosde(int id)
    {
        node* newnode=new node;
        newnode->id=id;
        newnode->left=NULL;
        newnode->right=NULL;
        newnode->parent=NULL;
        return newnode;
    }
    void build_bainary_tree()
    {
        node* ar[6]; //  whey it is node* ar[6] whey not node ar[6]
        for(int i=0; i<6; i++)
        {
            ar[i]=  creat_new_nosde(i);
        }
        ar[0]->left=ar[1];
        ar[0]->right=ar[2];

        ar[1]->left=ar[5];
        ar[1]->parent=ar[0];

        ar[2]->left=ar[3];
        ar[2]->right=ar[4];
        ar[2]->parent=ar[0];

        ar[5]->parent=ar[1];

        ar[3]->parent=ar[2];

        ar[4]->parent=ar[2];
        root=ar[0];
    }
    void bfsTreversa()
    {
        queue<node*> q;
        q.push(root);
        while(!q.empty())
        {
            node* a=q.front();
            int p=-1,l=-1,r=-1;
            q.pop();
            if(a->parent != NULL)p=a->parent->id;
            if(a->left != NULL)
            {
                l=a->left->id;
                q.push(a->left);
            }
            if(a->right != NULL)
            {
                r=a->right->id;
                q.push(a->right);
            }
            cout<<"node"<<a->id<<" prarent  = "<<p<<" left = "<<l<<" right = "<<r<<endl;
        }
    }
    void dfsTreversa(node* a)
    {
        if(a==NULL)
        {
            return;
        }
        cout<<a->id<<" ";
        dfsTreversa(a->left);
        dfsTreversa(a->right);
    }
    void inordTreversa(node* a)//left+root+right
    {
        if(a==NULL)
        {
            return;
        }
        inordTreversa(a->left);
        cout<<a->id<<" ";
        inordTreversa(a->right);
    }
    void preoderTreversa(node* a)
    {
        if(a==NULL)
        {
            return;
        }
        cout<<a->id<<" ";
        preoderTreversa(a->left);
        preoderTreversa(a->right);
    }
    void postoderTreversa(node* a)//reft+right+root
    {
        if(a==NULL)
        {
            return;
        }
        postoderTreversa(a->left);
        postoderTreversa(a->right);
        cout<<a->id<<" ";
    }
};
int main()
{
    bainaryTree n;
    n.build_bainary_tree();
    n.postoderTreversa(n.root);
    return 0;
}

