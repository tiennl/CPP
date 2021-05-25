#include <bits/stdc++.h> 
using namespace std;
#define ll long long
ll a[1000000],b[1000000];
int main(){ 
  	ll n,h=0,c=0;
  	cin>>n;
  	for (int i=0;i<n;i++) cin>>a[i];
  	for (int i=0;i<n;i++){
  		cin>>b[i];
		if (a[i]>b[i]) h++;
		else if (a[i]<b[i]) c++;	
	}
	cout<<h<<" "<<c;
    return 0; 
} 
