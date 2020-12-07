#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cout<<"1. Lap ma"<<endl;
	cout<<"2. Giai ma"<<endl;
	cout<<"Chon cach chuyen doi: ";
	cin>>t;
	if (t==1){
		string p,c="";
		int k;
		char a[1000];
		cout<<"Nhap ban tin p = ";
		cin.ignore();
		getline(cin,p);
		cout<<"Nhap k = ";
		cin>>k;
		a['a']='A'+k;
		for (int i='b';i<='z';i++){
			a[i]=a[i-1]+1;
			if (a[i]>'Z') a[i]='A';
		}
		for (int i=0;i<p.size();i++)
			if (p[i]==' ') c+=' '; 
			else c+=a[p[i]];
		cout<<c;
	}
	else{
		
	}
	return 0;
}
