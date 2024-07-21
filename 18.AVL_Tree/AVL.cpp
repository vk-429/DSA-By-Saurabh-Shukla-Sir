#include<iostream>
#include<algorithm>
using namespace std;

struct node
{
    node* left;
    int item;
    int hight;
    node* right;
};

class AVL
{
    private:
        node* root;
    protected:
        void preorderrec(node *);
        void inorderrec(node *);
        void postorderrec(node *);
        node *insertion(node*,int);
        node* deletion(node *,int);
    public:
        AVL();
        int getBF(node*);
        node* rightRotate(node*);
        node* leftRotate(node*);
        void inorder();
        void preorder();
        void postorder();
        void insert(int);
        void del(int);
        node* search(int);
        int getHight(node*);
        node* minValueNode(node *);
        void updateAnscestorsHeights(node*,int);
        ~AVL();
};


void AVL::updateAnscestorsHeights(node *ptr,int data)
{    
    if(data == ptr->item)
        ptr->hight=1;
    else
    {
        if(data < ptr->item)
        {
            updateAnscestorsHeights(ptr->left,data);
        }
        else if(data > ptr->item)
        {
            updateAnscestorsHeights(ptr->right,data);
        }
        ptr->hight=max(getHight(ptr->left),getHight(ptr->right))+1;
    }
}



node* AVL::insertion(node* ptr, int data) 
{ 
    node *n;
    if(ptr==NULL)
    {
        n=new node;
        n->left=NULL;
        n->item=data;
        n->right=NULL;
        n->hight=1;
        return n;
    }  
    if (data < ptr->item) 
        ptr->left = insertion(ptr->left,data); 
    else if (data > ptr->item) 
        ptr->right = insertion(ptr->right, data); 
    else // Duplicate values not allowed 
        return ptr; 
  
    /* 2. Update height of this ancestor node */
    ptr->hight = 1 + max(getHight(ptr->left), getHight(ptr->right)); 
  
    /* 3. Get the balance factor of this 
        ancestor node to check whether 
        this node became unbalanced */
    int balance = getBF(ptr); 
  
    // If this node becomes unbalanced,
    // then there are 4 cases 
  
    // Left Left Case 
    if (balance > 1 && data < ptr->left->item) 
        return rightRotate(ptr); 
  
    // Right Right Case 
    if (balance < -1 && data > ptr->right->item) 
        return leftRotate(ptr); 
  
    // Left Right Case 
    if (balance > 1 && data > ptr->left->item) 
    { 
        ptr->left = leftRotate(ptr->left); 
        return rightRotate(ptr); 
    } 
  
    // Right Left Case 
    if (balance < -1 && data < ptr->right->item) 
    { 
        ptr->right = rightRotate(ptr->right); 
        return leftRotate(ptr); 
    } 
  
    /* return the (unchanged) node pointer */
    return ptr; 
} 


void AVL::insert(int data)
{
    root=insertion(root,data);
}



node* AVL::search(int data)
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



AVL::~AVL()
{
    while(root)
        del(root->item);
}



void AVL::postorderrec(node *ptr)
{
    if(ptr)
    {
        postorderrec(ptr->left);
        postorderrec(ptr->right);
        cout<<ptr->item<<"("<<getBF(ptr)<<") ";
    }
}



void AVL::postorder()
{
    postorderrec(root);
}



void AVL::inorderrec(node *ptr)
{
    if(ptr)
    {
        inorderrec(ptr->left);
        cout<<ptr->item<<"("<<getBF(ptr)<<") ";
        inorderrec(ptr->right);
    }
}



void AVL::inorder()
{
    inorderrec(root);
}



void AVL::preorderrec(node *ptr)
{
    if(ptr)
    {
        cout<<ptr->item<<"("<<getBF(ptr)<<") ";
        preorderrec(ptr->left);
        preorderrec(ptr->right);
    }
}



