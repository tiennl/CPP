#include <bits/stdc++.h>
using namespace std;
#define db double 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	db t;
	while (cin>>t){
		if (t==0.00) return 0;
		double s=0,n=1;
		while (s<t){
			n++;
			s+=(1/n);
		}		
		cout<<n-1<<" "<<"card(s)"<<endl;
	}
	return 0;
}
