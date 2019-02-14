#include<iostream>

using namespace std;

int partition(int a[],int lo,int hi)
{
    int pivot = a[lo];
    while(lo<hi)
    {
        while(a[hi]>=pivot && hi>lo) hi--;
        a[lo] = a[hi];
        while(a[lo]<pivot && lo<hi) lo++;
        a[hi] = a[lo];
    }
    a[lo] = pivot;
    return lo;
}

void quickSort(int a[],int lo,int hi)
{
    if(lo>=hi) return;
    int pos = partition(a,lo,hi);
    quickSort(a,lo,pos-1);
    quickSort(a,pos+1,hi);
}

int main()
{
    int a[10];
    for(int i=0;i<10;i++)
        cin>>a[i];
    quickSort(a,0,9);
    for(int i=0;i<10;i++)
        cout<<a[i];
    cout<<endl;
}
