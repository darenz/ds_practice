#include<iostream>

using namespace std;

void fastSort(int array[],int start,int end);

void fastSort(int array[],int start,int end)
{
    int i = start;
    int j = end; 
    if( i >= j)
        return;
    int temp = array[i];
    while(i<j)
    {
        while(i<j && array[j]>=temp)
            j--; 
        //严重错误：
        //快速排序算法理解错误
        //快速排序为交换排序
        array[i] = array[j];
        while(i<j && array[i]<=temp)
            i++;
        array[j] = array[i];
    }
    array[i] = temp;
    fastSort(array,start,i-1);
    fastSort(array,i+1,end);
}

int main()
{
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    fastSort(array,0,n-1);
    //Qsort(array,0,n-1);
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<array[i]<<' ';
    }
    cout<<endl;
}
