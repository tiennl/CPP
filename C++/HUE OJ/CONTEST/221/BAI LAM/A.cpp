#include <bits/stdc++.h>
using namespace std;
int main(){
	string a,b;
	cin>>a>>b;
	if (a.size()>b.size()) cout<<"GREATER";
	else if (a.size()<b.size()) cout<<"LESS";
	else{
		for (int i=0;i<a.size();i++)
			if (a[i]!=b[i]){
				if (a[i]>b[i]){
					cout<<"GREATER";
					return 0;
				}
				else if (a[i]<b[i]){
					cout<<"LESS";
					return 0;
				}
			}
		cout<<"EQUAL";
	}
	return 0;
}
