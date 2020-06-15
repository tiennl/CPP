#include <bits/stdc++.h>
using namespace std;
int a[1000];
int main(){
	ifstream fi("sapxep.inp");
	ofstream fo("sapxep.out");
	int n,pos=0;
	fi>>n;
	for (int i=0;i<n;i++) fi>>a[i];
	sort(a,a+n);
	for (int i=n-1;i>=0;i--)
		if (a[i]<=0){
			pos=i;
			break;
		}
	for (int i=pos+1;i<n;i++) fo<<a[i]<<" ";
	for (int i=pos;i>=0;i--) fo<<a[i]<<" ";
	fi.close();
	fo.close();
	return 0;
}

