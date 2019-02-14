#include<iostream>
#include"BiTree.hpp"
using namespace std;

int main()
{
    BiTree<int> tree;
    cout<<"input n"<<endl;
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    tree.read(array,n);
    
    tree.showDLR();
    cout<<endl;
    tree.showLDR();
    cout<<endl;
    tree.showLRD();
    cout<<endl;
}
