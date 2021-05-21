#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

bool doixung(string x){
	for (int i=0;i<x.size()/2;i++){
		if (x[i]!=x[x.size()-i-1]) return false;
	}
	return true;
}

int main(){
	FIO
	string s,s1;
	ll q,max,l,d;
	cin>>s;
	cin>>q;
	max=0;
	for (int i=0;i<q;i++){
		cin>>l;
		if ((l==1 || l==0) && s.size()>=1) cout<<"1"<<endl;
		else{
			d=0;
			for (int j=0;j<=s.size()-l;j++){
				s1=s.substr(j,l);
				if (doixung(s1)==true){
					d=1;
					cout<<"1"<<endl;
					break;
				}
			}
			if (d==0) cout<<"0"<<endl;
		}
	}
	return 0;
}
