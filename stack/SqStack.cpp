#include<iostream>

#include"SqStack.hpp"

using namespace std;

int main()
{
    SqStack<int> stack(5);
    int s;
    while(1)
    {
        cout<<"1.show 2.push 3.pop 4.length 5.size"<<endl;

        cout<<"input:"<<endl;
        cin>>s;
        
        if(s==-1)
            break;
        else
        {
            switch(s)
            {
                case 1:
                    stack.show();
                    break;
                case 2:
                    int a;
                    cin>>a;
                    stack.push(a);
                    break;
                case 3:
                    int b;
                    stack.pop(b);
                    break;
                case 4:
                    cout<<stack.getLength()<<endl;
                    break;
                case 5:
                    cout<<stack.getStackSize()<<endl;
                    break;
                default:
                    break;
            }
        }
    }
}
