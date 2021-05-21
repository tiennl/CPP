#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define N 1000005 
ll a[N];
int main(){
	FIO
	ll n,m=0,f=0;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n-3;i++)
		for (int j=i+1;j<n-2;j++)
			for (int h=j+1;h<n-1;h++)
				for (int k=h+1;k<n;k++){
					if (a[i]>0 && a[j]<0 && a[h]<0 && a[k]>0 && a[i]>a[k]) m++;
					if (a[i]<0 && a[j]>0 && a[h]>0 && a[k]<0 && abs(a[i])<abs(a[k])) f++;
				}
	cout<<m<<" "<<f;
	return 0;
}
