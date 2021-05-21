#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define db double 
#define N 1000005

struct point{
	db x,y;
};

point arr[N],next[N];

double Striangle(point A, point B, point C){
	return abs((B.x*A.y-A.x*B.y) + (C.x*B.y-B.x*C.y) + (A.x*C.y-C.x*A.y))/2;
}

int main(){
	FIO
	ll n,pa=0,pb=1,pc=2;
	point a,b,c;
	db m;
	cin>>n;
	for (int i=0;i<n;i++) cin>>arr[i].x>>arr[i].y;
	m=Striangle(arr[0],arr[1],arr[2]);
	for (int i=0;i<n-2;i++)
		for (int j=i+1;j<n-1;j++)
			for (int k=j+1;k<n;k++)
				m=max(m,Striangle(arr[i],arr[j],arr[k]));
	cout<<m;
			 	
	return 0;
}
/*
5
0 0
0 3
1 5
2 4
3 0
*/










