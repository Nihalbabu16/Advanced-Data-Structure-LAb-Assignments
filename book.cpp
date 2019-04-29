#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    int count;
    node* child[15];
};
node* create_sub(int ind)
{
    node* temp=new node;
    temp->data=ind;
    temp->count=0;
    for(int i=0;i<15;i++)
    {
        temp->child[i]=NULL;
    }
    return temp;
}
node* create_sec(int ind)
{
    cout<<"Enter number of subsections in section "<<ind<<" :";
    int n;
    cin>>n;
    node* temp=new node;
    temp->data=ind;
    temp->count=n;
    for(int i=0;i<15;i++)
    {
        temp->child[i]=NULL;
    }
    for(int i=0;i<n;i++)
    {
        temp->child[i]=create_sub(i+1);
    }
    return temp;
}
node* create_chap(int ind)
{
    cout<<"Enter number of sections in chapter "<<ind<<" :";
    int n;
    cin>>n;
    node* temp=new node;
    temp->data=ind;
    temp->count=n;
    for(int i=0;i<15;i++)
    {
        temp->child[i]=NULL;
    }
    for(int i=0;i<n;i++)
    {
        temp->child[i]=create_sec(i+1);
    }
    return temp;

}
node* create_book()
{
    cout<<"Enter numbers of chapters:";
    int val;
    cin>>val;
    node* temp=new node;
    temp->data=1;
    temp->count=val;
    for(int i=0;i<15;i++)
    {
        temp->child[i]=NULL;
    }
    for(int i=0;i<val;i++)
    {
        temp->child[i]=create_chap(i+1);
    }
    return temp;
}
void display(node* ptr)
{
    cout<<"BOOK CONSISTS OF:";
    cout<<ptr->count<<" CHAPTERS";
    cout<<endl;
    cout<<"CHAPTERS ARE:\n";
    for(int i=0;i<ptr->count;i++)
    {
        cout<<"CHAPTER :"<<i+1;
        cout<<"\n";
        cout<<"SECTIONS IN CHAPTER "<<i+1<<" ARE:"<<ptr->child[i]->count<<endl;
        cout<<"They are as follows:";
        cout<<endl;
        for(int j=0;j<ptr->child[i]->count;j++)
        {
            cout<<"SECTION :"<<j+1;
            cout<<"\n";
            cout<<"SUBSECTIONS in section "<<j+1<<" ARE "<<ptr->child[i]->child[j]->count;
            cout<<"\nThey are:";
            for(int k=0;k<ptr->child[i]->child[j]->count;k++)
            {
                cout<<k+1<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
}
int main()
{
    node* root;
    root=create_book();
    display(root);
}