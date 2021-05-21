#include <bits/stdc++.h>
long long coin[10000000];
using namespace std;
int main(){
	long long t,c,i=0,res=0;
	cin>>t;
	while (t--){
		cin>>c;
		i=1;
		res=0;
		while (c>0){
			res++;
			coin[res]=i;
			c-=i;
			i*=2;
		}
		cout<<res<<endl;
		for (int i=1;i<=res;i++) cout<<coin[i]<<" ";
		cout<<endl;
	}
	return 0;
}
