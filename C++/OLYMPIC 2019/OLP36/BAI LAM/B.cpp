#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define N 10005
ll a[N]; 
int main(){
	FIO
	ll n=-1,coun=0;
	string s;
	cin>>s;
	n=s.size();
	for (int i=0;i<n;i++){
		a[i]=(int)(s[i]-48);
		if (a[i]==9) coun++;
	}
	if (coun==n){
		cout<<1;
		for (int i=1;i<n;i++) cout<<0;
		cout<<1;
		return 0;
	}	
	int mid=n/2; 
    bool l=false; 
    int i=mid-1; 
    int j=(n%2) ? mid+1 : mid; 
    while (i>=0 && a[i]==a[j]) i--,j++; 
    if (i<0 || a[i]<a[j]) l=true; 
    while (i>=0) a[j]=a[i],j++,i--; 
    if (l){ 
        int temp=1; 
        i=mid-1; 
        if (n%2==1){ 
            a[mid]+=temp; 
            temp=a[mid]/10; 
            a[mid]%=10; 
            j=mid+1; 
        } 
        else j=mid; 
        while (i>=0){ 
            a[i]+=temp; 
            temp=a[i]/10; 
            a[i]%=10; 
            a[j++]=a[i--];
        } 
    } 
    for (int i=0;i<n;i++) cout<<a[i];
	return 0;
}
