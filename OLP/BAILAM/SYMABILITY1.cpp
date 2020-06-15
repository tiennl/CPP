#include <iostream>
#include <algorithm>
using namespace std;
long long a[1000000],sl[10000000];
int main(){
	long long n,chan=0,le=0;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i],sl[a[i]]++;
	sort(a,a+n);
	if (sl[a[0]]%2==0) chan++;
	else le++;
	for (int i=1;i<n;i++)
		if (a[i]!=a[i-1]){
			if (sl[a[i]]%2==0) chan++;
			else le++;
		}
	if ((n%2==0 && le>0) || (n%2==1 && le>1)) cout<<"FALSE";
	else cout<<"TRUE";
	return 0;
}


