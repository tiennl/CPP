#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

ll a[5],b[5]={0};

int main(){
	FIO
	ll a0,a1,a2,d;
	cin>>a[0]>>a[1]>>a[2]>>d;
	a0=a[0];
	a1=a[1];
	a2=a[2];
	sort(a,a+3);
	for (int i=0;i<3;i++)
		if (a[i]<=d){
			b[i]=a[i];
			d-=a[i];
		}
		else{
			b[i]=d;
			break;
		}
	for (int i=0;i<3;i++)
		if (a[i]==a0){
			cout<<b[i]<<" ";
			break;
		}
	for (int i=0;i<3;i++)
		if (a[i]==a1){
			cout<<b[i]<<" ";
			break;
		}
	for (int i=0;i<3;i++)
		if (a[i]==a2){
			cout<<b[i];
			break;
		}
	return 0;
}
