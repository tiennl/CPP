#include <iostream>
using namespace std;
int a[30000];
int main(){
    int n,res=0;
    cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=0;i<n-1;i++)
        if (a[i]<a[i+1]){
            res++;
            a[i]=a[i+1];
        }
    cout<<res;
    return 0;
}
