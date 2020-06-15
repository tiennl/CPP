#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll a[8];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll t,n;
	string s,st;
	cin>>t;
	while (t--){
		cin>>n>>s;
		for (int i=0;i<8;i++) a[i]=0;
		st="";
		for (int i=0;i<s.size()-2;i++){
			st="";
			st=st+s[i]+s[i+1]+s[i+2];
			if (st=="TTT") a[0]++;
			else if (st=="TTH") a[1]++;
			else if (st=="THT") a[2]++;
			else if (st=="THH") a[3]++;
			else if (st=="HTT") a[4]++;
			else if (st=="HTH") a[5]++;
			else if (st=="HHT") a[6]++;
			else if (st=="HHH") a[7]++;
		}	
		cout<<n<<" ";
		for (int i=0;i<8;i++) cout<<a[i]<<" ";
		cout<<endl;
	}
	return 0;
}
