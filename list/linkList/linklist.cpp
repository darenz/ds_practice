#include<iostream>
#include"list.h"

using namespace std;

int main()
{
    LinkList h;
    h.creat();
    h.display();
    int i;
    int e;    
    int ein;
    cout<<"insert in i:"<<endl;
    cin>>i;
    cout<<"insert element:"<<endl;
    cin>>e;
    h.insertLoc(i,e);
    h.display();

    cout<<"insert after elem:"<<endl;
    cin>>e;
    cout<<"order:"<<endl;
    cin>>i;
    cout<<"insert element:"<<endl;
    cin>>ein; 
    h.insertElemAfter(e,i,ein);
    h.display();

    cout<<"insert before elem:"<<endl;
    cin>>e;
    cout<<"order:"<<endl;
    cin>>i;
    cout<<"insert element:"<<endl;
    cin>>ein;
    h.insertElemBefore(e,i,ein);
    h.display();
}
