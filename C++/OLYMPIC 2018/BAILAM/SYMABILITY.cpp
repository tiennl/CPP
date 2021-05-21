#include <iostream>
#include <algorithm>
using namespace std;
long long a[1000000],sl[10000000];
int main(){
	long long n,chan=0,le=0,k=0,num;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	num=a[0];
	sl[0]=1;
	k=0;
	for  (int i=1;i<n;i++)
		if (a[i]==num) sl[k]++;
		else{
			num=a[i];
			k++;
			sl[k]=1;
		}
	k++;
	for (int i=0;i<k;i++)
		if (sl[i]%2==0) chan++;
		else le++;
	if ((n%2==0 && le>0) || (n%2==1 && le>1)) cout<<"FALSE";
	else cout<<"TRUE";
	return 0;
}
