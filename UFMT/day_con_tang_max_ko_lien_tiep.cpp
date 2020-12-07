#include<bits/stdc++.h>
using namespace std;
int m,a[100100],n,b[100100],f[100100];
int main(){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++){
        f[i]=lower_bound(b+1,b+1+m,a[i])-b;
        m=max(m,f[i]);
        b[f[i]]=a[i];
    }
    cout<<m<<endl;
    vector <int> v;
    for (int i=n;i>=1;i--)
        if (f[i]==m){
        	v.push_back(a[i]);
            m--;
    	}
    for (int i=v.size()-1;i>=0;i--) cout<<v[i]<<" ";
 	cout<<endl;
	for (int i=1;i<=n;i++) cout<<f[i]<<" ";
	cout<<endl;
	for (int i=1;i<=n;i++) cout<<b[i]<<" ";
    return 0;
}
/*
7
a:	3 	2 	5 	7 	2 	10 	6
f:	
b:	


*/    
