#include <iostream>
#include <cmath>
using namespace std;

#define feq(a,b) (fabs(a-b)<1e-8)
const double pi (acos(-1));

int main()
{
    float a,b;
    a = 9.0000001;
    b = 8.999999999;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<feq(a,b)<<endl;
    cout<<pi<<endl;
}