#include <bits/stdc++.h>
using namespace std;
long long a[100000];
int main(){
	string st,k;
	long long n,d=0,s;
	cin>>st;
	s=st.size();
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++)
			if (a[i]!=0 && a[j]!=0 && a[i]==a[j]){
				a[i]=0;
				a[j]=0;
			}
	//for (int i=0;i<n;i++) cout<<a[i]<<" ";
	for (int i=0;i<n;i++)
		if (a[i]>0){
			k="";
			for (int j=s-a[i];j>=a[i]-1;j--)
				k+=st[j];
			d=0;
			for (int j=a[i]-1;j<=s-a[i];j++){
				st[j]=k[d];
				d++;
			}
		}
	cout<<st;
	return 0;
}
