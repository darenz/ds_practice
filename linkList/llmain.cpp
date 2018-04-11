#include <iostream>
#include "linkList.hpp"
using namespace std;

int main()
{
    LinkList<int> list();
    int n;
    while(1)
    {
        cout<<"element type : int"<<endl;
        cout<<"1.append an element"<<endl;
        cout<<"2.insert an element"<<endl;
        cout<<"3.delete an element"<<endl;
        cout<<"4.clear list"<<endl;
        cout<<"5.show list"<<endl;
        cout<<"0.exit"<<endl;

        cin>>n;
        Status s;
        switch(n)
        {
            case 1:
                cout<<"input element:"<<endl;
                ElemType e;
                cin>>e;
                s = list.append(e);
                if(s == OK)
                    cout<<"OK"<<endl;
                break;
            case 2:
                cout<<"input element:"<<endl;
                ElemType e;
                cin>>e;
                cout<<"input location:"<<endl;
                int i;
                cin>>i;
                s = list.insert(i,e);
                if(s == OK)
                    cout<<"insert success"<<endl;
                break;
            case 3:
                cout<<"input an element to delete:"<<endl;
                ElemType e;
                cin>>e;
                s = list.deleteElem(e);
                if(s == OK)
                    cout<<"delete success"<<endl;
                break;
            case 4:
                s = list.clear();
                if(s == OK)
                    cout<<"clear success"<<endl;
                break;
            case 5:
                list.show();
                break;
            case 0:
                break;
            default:
                cout<<"erro index"<<endl;
                break;
        }
        if(n==0)
            break;
    }
}

