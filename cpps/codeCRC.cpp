#include<iostream>
#include<vector>
using namespace std;

int MoveIt(int* a,int na,int maxa,int loc)
{
    int i = loc; 
    while(i<na && a[i]==0)    
        i++;
    if(i+1>maxa) return -1;
    return i;
}

void DoIt(int* a,int* b,int nb,int loc)
{
    int j = loc;
    for(int i=0;i<nb;i++) 
    {
        a[j+i] ^= b[i];
    }
}


bool CRC(int* a,int na,int maxa,int* b,int nb)
{
    int l = na;
    int loc = 0; 
    while(l>nb)
    {
        loc = MoveIt(a,na,maxa,loc);
        if(loc < 0)
            break;
        DoIt(a,b,nb,loc);
        l = na - loc;
    }
    return true;
}

int main()
{
    long ia;
    int ib;
    vector<int> a;
    vector<int> b;
    cin>>ia;
    cin>>ib;
    while(ia)
    {
        int t = ia%10;
        ia = ia/10;
        a.push_back(t);
    }
    while(ib)
    {
        int t = ib%10;
        ib = ib/10;
        b.push_back(t);
    }
    int* aa = new int[a.size()+b.size()-1];
    int* ab = new int[b.size()];
    for(int i=0;i<a.size();i++)
        aa[i] = a[a.size()-1-i];
    for(int i=0;i<b.size();i++)
        ab[i] = b[b.size()-1-i];
    CRC(aa,a.size()+b.size()-1,a.size(),ab,b.size());

    for(int i=0;i<a.size()+b.size()-1;i++)
    {
        if(i<a.size())
            aa[i] += a[a.size()-1-i];
        cout<<aa[i];
    }
    cout<<endl;
    return 0;
}
