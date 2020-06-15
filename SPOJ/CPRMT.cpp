#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
ll c[500],d[500]; 
int main(){
	FIO
	string a,b;
	while (cin>>a>>b){
		for (int i='a';i<='z';i++) c[i]=0,d[i]=0;
		for (int i=0;i<a.size();i++) c[a[i]]++;
		for (int i=0;i<b.size();i++) d[b[i]]++;
		for (int i='a';i<='z';i++)
			if (c[i]>0 && d[i]>0)
				for (int j=0;j<min(c[i],d[i]);j++) cout<<(char)(i);
		cout<<endl; 
	}	
	return 0;
}
