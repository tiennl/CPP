#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
string tostring(ll a){
    ostringstream temp;
    temp<<a;
    return temp.str();
}
int main(){
	FIO
	ll n,i,ii,temp;
	string st,s,m;
	cin>>n;
	m=tostring(n);
	st="1";
	i=1;
	temp=0;
	while (1){
		if (i==n) break;
		i++;
		st+=tostring(i);
		if (st.size()>200){
		    temp+=100;
		    st.erase(0,100);
		}
		if (st.find(m)!=-1){
			cout<<st.find(m)+temp+1;
			return 0;
		}
	} 
	return 0;
}
