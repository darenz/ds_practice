#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int ElemType;
#define true 1;
#define false 0;

typedef struct
{
    ElemType *elem;
    int table_len;
} SSTable;

int SSTableInit(SSTable *T,ElemType* t,int len)
{
    int i;
    T->elem = (ElemType*)malloc(sizeof(ElemType)*(len+1));
    if(T->elem == NULL)
        return false;
    for(i=1;i<len+1;i++)
        T->elem[i] = t[i-1];
    T->table_len = len+1;
    return true;
}

int Search_Seq(SSTable *T,ElemType key)
{
    int i;
    T->elem[0] = key;
    for(i=T->elem[T->table_len];T->elem[i]!=key;i--);
    return i;
}

int BinSearch(SSTable *T,ElemType key)
{
    int mid;
    int lo = 1;
    int hi = T->table_len+1;
    while(lo<hi)
    {
        mid = (lo+hi)>>1;
        if(key<T->elem[mid])
            hi = mid;
        else if(T->elem[mid]<key)
            lo = mid+1;
        else 
            return mid;
    }
    return -1;
}

int Partition(ElemType* a,int lo,int hi)
{
    ElemType pivot = a[lo];
    while(lo<hi)
    {
        while(lo<hi && a[hi]>=pivot) hi--;
        a[lo] = a[hi];
        while(lo<hi && a[lo]<=pivot) lo++;
        a[hi] = a[lo];
    }
    a[hi] = pivot; 
    return hi;
}

void QuickSort(ElemType* a,int lo,int hi)
{
    if(lo<hi)
    {
        int pivotpos = Partition(a,lo,hi);
        QuickSort(a,lo,pivotpos-1);
        QuickSort(a,pivotpos+1,hi);
    }
}

int quchong(ElemType* a,int len)
{
    int lo = 0;
    int hi = 1;
    while(hi<len)
    {
        while(a[hi]==a[lo]) hi++;
        a[++lo] = a[hi++];
    }
    return lo+1;
}

void main()
{
    int a[30] ;
    int i;
    int c;
    srand((int)time(0));
    for(i=0;i<30;i++)
        a[i] = rand()%100;
    for(i=0;i<30;i++)
        printf("%d ",a[i]);
    printf("\n");
    QuickSort(a,0,29);
    int len = quchong(a,30);
    for(i=0;i<len;i++)
        printf("%d ",a[i]);
    SSTable T;
    SSTableInit(&T,a,len);
    printf("\n");
    scanf("%d",&c) ;
    //int n = Search_Seq(&T,c);
    int n = BinSearch(&T,c);
    printf("%d\n",n);
    return ;
}
