#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ull long long
#define N 1000000
ull a[500]={0},b[N]={0}; 
ull powMod(ull a, ull b, ull p){
    ull r=1;
    a%=p;
    b%=p;
    while (b>0){
        if (b%2>0) r=r*a%p;
        a=a*a%p;  
        b/=2;
    }
    return r;
}
int main(){
	FIO
	ull k,n,res=1;
	string s;
	cin>>k>>s;
	if (s.size()==0){
		cout<<0;
		return 0;
	}
	for (int i=0;i<s.size();i++) a[s[i]]++;
	for (int i=2;i<=s.size();i++){
		n=i;
		for (int j=2;j<=sqrt(n);j++)
			while (n%j==0){
				b[j]++;
				n/=j;
			}
		if (n>1) b[n]++;
	}
	for (int i='a';i<='z';i++)
		if (a[i]>0){
			n=a[i];
			for (int j=2;j<=sqrt(n);j++)
				while (n%j==0){
					b[j]--;
					n/=j;
				}
			if (n>1) b[n]--;
		}
//	for (int i=1;i<=s.size();i++) cout<<b[i]<<" ";
	for (int i=2;i<=s.size();i++){
		if (b[i]>0) res*=powMod(i,b[i],k),b[i]=0;
		if (res>k) res%=k;
	}
	for (int i=2;i<=s.size();i++){
		if (b[i]<0) res/=powMod(i,b[i],k);
	}
	cout<<res%k;
	return 0;
}
