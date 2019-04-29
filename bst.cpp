#include<iostream>
using namespace std;
int level[100]={};
class node
{
public:
  int data;
  node *left;
  node *right;
};
void insert(int val,node **ptr)
{
  if(!(*ptr))
  {
    (*ptr)=new node;
    (*ptr)->data=val;
    (*ptr)->left=(*ptr)->right=NULL;
  }
  else if(val<(*ptr)->data)
    insert(val,&(*ptr)->left);
  else if(val>(*ptr)->data)
    insert(val,&(*ptr)->right);
}
bool search(int key,node* ptr)
{
  if(ptr==NULL)
    return 0;
  else if(key<ptr->data)
     search(key,ptr->left);
  else if(key>ptr->data)
    search(key,ptr->right);
  else
    return 1;
}
int minimum(node* ptr)
{
  while(ptr->left!=NULL)
  {
    ptr=ptr->left;
  }
  return (ptr->data);
}
int cnt=0;
void count(node *ptr)
{
  if(ptr==NULL)
    return ;
  count(ptr->left);
  cnt++;
  count(ptr->right);
}
void inorder(node* ptr)
{
  if(ptr==NULL)
    return ;
  inorder(ptr->left);
  cout<<ptr->data<<" ";
  inorder(ptr->right);
}
void lev(node * ptr)
{
  if(ptr==NULL)
    return ;
  if(ptr->left!=NULL)
  {
  level[ptr->left->data]=level[ptr->data]+1;
  lev(ptr->left);
  }
  if(ptr->right!=NULL)
  {
  level[ptr->right->data]=level[ptr->data]+1;
  lev(ptr->right);
  }
}
void mirror(node *ptr)
{
  if(ptr==NULL)
    return;
  mirror(ptr->left);
  mirror(ptr->right);
  node* temp;
  temp=ptr->left;
  ptr->left=ptr->right;
  ptr->right=temp;
}
int main()
{
  int n;
  char ch;
  int choice;
  int key;
  int max=-1;
  node* root=NULL;
  while(1)
  {
  cout<<"1.INSERT\n2.SEARCH\n3.DISPLAY(INORDER)\n4.MINIMUM NODE\n5.COUNT\n6.LEVEL\n7.MIRROR THE TREE\n8.EXIT";
  cout<<"Enter your choice(1-8):";
  cin>>choice;
  switch (choice)
   {
    case 1:cout<<"Enter value for binary search tree:";
           do {
                cin>>n;
                insert(n,&root);
                cout<<"Want to enter more(y/n):";
                cin>>ch;
              } while(ch=='y'||ch=='Y');
            break;
    case 2:cout<<"\nEnter value to be searched:";
           cin>>key;
           if(search(key,root))
           cout<<"\nFOUND\n";
           else
           cout<<"\nNOT FOUND\n";
           break;
    case 3:cout<<"THE INORDER DISPLAY OF THE BST IS:";
          inorder(root);
          cout<<"\n";
          break;
    case 4:cout<<"The minimum element is:";
           cout<<minimum(root);
           cout<<endl;
           break;
    case 5: count(root);
            cout<<"The total nodes present in bst is: ";
            cout<<cnt<<endl;
            break;
    case 6: lev(root);
            for(int i=0;i<100;i++)
            {
              if(level[i]>=max)
              max=level[i];
            }
            cout<<"THE maximum level is :";
            cout<<max<<endl;
            break;
    case 7: mirror(root);
            cout<<"Mirror done successfully\n";
            break;
    case 8: return 0;
    default:cout<<"OOPS WRONG CHOICE!!!";
  }
}
return 0;
}
