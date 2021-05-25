#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

struct team{
	string x;
	ll y,z,w;
};

team a[N];
bool check[N]={false};

bool cmp(team &a, team &b){
	if (a.y!=b.y) return a.y>b.y;
	return a.z<b.z;
}

int main(){
	FIO
	ll n,coun=0;
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>a[i].x>>a[i].y>>a[i].z>>a[i].w;
	sort(a,a+n,cmp);
	for (int i=0;i<n;i++)
		if (!check[a[i].w] && coun<10){
			coun++;
			check[a[i].w]=true;
			cout<<a[i].x<<endl;
		}
	return 0;
}

/*
13
Team1 8 30 1
Team2 7 30 2
Team3 8 34 3
Team4 7 20 4
Team5 4 10 5
Team6 7 20 1
Team7 4 50 6
Team8 5 45 7
Team9 2 55 8
Team10 1 43 9
Team11 0 0 10
Team12 4 54 10
Team13 1 55 11
*/
