#include<iostream>
#include"static_list.h"
using namespace std;

int main()
{
    StList list(5);
    cout<<"list is Empty:"<<list.IsEmpty()<<"(1 for ture,0 for false)"<<endl;
    int i=0;
    int n=0;
    while(i!=-1)
    {
        cout<<"input a number and index:"<<endl;
        cin>>n>>i;
        list.Insert(i,n);
        list.ShowList();
    }
   return 0;
}
