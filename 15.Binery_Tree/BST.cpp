#include<iostream>
using namespace std;

struct node
{
    node* left;
    int item;
    node* right;
};
class BST
{
    private:
        node *root;
    protected:
        void preorderrec(node *);
        void inorderrec(node *);
        void postorderrec(node *);
        node* deleteNode(node *,int);
    public:
        BST();  
        bool isEmpty();
        void insert(int);
        void inorder();
        void preorder();
        void postorder();
        node* getRoot();
        node* search(int);
        void del(int);
        void delrec(int);
        ~BST();
};
node* BST::deleteNode(node* ptr,int data)
{
    if(ptr==NULL)
        return NULL;
    if(data<ptr->item)
        ptr->left=deleteNode(ptr->left,data);
    else if(data>ptr->item)
        ptr->right=deleteNode(ptr->right,data);
    else
    {
        if(ptr->left==NULL && ptr->right==NULL)
        {
            delete ptr;
            return NULL;
        }
        if(ptr->left==NULL || ptr->right== NULL)
        {
            node *child=ptr->left?ptr->left:ptr->right;
            delete ptr;
            return child;
        } 

        node* pred,*parpred;
        parpred=ptr;
        pred=ptr->left;
        while(pred->right!=NULL)
        {
            parpred=pred;
            pred=pred->right;
        }
        ptr->item=pred->item;
        if(parpred->right)
            parpred->right=deleteNode(pred,pred->item);
        else
            parpred->left=deleteNode(pred,pred->item);        
    }
    return ptr;
}
void BST::delrec(int data)
{
    root=deleteNode(root,data);
}
BST::~BST()
{
    while(root)
        del(root->item);
}
void BST::del(int data)
{
    if(root)
    {
        node *t,*p=NULL;
        t=root;
        while(t)
        {
            if(t->item==data)
                break;
            p=t;
            if(data>t->item)
                t=t->right;
            else
                t=t->left;
        }
        if(t==NULL)
            cout<<"Element Does'nt Exist!\n";
        else
        {
            if(t->right==NULL)
            {
                if(t->left==NULL)
                {
                    if(p==NULL)
                        root=NULL;
                    else
                    {
                        if(t==p->left)
                            p->left=NULL;
                        else
                            p->right=NULL;
                    }
                }
                else
                {
                    p=t;
                    node *q=NULL;
                    t=t->left;
                    while(t->right)
                    {
                        q=t;
                        t=t->right;
                    }
                    if(q)
                    {
                        p->item=t->item;
                        q->right=NULL;
                        if(t->left)
                            q->right=t->left;
                    }
                    else
                    {
                        p->item=p->left->item;
                        p->left=t->left;
                    }
                }
            }
            else
            {
                p=t;
                node *q=NULL;
                t=t->right;
                while(t->left)
                {
                    q=t;
                    t=t->left;
                }
                if(q)
                {
                    p->item=t->item;
                    q->left=NULL;
                    if(t->right)
                        q->left=t->right;
                }
                else
                {
                    p->item=p->right->item;
                    p->right=t->right;
                }
            }
            delete t;
        }
    }
    else
        cout<<"Underflow\n";
}
node* BST::search(int data)
{
    node *t;
    t=root;
    while(t)
    {
        if(t->item==data)
            return t;
        if(data>t->item)
            t=t->right;
        else
            t=t->left;
    }
    cout<<"Item Not Found!\n";
    return NULL;
}
node* BST::getRoot()
{
    return root;
}

void BST::insert(int data)
{
    node* n=new node;
    n->item=data;
    n->left=NULL;
    n->right=NULL;
    if(root==NULL)
        root=n;
    else
    {
        node *t,*p;
        t=root;
        while(t)
        {
            p=t;
            if(t->item==data)
            {
                delete n;
                return;
            }
            else if(n->item<t->item)
                t=t->left;
            else
                t=t->right;
        }
        if(p->left==NULL)
        {
            if(p->right==NULL)
            {
                if(n->item>p->item)
                    p->right=n;
                else
                    p->left=n;
            }
            else
                p->left=n;
        }
        else
            p->right=n;
    }
}
bool BST::isEmpty()
{
    return root==NULL;
}
BST::BST()
{
    root=NULL;
}
void BST::postorderrec(node *ptr)
{
    if(ptr)
    {
        postorderrec(ptr->left);
        postorderrec(ptr->right);
        cout<<ptr->item<<" ";
    }
}
void BST::postorder()
{
    postorderrec(root);
}
void BST::inorderrec(node *ptr)
{
    if(ptr)
    {
        inorderrec(ptr->left);
        cout<<ptr->item<<" ";
        inorderrec(ptr->right);
    }
}
void BST::inorder()
{
    inorderrec(root);
}
void BST::preorderrec(node *ptr)
{
    if(ptr)
    {
        cout<<ptr->item<<" ";
        preorderrec(ptr->left);
        preorderrec(ptr->right);
    }
}
void BST::preorder()
{
    preorderrec(root);
}
// void preorder(node *root)
// {
//     if(root)
//     {
//         cout<<root->item<<" ";
//         preorder(root->left);
//         preorder(root->right);
//     }
// }

// void inorder(node *root)
// {
//     if(root)
//     {
//         inorder(root->left);
//         cout<<root->item<<" ";
//         inorder(root->right);
//     }
// }

// void postorder(node *root)
// {
//     if(root)
//     {
//         postorder(root->left);
//         postorder(root->right);
//         cout<<root->item<<" ";
//     }
// }
int main()
{
    BST T;
    T.insert(50);
    T.insert(30);
    T.insert(70);
    T.insert(20);
    T.insert(40);
    T.insert(80);
    T.insert(15);
    T.insert(25);
    T.insert(35);
    T.insert(45);
    T.insert(75);
    T.insert(85);
    T.insert(78);
    T.inorder();
    T.delrec(70);
    cout<<"\n";
    T.inorder();
    T.delrec(50);
    cout<<"\n";
    T.inorder();
    T.delrec(15);
    cout<<"\n";
    T.inorder();
    T.delrec(75);
    cout<<"\n";
    T.inorder();
    T.delrec(85);
    cout<<"\n";
    T.inorder();
    T.delrec(78);
    cout<<"\n";
    T.inorder();
    T.delrec(30);
    cout<<"\n";
    T.inorder();
    T.delrec(20);
    cout<<"\n";
    T.inorder();
    T.delrec(40);
    cout<<"\n";
    T.inorder();
    T.delrec(45);
    cout<<"\n";
    T.inorder();
    T.delrec(25);
    cout<<"\n";
    T.inorder();
    T.delrec(35);
    cout<<"\n";
    T.inorder();
    T.delrec(80);
    cout<<"\n";
    T.inorder();
    return 0;
}