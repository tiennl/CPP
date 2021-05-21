#include <bits/stdc++.h>
long long a[10000000];
using namespace std;
int main(){
	long long n,s1=0,s2=0,p=0;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n;i++){
		if (a[i]>=a[i+1])
			if (p%2==0) s1+=a[i];
			else s2+=a[i];
		else{
			if (p%2==0) s1+=a[i+1];
			else s2+=a[i+1];
			i++;
		}	
		p++;
	}
	cout<<s1<<" "<<s2;
	return 0;
}
