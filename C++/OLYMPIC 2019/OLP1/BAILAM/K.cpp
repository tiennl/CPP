#include <bits/stdc++.h>
using namespace std;
int a[100];
int main(){
	int n,am=0,duong=0,khong=0;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
		if (a[i]>0) duong++;
		else if (a[i]<0) am++;
		else khong++;
	}
	if (khong>0) cout<<-1;
	else if (am==n || duong==n) cout<<0;
	else cout<<min(am,duong);
	return 0;
}
