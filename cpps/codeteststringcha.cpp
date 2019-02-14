#include<iostream>
#include<string>

using namespace std;

class a
{
    string s;
    class b
    {
        int x,y;
    } bb;
};

int main()
{
    char s[20] = {"aldjfj"};
    string ss = s;
    cout<<ss<<endl;
    cout<<ss.length()<<endl;

    cout<<sizeof(string)<<endl;
    cout<<sizeof(a)<<endl;
    a a1;

}
