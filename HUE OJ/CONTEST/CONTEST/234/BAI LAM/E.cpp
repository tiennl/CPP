#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll sl[100];
string a[100000];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,k;
	cin>>n;
	sl[1]=2;
	for (int i=2;i<=10;i++) sl[i]=sl[i-1]*2;
	if (n==1) cout<<0<<endl<<1;
	else {
		a[1]="0";
		a[2]="1";
		if (n>=2){
			k=sl[2]/2;
			for (int i=sl[2]/2+1;i<=sl[2];i++,k--) a[i]="1"+a[k];
			for (int i=1;i<=sl[2]/2;i++) a[i]="0"+a[i];
			if (n==2) for (int i=1;i<=sl[2];i++) cout<<a[i]<<endl;
		}
		if (n>=3){
			k=sl[3]/2;
			for (int i=sl[3]/2+1;i<=sl[3];i++,k--) a[i]="1"+a[k];
			for (int i=1;i<=sl[3]/2;i++) a[i]="0"+a[i];
			if (n==3) for (int i=1;i<=sl[3];i++) cout<<a[i]<<endl;
		}
			if (n>=4){
			k=sl[4]/2;
			for (int i=sl[4]/2+1;i<=sl[4];i++,k--) a[i]="1"+a[k];
			for (int i=1;i<=sl[4]/2;i++) a[i]="0"+a[i];
			if (n==4) for (int i=1;i<=sl[4];i++) cout<<a[i]<<endl;
		}
			if (n>=5){
			k=sl[5]/2;
			for (int i=sl[5]/2+1;i<=sl[5];i++,k--) a[i]="1"+a[k];
			for (int i=1;i<=sl[5]/2;i++) a[i]="0"+a[i];
			if (n==5) for (int i=1;i<=sl[5];i++) cout<<a[i]<<endl;
		}
			if (n>=6){
			k=sl[6]/2;
			for (int i=sl[6]/2+1;i<=sl[6];i++,k--) a[i]="1"+a[k];
			for (int i=1;i<=sl[6]/2;i++) a[i]="0"+a[i];
			if (n==6) for (int i=1;i<=sl[6];i++) cout<<a[i]<<endl;
		}
			if (n>=7){
			k=sl[7]/2;
			for (int i=sl[7]/2+1;i<=sl[7];i++,k--) a[i]="1"+a[k];
			for (int i=1;i<=sl[7]/2;i++) a[i]="0"+a[i];
			if (n==7) for (int i=1;i<=sl[7];i++) cout<<a[i]<<endl;
		}
			if (n>=8){
			k=sl[8]/2;
			for (int i=sl[8]/2+1;i<=sl[8];i++,k--) a[i]="1"+a[k];
			for (int i=1;i<=sl[8]/2;i++) a[i]="0"+a[i];
			if (n==8) for (int i=1;i<=sl[8];i++) cout<<a[i]<<endl;
		}
			if (n>=9){
			k=sl[9]/2;
			for (int i=sl[9]/2+1;i<=sl[9];i++,k--) a[i]="1"+a[k];
			for (int i=1;i<=sl[9]/2;i++) a[i]="0"+a[i];
			if (n==9) for (int i=1;i<=sl[9];i++) cout<<a[i]<<endl;
		}
			if (n>=10){
			k=sl[10]/2;
			for (int i=sl[10]/2+1;i<=sl[10];i++,k--) a[i]="1"+a[k];
			for (int i=1;i<=sl[10]/2;i++) a[i]="0"+a[i];
			if (n==10) for (int i=1;i<=sl[10];i++) cout<<a[i]<<endl;
		}
	}
	return 0;
}
