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
//////////////////////////////////
    void insertion(int data)
    {
        node* newn=creat_new_nosde(data);
        if(root =NULL)
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
    ////////////////////////////////////
};
int main()
{
    bainaryTree n;
    n.build_bainary_tree();
    //n.insertion(8);
    // n.dfsTreversa(n.root);

    n.bfsTreversa();
    return 0;
}
