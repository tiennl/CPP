#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
main()
{
    long long dem=0;
    double x;
    cin>>x;
    x=sqrt(x);
    x=x/(sqrt(2));
    x=x/(1+sqrt(3)+sqrt(2));
    cout<<fixed<<setprecision(4)<<x;
}
