#include <iostream>
using namespace std;
class TBT;
class Node
{
    Node *l,*r;
    int data;
    bool rt,lt;
public:
    Node()
    {
        data=0;
        l=NULL;
        r=NULL;
        rt=lt=0;
    }
    Node(int d)
    {
        l=NULL;
        r=NULL;
        rt=lt=0;
        data=d;
    }
    friend class TBT;
};
class TBT
{
     Node *root; //Temporary node
     public:
     TBT() //Temporary node initialization
     {
         root=new Node(65739);
         root->l=root->r=root;
         root->rt=1; //child
         root->lt=0; //threaded connection
     }
     void create();
     void insert(int data);
     Node *inordsuc(Node *);
     void inorder();
     Node *preordsuc(Node *c);
     void preorder();
};
void TBT::preorder()
{
    Node *c=root->l;
    while(c!=root)
    {
        cout<<" "<<c->data;
        c=preordsuc(c);
    }
}
Node *TBT::preordsuc(Node *c)
{
    if(c->lt==1)
    {
        return c->l;
    }
    while(c->rt==0)
    {
        c=c->r;
    }
    return c->r;
}
void TBT::inorder()
{
    Node *c=root->l;
    while(c->lt==1)
        c=c->l;
    while(c!=root)
    {
        cout<<" "<<c->data;
        c=inordsuc(c);
    }
}
Node* TBT::inordsuc(Node *c)
{
    if(c->rt==0)
        return c->r;
    else
        c=c->r;
    while(c->lt==1)
    {
        c=c->l;
    }
    return c;
}
void TBT::create()
{
    int n;
    cout<<"\nHow many no. of nodes do you want to insert: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
         int info;
         cout<<"\nPlease enter the data to be inserted: ";
         cin>>info;
         insert(info);
    }
}
void TBT::insert(int data)
{
    if(root->l==root&&root->r==root) //when there is no node
    {
        Node *p=new Node(data);
        p->l=root->l;
        p->lt=root->lt; 
        p->rt=0;
        p->r=root->r;
        root->l=p;
        root->lt=1;
        cout<<"\nInsertion started successfully.\n Data inserted is:"<<data<<endl;
        return;
     }
     Node *curr;//new node;
     curr=root->l; //first node inserted in the tree
     while(1)
     {
         int ch;
         cout<<"Press 1:Insert on left \nPress 2:Insert on right\nEnter your choice:"<<endl;
         cin>>ch;
         if(ch==2)   //For insertion on right
         {
             if(curr->rt==0)
             {
                 Node *p=new Node(data);
                p->r=curr->r;
                p->l=curr;
                 curr->r=p;
                 curr->rt=1;
                 cout<<data<<" is inserted on the right successfully. "<<endl;
                 return;
             }
             else
                 curr=curr->r;
         }
         if(ch==1) //For insertion on left
         {
              if(curr->lt==0)
              {
                  Node *p=new Node(data);
                  p->l=curr->l;
                  p->r=curr;
                 curr->l=p;
                  curr->lt=1;
                  cout<<data<<" is inserted on the left successfully. "<<endl;
                  return;
               }
             else
                 curr=curr->l;
         }
     }
}
int main()
{
    TBT ob;
    int v,choice;
    cout<<"***Threaded Binary Tree***\n";
    cout<<"\nCreating Tree\n";
    ob.create();
    do
    {
        cout<<"\nTBT operations\n";
        cout<<"1.Insert \n2.Preorder traversal\n3.Inorder traversal\n4.Exit"<<endl;
        cout<<"Enter Your Choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"\nEnter data you want to insert: "<<endl;
                cin>>v;
                ob.insert(v);
                break;
            case 2:
                cout<<"\nPreorder traversal is: ";
                ob.preorder();
                break;
            case 3:
                cout<<"\nInorder traversal is: ";
                ob.inorder();
                break;
            case 4:
                cout<<"Thank you for using TBT\n";
                cout<<"---------PROGRAM ENDS---------";
                exit(0);
            default:
                cout<<"\nInvalid Input\n";
                break;
        }


    }while(choice=1);
    return 0;
}