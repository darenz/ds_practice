#include<iostream>

using namespace std;

template<class T>
class Node
{
    public:
        T val; 
        Node* next;
};

class static_search1
{

    private :

};


void sort(int* list,int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            int t;
            if(list[j]>list[j+1])
            {
                t = list[j];
                list[j] = list[j+1];
                list[j+1] = t;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<list[i]<<" ";
    }
    cout<<endl;
}

int search2(int* list,int k,int n)
{
    int low = 0;
    int high = n-1;
    int mid = n/2;
    
    while(list[mid]!=k)
    {
        if(list[mid]>k)
        {
            high = mid;
            mid = (low + high)/2;
        }
        else if(list[mid]<k)
        {
            low = mid;
            mid = (low + high)/2;
        }
        
        if(low == mid || mid==high)
            return 0;
    }
    return mid+1;
}

int search1(int* list,int k,int n)
{
    list[0] = k;
    int i = n ;
    while(list[i]!=k)
    {
        i--;
    }
    return i;
}

int main()
{
    int n;
    int nn;
    cin>>n;
    nn = n;
    int* list = new int[n+1];
//    list[0] = 0;
    while(n--)
    {
        cin>>list[nn-n];
    }
    int k;
    cout<<"intput k"<<endl;
    cin>>k;

    int r;
//    r = search1(p,k,nn);
    sort(&list[1],nn);
    r = search2(&list[1],k,nn) ;
    cout<<r<<endl;
}
