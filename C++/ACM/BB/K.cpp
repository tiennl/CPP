#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
int main(){
	FIO
    ll n;
    cin>>n;
    ll a[n+10],b[n+10],dem=n,dau=0,duoi=0;
    for (int i=0;i<n;i++) cin>>a[i];
    ll minn=a[0],maxx=a[0];
    b[0]=a[0];
    for (int i=1;i<n;i++){
    	b[i]=a[i];
    	minn=min(minn,a[i]);
    	maxx=max(maxx,a[i]);
	}
	sort(b,b+n);
	bool ok=false;
	ll d=0;
	for (int i=0;i<n;i++)
		if (b[i]==a[i]) d++;
	if (d==n) ok=true;
	d=0;
	sort(b,b+n,greater<ll>());
	for (int i=0;i<n;i++)
		if (b[i]==a[i]) d++;
	if (d==n) ok=true;
	if (ok==false && ((a[0]==minn && a[n-1]==maxx) || (a[0]==maxx && a[n-1]==minn))) dem++;
    for (int i=1;i<n;i++){
        if(a[i]>a[duoi]){
                duoi=i;
                dem+=(duoi-dau);
        }
        else{
            dau=i;
            duoi=i;
        }
    }
    dau=n-1;
	duoi=n-1;
    for(int i=n-2;i>=0;i--){
        if(a[i]>a[duoi]){
                duoi=i;
                dem+=(dau-duoi);
        }
        else{
            dau=i;
            duoi=i;
        }
    }
    cout<<dem;
    return 0;
}
/*

8
1 3 2 4 5 7 6 8 -> 15
2 4 5
4 5 7
1 3 2 4
2 4 5 7
5 7 6 8
1 3 2 4 5
4 5 7 6 8
1 3 2 4 5 7 
2 4 5 7 6 8
1 3 2 4 5 7 6 8


*/









