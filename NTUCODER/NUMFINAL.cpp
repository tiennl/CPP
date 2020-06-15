#include <bits/stdc++.h>
using namespace std;
int main(){
	string aa,bb;
	int a,b;
	cin>>aa>>bb;
	if (bb=="0") cout<<1;
	else{
	a=(int)aa[aa.size()-1]-48;
	if (bb.size()>=2) b=((int)bb[bb.size()-2]-48)*10+(int)bb[bb.size()-1]-48;
	else b=(int)bb[bb.size()-1]-48;
	if (a==0 || a==1 || a==5 || a==6) cout<<a;
	else
	if (a==2){
		if (b%4==2) cout<<4;
		else if (b%4==3) cout<<8;
		else if (b%4==0) cout<<6;
		else cout<<2;
	}
	else if (a==3){
		if (b%4==2) cout<<9;
		else if (b%4==3) cout<<7;
		else if (b%4==0) cout<<1;
		else cout<<3;
	}
	else if (a==4){
		if (b%2==0) cout<<6;
		else cout<<4;
	}	
	else if (a==7){
		if (b%4==2) cout<<9;
		else if (b%4==3) cout<<3;
		else if (b%4==0) cout<<1;
		else cout<<7;
	}
 	else if (a==8){
		if (b%4==2) cout<<4;
		else if (b%4==3) cout<<2;
		else if (b%4==0) cout<<6;
		else cout<<8;
	}
	else if (a==9){
		if (b%2==0) cout<<1;
		else cout<<9;
	}}
	return 0;
}

