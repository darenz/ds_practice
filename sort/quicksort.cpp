#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;

int Partition(int* a,int lo,int hi)
{
    int pivot = a[lo];
    while(lo<hi)
    {
        while(lo<hi && a[hi]>=pivot) hi--;
        a[lo] = a[hi];
        while(lo<hi && a[lo]<=pivot) lo++;
        a[hi] = a[lo];
    }
    a[lo] = pivot;
    return lo;
}

void QuickSort(int* a,int lo,int hi)
{
    if(lo<hi)
    {
        int pivotpos = Partition(a,lo,hi);
        QuickSort(a,lo,pivotpos-1);
        QuickSort(a,pivotpos+1,hi);
    }
}

int main()
{
    srand((int)time(0));
    int *a = new int[30];
    for(int i=0;i<30;i++)
    {
        a[i] = rand()%100;
        cout<<a[i]<<" ";
    }
    cout<<endl;
    QuickSort(a,0,29);
    for(int i=0;i<30;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
