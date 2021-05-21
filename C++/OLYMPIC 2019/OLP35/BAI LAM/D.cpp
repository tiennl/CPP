#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define N 100005 
ll a[N],b[N];
int main(){
	FIO
	ll n,m=-1,res=0;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
		if (a[i]%2!=0){
			m++;
			b[m]=i;
		}
	}
	m++;
	for (int i=0;i<n-2;i++)
		for (int j=i+2;j<n;j++)
			if (a[i]>a[j] && a[i]%2==0 && a[j]%2==0){
				int p=upper_bound(b,b+m,i)-b;
				if (b[p]>i && b[p]<j) res++;
			}
	cout<<res;
	return 0;
}
