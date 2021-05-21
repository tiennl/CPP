#include <iostream>
#include <string>
using namespace std;
main(){
    long long n,dem,max;
    string s;
    cin>>n;
    cin>>s;
    dem=1;
    max=0;
    for (int i=1;i<n;i++){
        if (s[i]!=s[i-1]){
            dem++;
            if (dem>max) max=dem;
        }
        else if (s[i]==s[i-1]) dem=1;
    }
    cout<<max;
}