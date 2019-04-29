#include<bits/stdc++.h>
using namespace std;
class Heap
{
    private:
        int arr[100];
        int n;
    public:
        void input();
        void max_heapify(int);
        void min_heapify(int);
        void build_max_heap();
        void build_min_heap();
        void output();
};
void Heap :: input()
{
    cout<<"Enter number of students: ";
    cin>>n;
    cout<<"Enter their marks: ";
    for(int i=1;i<=n;i++)
        cin>>arr[i];
}
void Heap :: output()
{
    build_max_heap();
    cout<<"\nThe maximum marks obtained is :";
    cout<<arr[1];
    build_min_heap();
    cout<<"\nThe minimum marks obtained is :";
    cout<<arr[1]<<endl;
}
void Heap :: build_max_heap()
{
    for(int i=n/2;i>=1;i--)
    {
        max_heapify(i);
    }
}
void Heap :: build_min_heap()
{
    for(int i=n/2;i>=1;i--)
    {
        min_heapify(i);
    }
}
void Heap :: max_heapify(int i)
{
    int left = 2*i ;           
    int right = 2*i +1 ;
    int largest;
    if(left<= n && arr[left] > arr[i] )
          largest = left;
    else
         largest = i;
    if(right <= n && arr[right] > arr[largest] )
        largest = right;
    if(largest != i )
    {
        swap (arr[i] , arr[largest]);
        max_heapify (largest);
    } 
}
void Heap :: min_heapify(int i)
{
    int left  = 2*i;
    int right = 2*i+1;
    int smallest;
    if(left <= n && arr[left] < arr[ i ] )
        smallest = left;
    else
        smallest = i;
    if(right <= n && arr[right] < arr[smallest] )
        smallest = right;
    if(smallest != i)
    {
        swap (arr[ i ], arr[ smallest ]);
        min_heapify (smallest);
    } 
}
int main()
{
    Heap h;
    h.input();
    h.output();
    return 0;
}