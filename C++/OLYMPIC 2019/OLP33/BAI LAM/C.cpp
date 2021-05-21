#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000000 
ll a[N];
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,c,sum=0,res=0;
	cin>>n>>c;
	for (int i=0;i<n;i++) cin>>a[i];
	sum=a[0];
	ll i=0,j=0;
	while (i<n && j<n){
		if (sum<=c){
			j++;
			if (i<=j) res+=(j-i);
			if (j<n) sum+=a[j];
		}
		else{
			sum-=a[i];
			i++;
		}
	}
	cout<<res;
	return 0;
}
/*
5 6 
3 1 2 7 4
sum=3 i=0 j=0
j=1		res=0+1=1		sum=3+1=4	|	3
j=2		res=1+2=3		sum=4+2=6	|	3 1   |  1
j=3		res=3+3=6		sum=6+7=13  |   3 1 2 |  1 2  |  2
sum=13-3=10		i=1
sum=10-1=9 		i=2
sum=9-2=7		i=3
sum=7-7=0		i=4
j=4		res=6+0=6		sum=0+4=4
j=5		res=6+1=7		sum=4+0=4	|   4
*/
			
