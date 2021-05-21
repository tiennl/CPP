#include <bits/stdc++.h>
long long a[10000000];
using namespace std;
int main(){
	long long n,maxa=0,mina=0,res=0,sum=0,coun=0,v1=0,v2=0;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++){
			maxa=*max_element(a+i,a+(j-i+1));
			mina=*min_element(a+i,a+(j-i+1));
			if ((a[i]==maxa && a[j]==mina) || (a[i]==mina && a[j]==maxa)){
				if ((maxa-mina>res) || ((maxa-mina==res) && ((j-i+1)>coun)) || 
				((maxa-mina==res) && ((j-i+1)==coun) && (maxa+mina<sum))){
					res=maxa-mina;
					coun=j-i+1;
					v1=i;
					v2=j;
					sum=maxa+mina;
				}
			}
			cout<<i<<" "<<j<<" "<<res<<" "<<coun<<" "<<v1+1<<" "<<v2+1<<endl;
		}
	cout<<coun<<" "<<v1+1<<" "<<v2+1;
	return 0;
}
