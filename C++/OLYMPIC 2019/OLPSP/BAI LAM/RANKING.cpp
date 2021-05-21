#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define N 1000000 
ll n,coun=0;
bool used[N]={false};
struct team{
	string x;
	int y,z,w;
};
team a[N];
bool SS(team &a, team &b){
	if (a.y!=b.y) return a.y>b.y;
	return a.z<b.z;
}
int main(){
	FIO
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>a[i].x>>a[i].y>>a[i].z>>a[i].w;
	sort(a,a+n,SS);
	for (int i=0;i<n;i++)
		if (!used[a[i].w] && coun<10){
			coun++;
			used[a[i].w]=true;
			cout<<a[i].x<<endl;
		}
	return 0;
}
