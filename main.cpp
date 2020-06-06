#include <iostream>
using namespace std;

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;

void insert(int element)
{
    struct Node *p=root;
    struct Node *q,*tmp;
    tmp= new Node;
    tmp->data=element;
    tmp->lchild=tmp->rchild=NULL;
    if(root==NULL)
    {
        root=tmp;
    }
    else
    {
        while(p!=NULL)
        {
            q=p;
            if(p->data==element)
            {
                return;
            }
            else if(element < p->data)
            {
                p=p->lchild;
            }
            else{
                p=p->rchild;
            }
        }
        if(element > q->data)
        {
            q->rchild=tmp;
        }
        else
            q->lchild=tmp;
    }
}

void Search(Node *p,int key)
{
    if(p==NULL)
    {
        cout << " BST is empty" << endl;
    }
    else{
        while(p!=NULL)
        {
            if(p->data==key)
            {
                cout << "Element is found" << endl;
                return;
            }
            else if(key < p->data)
            {
                p=p->lchild;
            }
            else{
                p=p->rchild;
            }
        }
    }
    cout << "Element not found "<<endl;
        
}

void InOrder(Node *p)
{
    if(p)
    {
        InOrder(p->lchild);
        cout << p->data << " ";
        InOrder(p->rchild);
    }

}

int Height(Node *p)
{
int x,y;
if(p==NULL)return 0;
x=Height(p->lchild);
y=Height(p->rchild);
return x>y?x+1:y+1;
}

struct Node * InOrderpredecssor(Node *p)
{
    while(p && p->rchild!=NULL)
    {
        p=p->rchild;
    }
    return p;
}

struct Node * InOrderSuccessor(Node *p)
{
    while(p && p->lchild!=NULL)
    {
        p=p->lchild;
    }
    return p;
}

struct Node * Delete(Node *p,int key)
{
    struct Node *q;
    if(p==NULL)
    {
        return NULL;
    }
    if(p->lchild==NULL && p->rchild==NULL)
    {
        delete p;
        return NULL;
    }
    if(key < p->data)
    {
        p->lchild=Delete(p->lchild,key);
    }
    else if(key > p->data)
    {
        p->rchild=Delete(p->rchild,key);
    }
    else
    {
        if(Height(p->lchild) > Height(p->rchild))
        {
            q=InOrderpredecssor(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q=InOrderSuccessor(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
            
        }
    }
return p;
}

int main()
{
    int Num,data,searchdata;
    cout << "Enter Number of data to be instered in BST: "<<endl;
    cin >> Num;
    cout <<"Enter the node values: " << endl;
    for(int i=0;i<Num;i++)
    {
        cin >> data;
        insert(data);
    }
    cout <<"Elements in BST are: "<< endl;
    InOrder(root);
    cout << endl;
    cout << "Enter any node value to search in BST:" << endl;
    cin >> searchdata;
    Search(root,searchdata);
    cout <<"Enter the value to be deleted in BST: " << endl;
    cin >> data;
    Delete(root,data);
    cout << "After deleting Node: " << endl;
    InOrder(root);
    cout << endl;
    return 0;
}