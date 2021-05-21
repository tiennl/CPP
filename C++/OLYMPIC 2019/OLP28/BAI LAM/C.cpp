#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000][1000];
ll n;
void sum(int x){
	priority_queue <ll> q;
	for (int i=0;i<n;i++)
		q.push(a[0][i]+a[x][0]);
	for (int i=0;i<n;i++)
		for (int j=1;j<n;j++)
			if (a[0][i]+a[x][j]<q.top()){
				q.pop();
				q.push(a[0][i]+a[x][j]);
			}
			else break;
	ll k=n-1;
	while(!q.empty()){
		a[0][k--]=q.top();
		q.pop();
	}
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++) cin>>a[i][j];
		sort(a[i],a[i]+n);
	}
	for (int i=1;i<n;i++) sum(i);
	for (int i=0;i<n;i++) cout<<a[0][i]<<" ";
	return 0;
}
