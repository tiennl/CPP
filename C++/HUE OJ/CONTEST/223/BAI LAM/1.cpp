#include <bits/stdc++.h>
long long a[100];
int x[100];
using namespace std;
long long kt(int x[], long long n){
	long long s=0,c4=0,c7=0;
	for (int i=1;i<=n;i++){
		s=s*10+x[i];
		if (x[i]==4) c4++;
		else c7++;
	}
	if (c4!=c7) return 0;
	return s; 
}
void hoanvi(long long n, long long i, int x[], long long &m, long long a[]){
	for (int j=1;j<=2;j++){
		if (j==1) x[i]=4;
		else x[i]=7;
		if (i==n){
			m++;
			a[m]=kt(x,n);
		}
		else hoanvi(n,i+1,x,m,a);
	}
}
int scs(long long n){
	int s=0;
	while (n>0){
		s++;
		n/=10;
	}
	return s;
}
int main(){
	long long t,n,num,m=0,ok=0,res=0;
	cin>>t;
	while (t--){
		cin>>num;
		n=scs(num);
		m=0;
		ok=0;
		if (n%2!=0){
			n++;
			for (int i=0;i<n/2;i++) cout<<4;
			for (int i=0;i<n/2;i++) cout<<7;
			ok=1;
		}
		if (n%2==0 && ok==0){
			hoanvi(n,1,x,m,a);
			sort(a+1,a+m+1);
			for (int i=1;i<=m;i++)
				if (a[i]>=num){
					cout<<a[i];
					ok=1;
					break;	
				}
		}
		while (ok==0){
		//	cout<<ok;
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
	//	for (int i=1;i<=m;i++) cout<<a[i]<<" ";
		cout<<endl;
	}
	return 0;
}
