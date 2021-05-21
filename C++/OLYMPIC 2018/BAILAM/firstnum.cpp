#include <iostream>
#include <string>
#include <sstream>
using namespace std;
string toString(ll a){
    ostringstream temp;
    temp<<a;
    return temp.str();
}
main(){
	int n,kt,i,ii,temp;
	string st,s,m;
	cin>>n;
	m=tostring(n);
	kt=0;
	st="1";
	i=1;
	temp=0;
	while (kt==0){
		if (i==n) break;
		i++;
		s="";
		ii=i;
		while (ii>0){ 
			s+=tostring(ii%10);
			ii/=10;
		}
		for (int j=s.size()-1;j>=0;j--) st+=s[j];
		if (st.size()>200){
		    temp+=100;
		    st.erase(0,100);
		}
		if (st.find(m)!=-1){
			cout<<st.find(m)+temp+1;
			kt=1;
			break;
		}
	} 
}
