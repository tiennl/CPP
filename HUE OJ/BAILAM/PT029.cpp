#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define ull unsigned long long
#define N 1000005

ull a[N];
ll x[N];

ll check(ll x[], ll n){
	ll s=0,c4=0,c7=0;
	for (int i=1;i<=n;i++){
		s=s*10+x[i];
		if (x[i]==4) c4++;
		else c7++;
	}
	if (c4!=c7) return 0;
	return s; 
}

void per(ll n, ll i, ll x[], ll &m, ull a[]){
	for (int j=1;j<=2;j++){
		if (j==1) x[i]=4;
		else x[i]=7;
		if (i==n){
			m++;
			a[m]=check(x,n);
		}
		else per(n,i+1,x,m,a);
	}
}

ll digit(ll n){
	ll s=0;
	while (n>0){
		s++;
		n/=10;
	}
	return s;
}

int main(){
	FIO
	ll t,n,num,m=0,ok=0,res=0;
	cin>>t;
	while (t--){
		cin>>num;
		n=digit(num);
		m=0;
		ok=0;
		if (n%2!=0){
			n++;
			for (int i=0;i<n/2;i++) cout<<4;
			for (int i=0;i<n/2;i++) cout<<7;
			ok=1;
		}
		if (n%2==0 && ok==0){
			per(n,1,x,m,a);
			sort(a+1,a+m+1);
			for (int i=1;i<=m;i++)
				if (a[i]>=num){
					cout<<a[i];
					ok=1;
					break;	
				}
		}
		while (ok==0){
			res=0;
			if (n%2==0){
				for (int i=0;i<n/2;i++) res=res*10+4;
				for (int i=0;i<n/2;i++) res=res*10+7;
			}
			if (res>=num){
				cout<<res;
				ok=1;
			}
			n++;
		}
		cout<<endl;
	}
	return 0;
}

