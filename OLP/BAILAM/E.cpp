#include <iostream>
#include <math.h>
using namespace std;
int main(){
    float a,b;
    int n,m;
    unsigned long long sum=0;
    cin>>a>>b;
    if (int(a)==a) n=(int)a;
	else n=(int)a+1; 
    m=(int)b;
	//cout<<n<<" "<<m<<endl;
    sum=((m+n)*((m-n)+1))/2;
    cout<<sum;
}
