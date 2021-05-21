#include <fstream>
using namespace std;
int a[1000000];
int b[10109999];
main(){
    ifstream fi ("park.inp");
    ofstream fo ("park.out");
    int k;
    long long s=0;
    fi>>k;
    for (int i=10102010;i<=10109999;i++) b[i]=0; 
    for (int i=0;i<k;i++){
        fi>>a[i];
        b[a[i]]++;
    }
    for (int i=10102010;i<=10109999;i++)
        if (b[i]>0){
            if (b[i]<=5) s+=100;
            else if (b[i]>5) s+=(100+(b[i]-5));
        }
    fo<<s;
}