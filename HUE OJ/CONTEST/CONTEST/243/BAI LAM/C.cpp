#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	char s;
	int x,d=0,res=0;
	while (cin>>s){
		if (s=='i'){
			cin>>x;
			d++;
			if (d%2==0) res+=x;
		}
		if (s=='s') cout<<res<<endl;
		if (s=='0'){
			cin>>s;
			return 0;
		}
	}	
	return 0;
}
