#include <bits/stdc++.h>
#define N 100
using namespace std;
class Student
{
    char name[N];
    int rno;
    int year;
    int division;
    char address[N];
    friend class FileOperations;
    public:	Student()
    		{
   				strcpy(name,"");
   				rno=year=division=0;
   				strcpy(address,"");
    		}
    		Student(char name[N],int rno,int year,int division,char address[N])
    		{
    			strcpy(this->address,address);
    			strcpy(this->name,name);
    			this->division=division;
    			this->rno=rno;
    			this->year=year;
    		}
    		int getrno()
    		{
    			return rno;
    		}
    		void displayStudentData()
    		{
    			cout<<endl<<setw(3)<<rno<<setw(10)<<name<<setw(3)<<year<<setw(2)<<division<<setw(10)<<address;
    		}
};
class FileOperations
{
	fstream file;
	public:FileOperations(char *name)
		   {
			 this->file.open(name,ios::in|ios::out|ios::ate|ios::binary);
		   }
		   void insertRecord(int rno,char name[N],int year,int division,char address[N])
		   {
			   Student s=Student(name,rno,year,division,address);
			   file.seekp(0,ios::end);
			   file.write((char*)&s,sizeof(Student));
			   file.clear();
		   }
		   void displayAllRecords()
		   {
			   Student s;
			   file.seekg(0,ios::beg);
			   while(file.read((char *)&s,sizeof(Student)))
			   {
				   s.displayStudentData();
			   }
			   file.clear();
		   }
		   void displayRecord(int rno)
		   {
			   Student s;
			   file.seekg(0,ios::beg);
			   void *p;
			   while(file.read((char *)&s,sizeof(Student)))
			   {
				   if(s.rno==rno)
				   {
					   s.displayStudentData();
					   break;
				   }
			   }
			   if(p==NULL)
				   throw "Element not present";
			   file.clear();
		   }
		   void deleteRecord(int rno)
		   {
			   ofstream newFile("new.txt",ios::binary);
			   file.seekg(0,ios::beg);
			   bool flag=false;
			   Student s;
			   while(file.read((char *)&s,sizeof(s)))
			   {
				   if(s.rno==rno)
				   {
					   flag=true;
					   continue;
				   }
				   newFile.write((char *)&s,sizeof(s));
			   }
			   if(!flag)
			   {
				   cout<<"Element Not Present";
			   }
			   file.close();
			   newFile.close();
			   remove("student.txt");
			   rename("new.txt","student.txt");
			   file.open("student.txt",ios::in|ios::ate|ios::out|ios::binary);
		   }
		   ~FileOperations()
		   {
			   file.close();
			   cout<<"Closing file..";
		   }

};
int  main()
{
	ofstream newFile("student.txt",ios::app|ios::binary);
	newFile.close();
	FileOperations file((char *)"student.txt");
    int rno,year,division,choice=0;
    char name[N],address[N];
    while(choice!=5)
    {
        cout<<"\n*****Phone Book*****\n";
        cout<<"1) Add New Record\n";
        cout<<"2) Display All Records\n";
        cout<<"3) Display by roll no\n";
        cout<<"4) Deleting a Record\n";
        cout<<"5) Exit\n";
        cout<<"Choose your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1 : 
            		cout<<endl<<"Enter roll number:";
            		cin>>rno;
					cout<<endl<<"Enter name :";
					cin.ignore();
					cin.getline(name,N);
            		cout<<"Enter Year and Division : \n";
            		cin>>year>>division;
            		cout<<"Enter address : \n";
            		cin>>address;
            		file.insertRecord(rno,name,year,division,address);
            		break;
            case 2 :
            		file.displayAllRecords();
            		break;
            case 3 :
            		cout<<"Enter Roll Number: ";
            		cin>>rno;
            		try
            		{
            			file.displayRecord(rno);
            		}
            		catch(const char *str)
            		{
            			cout<<str;
            		}
            		break;
            case 4:
            		cout<<"Enter roll no: ";
            		cin>>rno;
            		file.deleteRecord(rno);
            		break;
           case 5 :break;
        }

    }
}
