#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        Node *down;
        Node();
};

Node::Node()
{
    data=0;
    next=NULL;
    down=NULL;
}

class Skip
{
    vector<Node*> head;
    public:
        void create(vector<int>);
        void search(int);
};

void Skip::create(vector<int>v)
{
    int s,i,j=0,r;
    s=v.size();
    Node *h=NULL;
    while(pow(2,j)<=s)
    {
            Node *t,*b;
        for(i=0;i<s;i+=pow(2,j))
        {
            t=new Node;
            t->data=v[i];
            if(h==NULL)
            {
                h=t;
                b=h;
            }
            else
            {
                b->next=t;
                b=b->next;
            }
        }
        head.push_back(h);
        h=NULL;
        j++;
    }
    Node *y=new Node;
    y->data=v[0];
    head.push_back(y);
    r=head.size();
    for(i=1;i<r;i++)
    {
        Node *st,*p;
        st=head[i];
        p=head[i-1];
        while(st!=NULL)
        {
            st->down=p;
            p=p->next;
            if(p!=NULL)
                p=p->next;
            st=st->next;
        }
    }
}

void Skip::search(int s)
{
    int d,i,f=0;
    d=head.size();
    Node *st;
    st=head[d-1];
    if(st->data>s)
    {
	cout<<"Element not found\n";
	return ;
    }
    while(f==0)
    {
        if(st==NULL)
        {
            cout<<"Element not found\n";
            return;
        }
        if(s==st->data)
        {
            cout<<"Element is found\n";
            f=1;
            break;
        }
        else if(s>st->data)
        {
            if(st->next==NULL||st->next->data>s)
            st=st->down;
            else if(st->next!=NULL)
            st=st->next;
        }
    }
}

 int main()
 {
     Skip sl;
     vector<int> v;
     int x,s;
     char c;
     cout<<"Enter Numbers to insert in skip list:\n";
     while(1)
     {
         cout<<"Enter a number\n";
         cin>>x;
         v.push_back(x);
         cout<<"Do You want to continue(y/n):";
         cin>>c;
         if(c=='n'||c=='N')
         break;
     }
     sort(v.begin(),v.end());
     sl.create(v);
     while(1)
     {
        cout<<"Enter element to search:";
        cin>>s;
        sl.search(s);
        cout<<"Do You want to continue(y/n):";
        cin>>c;
        if(c=='n'||c=='N')
        break;
     }
     
     return 0;
 }
