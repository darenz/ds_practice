#include<iostream>

using namespace std;

struct student
{
    //int nameid;
    char id;
    short id2;
    int id3;
} __attribute__((aligned(4)));

struct student2
{
    //int nameid;
    char c1;
    char c2;
};

int main()
{
    cout<<sizeof(student)<<endl;
    cout<<sizeof(int)+sizeof(char)<<endl;
    cout<<sizeof(student2)<<endl;
    return 0;
}
