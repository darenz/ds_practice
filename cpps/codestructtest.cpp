#include<iostream>

using namespace std;

class test
{
    public:
        test(int b)
        {
            a = b;
        }
        int a;

        test* next;
    private:

};

class test2
{
    public:
        test2():head(&Head),Head(0)
        {
            ;
        }
        test Head;
        test* head;
};

int main()
{
    test2 t;
    t.head->next = new test(1);
    cout<<t.head->next->a<<endl;;
}
