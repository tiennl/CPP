#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ull long long
#define N 1000005 
ull a[N],s[N];
int main(){
	FIO
	ull n,res=-1e18,x,y,z;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	s[2]=a[0]-2*a[1]-a[2];
	res=s[2];
	x=a[0];
	y=a[1];
	z=a[2];
	cout<<res<<" "<<x<<" "<<y<<" "<<z<<endl;
	for (int i=3;i<n;i++){
		int ok=0;
		if (s[i-1]>x-2*y-a[i]){
			s[i]=s[i-1];
		}
		else{
			s[i]=x-2*y-a[i];
			ok=1;
		}
		if (x-2*z-a[i]>s[i]){
			s[i]=x-2*z-a[i];
			ok=2;
		}
		if (y-2*z-a[i]>s[i]){
			s[i]=y-2*z-a[i];
			ok=3;
		}
		if (ok==1) z=a[i];
		else if (ok==2) y=z,z=a[i];
		else if (ok==3) x=y,y=z,z=a[i];
		res=max(res,s[i]);
		cout<<s[i]<<" "<<x<<" "<<y<<" "<<z<<endl;
	}
	cout<<res;
	return 0;
}
