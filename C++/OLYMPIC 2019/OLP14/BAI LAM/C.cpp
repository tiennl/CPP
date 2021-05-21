#include <bits/stdc++.h>
long long a[1000000],maxx[10000000];
using namespace std;
int main(){
	long long n,res=0,sum=0,coun=0,v1=0,v2=0,mina=0,maxa=0;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	if (n<1000){
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++){
			maxa=a[i];
			mina=a[i];
			for (int k=i+1;k<=j;k++){
				maxa=max(maxa,a[k]);
				mina=min(mina,a[k]);
			}
			if ((a[i]==maxa && a[j]==mina) || (a[i]==mina && a[j]==maxa)){
				if ((maxa-mina>res) || ((maxa-mina==res) && ((j-i+1)>coun)) || 
				((maxa-mina==res) && ((j-i+1)==coun) && (maxa+mina<sum))){
					res=maxa-mina;
					coun=j-i+1;
					v1=i;
					v2=j;
					sum=maxa+mina;
				}
			//	cout<<i<<" "<<j<<" "<<res<<" "<<coun<<" "<<v1+1<<" "<<v2+1<<endl;
			}
		
		}
	cout<<coun<<" "<<v1+1<<" "<<v2+1;
	}
	else{
	long long res=0,res2=0,ans=0,ans2=0,v1=0,v2=0,vv1=0,vv2=0;

	maxx[0]=1;
	v1=0;
	res=0;
	for (int i=1;i<n;i++) {
		if (a[i]>=a[i-1]) maxx[i]=maxx[i-1]+1;
		else maxx[i]=1;
		if (maxx[i]>res){
			res=maxx[i];
			v1=i-maxx[i]+1;
			v2=i;
			ans=a[v2]-a[v1];
		}
	}
	maxx[0]=1;
	vv1=0;
	res2=0;
	for (int i=1;i<n;i++) {
		if (a[i]<=a[i-1]) maxx[i]=maxx[i-1]+1;
		else maxx[i]=1;
		if (maxx[i]>res2){
			res2=maxx[i];
			vv1=i-maxx[i]+1;
			vv2=i;
			ans2=a[vv1]-a[vv2];
		}
	}
	if ((ans2>ans) || (ans2==ans && res2>res) || (ans2==ans && res2==res && a[vv1]+a[vv2]>a[v1]+a[v2])){
		ans=ans2;
		v1=vv1;
		v2=vv2;
	}
	cout<<res<<" "<<v1+1<<" "<<v2+1;
	}
	return 0;
}