void AVL::preorder()
{
    preorderrec(root);
}



node* AVL::minValueNode(node *ptr)
{
    node* current = ptr; 
  
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) 
        current = current->left; 
  
    return current;
}



node* AVL::deletion(node* ptr,int data)
{      
    
    if (ptr == NULL) 
        return ptr; 

    if ( data < ptr->item ) 
        ptr->left = deletion(ptr->left, data);  
    else if( data > ptr->item ) 
        ptr->right = deletion(ptr->right,data); 
    else
    { 
        // node with only one child or no child 
        if( (ptr->left == NULL) || (ptr->right == NULL) ) 
        { 
            node *temp = ptr->left ? ptr->left :ptr->right; 
  
            // No child case 
            if (temp == NULL) 
            { 
                temp = ptr; 
                ptr = NULL; 
            } 
            else // One child case 
                *ptr = *temp; 
            free(temp); 
        } 
        else
        { 
            // node with two children: Get the inorder 
            // successor (smallest in the right subtree) 
            node* temp = minValueNode(ptr->right); 
  
            ptr->item = temp->item; 
  
            // Delete the inorder successor 
            ptr->right = deletion(ptr->right,temp->item); 
        } 
    } 
  
    // If the tree had only one node then return 
    if (ptr == NULL) 
        return ptr; 
  
    
    ptr->hight = 1 + max(getHight(ptr->left),getHight(ptr->right)); 
  
    
    int balance = getBF(ptr);  
  
    // Left Left Case 
    if (balance > 1 && getBF(ptr->left) >= 0) 
        return rightRotate(ptr); 
  
    // Left Right Case 
    if (balance > 1 && getBF(ptr->left) < 0) 
    { 
        ptr->left = leftRotate(ptr->left); 
        return rightRotate(ptr); 
    } 
  
    // Right Right Case 
    if (balance < -1 && getBF(ptr->right) <= 0) 
        return leftRotate(ptr); 
  
    // Right Left Case 
    if (balance < -1 && getBF(ptr->right) > 0) 
    { 
        ptr->right = rightRotate(ptr->right); 
        return leftRotate(ptr); 
    } 
  
    return ptr; 
 
}

void AVL::del(int data)
{
    root=deletion(root,data);
}

node* AVL::rightRotate(node *A)
{
    node *B=A->left;
    node *RT= B->right;

    B->right=A;
    A->left=RT;

    //edit heights
    A->hight=max(getHight(A->left),getHight(A->right))+1;
    B->hight=max(getHight(B->left),getHight(B->right))+1;

    return B;
}
node* AVL::leftRotate(node *A)
{
    node *B=A->right;
    node *LT=B->left;

    B->left=A;
    A->right=LT;

    //edit heights
    A->hight= max(getHight(A->left),getHight(A->right))+1;
    B->hight= max(getHight(B->left),getHight(B->right))+1;

    return B;
}


int AVL::getHight(node* ptr)
{
    if(ptr)
        return ptr->hight;
    return 0;
}


int AVL::getBF(node *ptr)
{
    if(ptr)
        return getHight(ptr->left)-getHight(ptr->right);
    return 0;
}



AVL::AVL()
{
    root=NULL;
}



int main()
{
    AVL tree;
    // tree.insert(50);
    // tree.insert(30);
    // tree.insert(70);
    // tree.insert(90);
    // tree.insert(110);
    // tree.inorder();
    // tree.del(110);
    // cout<<endl;
    // tree.inorder();
    // cout<<endl;
    // tree.del(30);
    // tree.inorder();
    // cout<<endl;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    //tree.insert(60);
    tree.insert(90);
    tree.insert(10);
    //tree.insert(80);
    tree.insert(25);
    tree.insert(45);
    //tree.insert(100);
    tree.inorder();
    cout<<"\n";
    tree.del(70);
    tree.inorder();
    cout<<"\n";
    return 0;
}