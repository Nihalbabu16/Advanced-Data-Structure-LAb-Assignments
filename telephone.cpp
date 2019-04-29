#include<bits/stdc++.h>
#define N 100005
using namespace std;
bool visited[N];
int calhash(string tel)
{
    int sum=0;
    for(int i=0;i<tel.size();i++)
    {
        sum+=((tel[i]-48)*(i+1));
    }
    return sum;
}
int main()
{
    vector<pair<string,string> > hashtable[N];
    ifstream fin("tel.txt",ios::in);
    if(!fin)
    {
        cout<<"ERROR OPENING FILE";
    }
    string s;
    while(getline(fin,s))
    {
        string name="",tel="";
        int flag=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' '&&flag==0)
            name+=s[i];
            else if(s[i]==' ')
            flag=1;
            else if(flag==1)
            {
                tel+=s[i];
            }   
        }
        int ind=calhash(tel);
        hashtable[ind].push_back(make_pair(name,tel));
        visited[ind]=true;
    }
    char ch;
    do
    {
        string str;
        cout<<"ENTER TELEPHONE NUMBER TO SEARCH IN HASH TABLE:";
        cin>>str;
        int ind=calhash(str);
        if(visited[ind])
        {
           for(int i=0;i<hashtable[ind].size();i++)
           {
               if(hashtable[ind][i].second==str)
               {
                   cout<<hashtable[ind][i].first<<"\n";
               }
           }
        }
        else
        {
            cout<<"NOT FOUND\n";
        }
        cout<<"Do you want to search more (y/n):";
        cin>>ch;
    } while (ch=='y'||ch=='Y'); 
}