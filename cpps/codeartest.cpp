#include<iostream>

using namespace std;
float* func();
int main()
{
    /*
    float a;
    cout<<sizeof(a)<<endl;
    float* b[2];
    cout<<sizeof(b)<<endl;
    float* array[2048];
    cout<<"array :"<<sizeof(array)/sizeof(float)<<endl;
    float (*p)[2048];
    cout<<"p:"<<sizeof(p)<<endl;
    */

    float* tm = func();
    cout<<tm<<endl;
    delete [] tm; 
    tm = new float[2048];
    cout<<tm<<endl;
    for(int i=0;i<2048;i++)
        tm[i] = i;
}

float* func()
{
    float* t = new float[2048];
    cout<<sizeof(t)<<endl;
    return  t;
}
