#include <bits/stdc++.h>
long long a[1000000][100],c[1000000],coun[1000000];
using namespace std;
int main(){
	long long n,d=0,sl=0;
	string s;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>s;
        d=0;
   	 	bool ok=0;
    	for (int i=0;i<s.size();i++){
    		sl++;
        	if (a[d][s[i]]==0) a[d][s[i]]=sl;
        	d=a[d][s[i]];
        	c[d]++;
        	if (ok==0) cout<<s[i];
        	if (c[d]==1) ok=1;
    	}
    	coun[d]++;
    	if (ok==0) cout<<" "<<coun[d];
    	cout<<endl;
    }
    return 0;
}
