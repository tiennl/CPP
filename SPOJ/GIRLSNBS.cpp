#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	double g,b;
	while (cin>>g>>b){
		if (g==-1 && b==-1) return 0;
		if ((g==b && g==0) || (g==0 || b==0)) cout<<max(g,b)<<endl;
		else{
			double res=max(g,b)/(min(g,b)+1);
			cout<<ceil(res)<<endl;
		}
	}
	return 0;
}
