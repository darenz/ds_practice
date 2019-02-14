#include<iostream>
using namespace std;

//从a数组中，删除b,c数组中共有的数。a,b,c都为非递减数组。
int findOut(int* b,int nb,int* c,int nc,int* t);
int deleteOut(int* a,int na,int* pt,int tn);
int minSize(int a,int b);
int deleteElem(int *a,int *aend);
int getNum(int *a,int n);

int main()
{
    int na,nb,nc;

    cout<<"input a,b,c size"<<endl;
    cin>>na;
    cin>>nb;
    cin>>nc;
    int a[na];
    int b[nb];
    int c[nc];
    cout<<"input a ";
    getNum(a,na);
    cout<<"input b ";
    getNum(b,nb);
    cout<<"input c ";
    getNum(c,nc);

    int min = minSize(nb,nc);
    int t[min];
    int tn;

    tn = findOut(b,nb,c,nc,t);
    deleteOut(a,na,t,tn);
    for(int i=0;i<tn;i++)
        cout<<t[i]<<" ";
    cout<<endl;
    for(int i=0;i<na;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}

int findOut(int* b,int nb,int* c,int nc,int* t)
{
    //int min = minSize(nb,nc);
    t[0] = 0;
    int count=0;
    int* pb = b;
    int* pc = c;

    while(pb<b+nb && pc<c+nc)
    {
        while(*pb < *pc &&(pb<b+nb && pc<c+nc))
            pb++;
        if(*pb == *pc)
        {
            count++;
            t[count-1] = *pb;
            pc++;
        }
        while(*pc <= *pb &&(pb<b+nb && pc<c+nc))
        {
            if(*pc == *pb)
            {
                if(*(pc-1)!=*pc)
                {
                    count++;
                    t[count-1] = *pb;
                }
            }
            pc++;
        }
    }
    cout<<count<<endl;
    return count; 
}

int minSize(int a,int b)
{
    return a>b?b:a;
}

int deleteElem(int *a,int *aend)
{
    int *p = a;
    for(int i=0;i<aend-a-1;i++)
    {
        *p = *(p+1);
        p++;
    }
    *(aend-1) = 0;
    return true;
}

int deleteOut(int* a,int na,int* pt,int tn)
{
    int *pa = a;
    int *p = pt;
    while(pa<a+na && p<pt+tn)
    {
        while(*pa < *p &&(pa<a+na && p<pt+tn))
            pa++;
        if(*pa == *p)
            deleteElem(pa,a+na);
        p++;
    }
    return true;
}

int getNum(int *a,int n)
{
    int t;
    cout<<"get numbers:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        a[i] = t;
    }

    return true;
}

