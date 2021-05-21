#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); 
#define ll long long
#define N 1000000 
ll a[N];
int main(){
	FIO
	ll n,num,maxx=0,coun=0,res=0;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>num;
		a[num]++;
		coun=max(coun,a[num]);
		maxx=max(maxx,num);
	}
	for (int i=maxx;i>=0;i--)
		if (a[i]==coun){
			cout<<i;
			return 0;
		}
	return 0;
}
