#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n;
	while (cin>>n){
		if (n==-1) return 0;
		ll res=0,i=0,ok=0;
		while (res<n){
			if (i==0) res=1;
			else res+=6*i;
			i++;
			if (res==n){
				cout<<"Y"<<endl;
				ok=1;
				break;
			}
		}	
		if (!ok) cout<<"N"<<endl;
	}
	return 0;
}
