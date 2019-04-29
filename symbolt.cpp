    #include<bits/stdc++.h>
    using namespace std;     
    int main(){
    	
      		string line,iden[100],d;
          string datatype[100];
          string fod[100];
          
      		ifstream fout;
      		fout.open("program.cpp",ios::in);
      		while(getline(fout,line))
    {
        std::istringstream iss(line);
        string s;
        while(1)
        {
        if (iss >> s) 
          { 
            if(s == "int" || s == "float" || s == "double" || s == "void")
            {
              d = s;
              if (iss >> s)
              {
                int ascii = 0;
                for( int i = 0 ; i < s.length() ; i++)
                {
                	ascii += s[i];
                }
                ascii %= 100;
                iden[ascii] = s;
                datatype[ascii] = d;
                if (iss >> s)
                {
                  if(s == "(")
                    fod[ascii] = "fun";
                  else
                    {
                      iss >> s;
                      fod[ascii] = s;
                    }
                  
                }
              }
            }
          }
        else  break;
      }
      }

      cout<<"Enter your query?\n";
      string q,f;
      cin>>q;
      int ascii = 0;
                for( int i = 0 ; i < q.length() ; i++)
                {
                	ascii += q[i];
                }
                ascii %= 100;

      if(fod[ascii] == "fun")
             cout<<q<<" is a function of return type "<<datatype[ascii]<<endl;
      else
           cout<<q<<" is of "<<datatype[ascii]<<" datatype of value =  "<<fod[ascii]<<endl;
     
     return 0;
    }	