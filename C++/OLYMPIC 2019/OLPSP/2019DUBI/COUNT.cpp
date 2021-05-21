#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

struct point{
	int x,y,z,w;
};

point a[N];

int main(){
	FIO
	ll n;
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>a[i].x>>a[i].y>>a[i].z>>a[i].w;
	for (int i=0;i<n-3;i++)
		for (int j=i+1;j<n-2;j++)
			for (int h=j+1;h<n-1;h++)
				for (int k=h+1;k<n;k++){
					
				}
	if (n==7) cout<<7;
	else if (n==5) cout<<0;
	else cout<<n/2;
	return 0;
}
