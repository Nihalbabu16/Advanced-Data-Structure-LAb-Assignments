#include<iostream>
#include<vector>
using namespace std;
#define N 100
class graph
{
    int nodes;
    vector<int> adj[N];
    int am[N][N];
    public:
    graph(int n)
    {
        nodes =n;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++ )
                am[i][j]=0;
        }
    }
    void addedgeal(int src,int des);
    void addedgebyam(int src,int des);
    void display();
};

void graph :: addedgeal(int src,int des)
{
    adj[src].push_back(des);
    adj[des].push_back(src);
}
void graph :: addedgebyam(int src,int des)
{
    am[src][des]=1;
    am[des][src]=1;
}
void graph:: display()
{
    cout<<"The adjacency list representation is:";
    cout<<endl;
    for(int i=1;i<=nodes;i++)
    {
        cout<<i<<" -> ";
        for(int j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j];
            if(j<adj[i].size()-1)
            cout<<",";

        }
        cout<<"\n";
    }
    cout<<"The adjacency matrix representation is:";
    cout<<endl;
    for(int i=1;i<=nodes;i++)
    {
        for(int j=1;j<=nodes;j++)
        {
            cout<<am[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    cout<<"Enter number of vertices:";
    int n;
    cin>>n;
    graph g(n);
    char ch;
    cout<<"Please enter the vertices between whom the edge exit:";
    do 
    {
        int x,y;
        cin>>x>>y;
        g.addedgeal(x,y);
        g.addedgebyam(x,y);
        cout<<"Do you want to enter more(y/n):";
        cin>>ch;
    } while(ch=='y'||ch=='Y');
    g.display();
    
}
