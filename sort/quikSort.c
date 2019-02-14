#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ElemNum 50

int Partition(int *a,int lo,int hi)
{
    int pivot = a[lo];
    while(lo<hi)
    {
        while(lo<hi && a[hi]>=pivot) hi--;
        a[lo] = a[hi];
        while(lo<hi && a[lo]<=pivot) lo++;
        a[hi] = a[lo];
    }
    a[hi] = pivot; // hi=lo
    return hi;
}

void QuickSort(int *a,int lo,int hi)
{
    int pivotpos;
    if(lo<hi)
    {
        pivotpos = Partition(a,lo,hi);
        QuickSort(a,lo,pivotpos-1);
        QuickSort(a,pivotpos+1,hi);
    }
}

int quchong(int *a,int len)
{
    int lo = 0;
    int hi = 1;
    while(hi<len-1)
    {
        while(a[hi]==a[lo]) hi++;
        a[++lo] = a[hi++];
    }
    return lo+1;
}

int BinSearch(int *a,int len,int key)
{
    int lo = 0;
    int hi = len; 
    int mid;
    while(lo<hi)
    {
        mid = (lo+hi)>>1;
        if(key < a[mid]) 
            hi = mid;   // [lo,hi)
        else if(a[mid] < key)
            lo = mid+1; // [lo,hi)
        else return mid+1;
    }
    return -1;
}

int main()
{
    int a[ElemNum];
    srand((int)time(0));
    int i;
    for(i=0;i<ElemNum;i++)
    {
        a[i] = rand()%100;
        printf("%d ",a[i]);
    }
    printf("\n");

    QuickSort(a,0,ElemNum-1);
    for(i=0;i<ElemNum;i++)
        printf("%d ",a[i]);
    printf("\n");

    int len = quchong(a,ElemNum);
    for(i=0;i<len;i++)
        printf("%d ",a[i]);
    printf("\n");

    int c;
    scanf("%d",&c);
    int n = BinSearch(a,len,c);
    printf("%d",n);
    printf("\n");

    return 0;
}
