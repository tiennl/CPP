#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	string s;
	ll sum=0;
	while (cin>>s){
		if (s[0]=='F') return 0;
		else if (s[0]=='S') cout<<sum<<endl;
		else{
			cin>>s;
			ll p1=0,p2=0,a=0,b=0;
			for (int i=0;i<s.size();i++)
				if (s[i]==';'){
					if (p1==0) p1=i;
					else p2=i;
				}
			for (int i=p1+1;i<p2;i++) a=a*10+(s[i]-48);
			for (int i=p2+1;i<s.size();i++) b=b*10+(s[i]-48);
			sum+=abs(a-b)*125;
		}
	}
	return 0;
}
