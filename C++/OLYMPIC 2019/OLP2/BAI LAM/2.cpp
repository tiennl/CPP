#include <bits/stdc++.h>
using namespace std;
long long a[100000];
int main(){
	string st,k;
	long long m,d=0,s;
	cin>>st;
	s=st.size();
	cin>>m;
	for (int i=0;i<m;i++) cin>>a[i];
	a[m]=0;
	int i=0;
	while (i<m){
		if (a[i]==a[i+1]) i++;
		else if (a[i]!=a[i+1]){
			k="";
			for (int j=s-a[i];j>a[i]-1;j--)
				k+=st[j];
			d=0;
			for (int j=a[i]-1;j<s-a[i];j++){
				st[j]=k[d];
				d++;
			}
	//	cout<<k<<endl;
		}
		i++;
	}
	cout<<st;
	return 0;
}
