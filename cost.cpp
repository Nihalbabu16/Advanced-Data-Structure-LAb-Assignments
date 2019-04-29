#include<bits/stdc++.h>
#define MAX 100
using namespace std;
int arr[MAX];
void init()
{
    for(int i = 0;i < MAX;++i)
        arr[i] = i;
}

int root(int x)
{
    while(arr[x] != x)
    {
        arr[x] = arr[arr[x]];
        x = arr[x];
    }
    return x;
}

void Union(int x, int y)
{
    int p = root(x);
    int q = root(y);
    arr[p] = arr[q];
}
int kruskal(pair<int,pair<int,int>> p[],int edges)
{
    int x, y;
    int cost, mc = 0;
    for(int i = 0;i < edges;++i)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(root(x) != root(y))
        {
            cout<<x<<"-> "<<y<<"("<<cost<<")"<<endl;
            mc += cost;
            Union(x, y);
        }    
    }
    return mc;
}
int main()
{
    ifstream fin("file.txt",ios::in);
    if(!fin)
    {
        cout<<"ERROR OPENING FILE";
        return 0;
    }
    init();
    string s;
    string a="",b="",c="";
    pair<int,pair<int,int>> v[MAX];
    int edges=0;
    cout<<"THE EDGES IN THE GRAPH  AND THEIR WEIGHT ARE:";
    cout<<endl;
    while(getline(fin,s))
    {
        a="";
        b="";
        c="";
        int src=0,des=0,cs=0;
        int f1=0,f2=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' '&&f1==0)
            {
                a+=s[i];
            }
            else if(s[i]==' '&&f1==0)
            {
                f1=1;
            }
            else if(s[i]!=' '&&f2==0)
            {
                b+=s[i];
            }
            else if(s[i]==' '&&f2==0)
            {
                f2=1;
            }
            else if(s[i]!=' '&&f2==1)
            {
                c+=s[i];
            }
        }
        int p=0;
        for(int i=a.size()-1;i>=0;i--)
        {
            src+=(a[i]-48)*pow(10,p);
            p++;
        }
        p=0;
        for(int i=b.size()-1;i>=0;i--)
        {
            des+=(b[i]-48)*pow(10,p);
            p++;
        }
        p=0;
        for(int i=c.size()-1;i>=0;i--)
        {
            cs+=(c[i]-48)*pow(10,p);
            p++;
        }
        v[edges]=make_pair(cs,make_pair(src,des));
        cout<<src<<"-> "<<des<<" ("<<cs<<")"<<endl;
        edges++;
    }
    sort(v,v+edges);
    int mincost;
    cout<<"THE EDGES SELECTED ARE:";
    cout<<endl;
    mincost = kruskal(v,edges);
    cout<<"THE MINIMUM COST IN CONNECTING ALL OFFICES IS:";
    cout << mincost << endl;
    return 0;
}