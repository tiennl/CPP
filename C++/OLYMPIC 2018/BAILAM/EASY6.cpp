#include <bits/stdc++.h>
using namespace std;
int a[100000];
int main(){
	int n,max=1,len=1;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	if (n<2) cout<<n;
	else{
	for (int i=0;i<n-1;i++){
		if (a[i+1]==a[i]){
			if (len>max) max=len;
			len=1;
		}
		else len++;
	}
	if (len>max) max=len;
	cout<<max;
	}
	return 0;
}
