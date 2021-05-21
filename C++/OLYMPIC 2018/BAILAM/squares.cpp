#include <iostream>
#include <fstream>
using namespace std;
long long s[10000000];
main(){
   ifstream fi ("squares.inp");
   ofstream fo ("squares.out");
   long long n,l,sum;
   fi>>n>>l;
   int k=1000000007;
   for (int i=n;i>=0;i--){
       s[i]=l*l;
       sum+=s[i];
       if (sum>k) sum=sum%k;
       l*=2;
   }
   fo<<sum;
}
