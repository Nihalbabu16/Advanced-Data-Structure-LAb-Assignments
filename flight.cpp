#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream fin("input.txt",ios::in);
    if(!fin)
    {
        cout<<"FILE OPENING FAILED DUE TO SOME REASON!!!";
        return 0;
    }
    cout<<"TAKING INPUT FROM A FILE ABOUT SOME FLIGHTS...........";
    string s;
    vector<pair<pair<string,string>,int>>adj;
    string src,des;
    int dis;
    set<string> st;
    set<string> ::iterator it;
    while(getline(fin,s))
    {
        src="";
        des="";
        string wt="";
        dis=0;
        int f1=0,f2=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' '&&f1==0)
            {
                src+=s[i];
            }
            else if(s[i]==' '&&f1==0)
            {
                f1=1;
            }
            else if(s[i]!=' '&&f2==0)
            {
                des+=s[i];
            }
            else if(s[i]==' '&&f2==0)
            {
                f2=1;
            }
            else if(s[i]!=' '&&f2==1)
            {
                wt+=s[i];
            }

        }
        st.insert(src);
        int p=0;
        for(int i=wt.size()-1;i>=0;i--)
        {
            dis+=(wt[i]-48)*pow(10,p);
            p++;
        }
        adj.push_back(make_pair(make_pair(src,des),dis));
    }
    fin.close();
    cout<<"INPUT TAKEN SUCCESSFULLY!!!!\n";
    cout<<"DISPLAYING IN FORM OF ADJACENCY LIST.......\n";
    //cout<<"   SOURCE   "<<"     DESTINATION    "<<"    TIME TAKEN(HRS)  ";
    for(it=st.begin();it!=st.end();it++)
    {
        src=*it;
        cout<<src<<" -> ";
        for(int i=0;i<adj.size();i++)
        {
            if(adj[i].first.first==src)
            {
                cout<<adj[i].first.second<<" ("<<adj[i].second<<"hrs)"<<"   ";
            }
        }
        cout<<endl;
    }
    char ch;
    do
    {
        cout<<"Enter your  source:";
        cin>>src;
        cout<<"Enter your destination:";
        cin>>des;
        int flag=0;
        for(int i=0;i<adj.size();i++)
        {
            if(adj[i].first.first==src&&adj[i].first.second==des)
            {
                cout<<"FLIGHT FOUND AND IT TAKES "<<adj[i].second <<" hrs\n";
                flag=1;
                break;

            }
        }
        if(!flag)
        {
            cout<<"NO FLIGHTS FOUND\n";
        }
        cout<<"DO YOU WANT TO CONTINUE(y/n)";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    return 0;
}