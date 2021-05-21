#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define pb push_back
#define N 1000005

ll coun[N]={0};
vector <ll> a;

int main(){
	FIO
	ll n,res=0;
	cin>>n;
	for (int i=0;i<n;i++){
		ll num;
		cin>>num;
		if (coun[num]==0) a.pb(num);
		coun[num]++;
	}
	while (1){
		ll d=0;
		for (int i=0;i<a.size();i++)
			if (coun[a[i]]>0) d++,coun[a[i]]--;
		if (d==0) break;
		res+=(d-1);
	}
	cout<<res;
	return 0;
}
