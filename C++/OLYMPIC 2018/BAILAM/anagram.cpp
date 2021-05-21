#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a[10000000],b[10000000],c[10000000];
string sorts(string x){
	string res="";
	for (int ii=0;ii<x.size();ii++) c[ii]=(int)x[ii];
	sort(c,c+x.size());
	for (int ii=0;ii<x.size();ii++) res+= ((string)c[ii]);
	return res; 
}
main(){
	string s1,s2,ss1,ss2,ss,temp;
	cin>>s1>>s2;
	if (s1==s2) cout<<s1.size();
	else if (s1.size()==s2.size()){
		ss1=sorts(s1);
		ss2=sorts(s2);
		if (ss1==ss2) cout<<s1.size();
	}
	else{

	if (s1.size()>s2.size()){
		temp=s1;
		s1=s2;
		s2=temp;
	}
	long long ka=0,kb=0;
	for (int i=1;i<s1.size();i++)
		for (int j=0;j<s1.size()-i+1;j++){
	 		ka++;
	 		ss=s1;
			a[ka]=ss.substr(j,i);
		}
	ka++;
	a[ka]=s1;
	for (int i=1;i<s1.size()+1;i++)
		for (int j=0;j<s2.size()-i+1;j++){
	 		kb++;
	 		ss=s2;
			b[kb]=ss.substr(j,i);
		}
	int kt=0;
	for (int j=kb;j>=0;j--){
		for (int i=ka;i>=0;i--)
			if (a[i].size()==b[j].size()){
				ss1=sorts(a[i]);
				ss2=sorts(b[j]);
				if (ss1==ss2){
					kt=1;
					cout<<a[i].size()<<endl;
				//	cout<<a[i]<<" "<<b[j];
					break;
				}
			}
		if (kt==1) break;
	}
	}
}















