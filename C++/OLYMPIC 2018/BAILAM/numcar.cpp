#include <iostream>
#include <math.h>
using namespace std;
bool kt(long long x){
    long long s=0;
    while (x>0){
        s+=(x%10);
        x/=10;
    }
    if (s==9) return true;
    else return false;
}
main(){
    long long n,d;
    cin>>n;
    d=0;
    for (int i=1;i<pow(10,n);i++){
        if (kt(i)) d++;
    }
    cout<<d%1000000007;
}