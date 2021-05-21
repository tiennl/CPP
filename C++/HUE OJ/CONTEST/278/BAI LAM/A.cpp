#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

struct point{
	double x, y;
};

point a[N];
ll d[N];

double dis(point p1, point p2){
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

bool isSquare(point p1, point p2, point p3){
	double d1,d2,d3;
	d1=dis(p1,p2);
	d2=dis(p2,p3);
	d3=dis(p1,p3);
	double p=(d1+d2+d3)/2;
	double s1=sqrt(p*(p-d1)*(p-d2)*(p-d3));
	double s2=d1*d2/2;
	if (abs(s1-s2)<0.000005) return true;
	return false;
}

int main(){
	FIO
	ll t;
	cin>>t;
	while (t--){
		ll res=0;
		for (int i=1;i<=4;i++) cin>>a[i].x>>a[i].y;
		if (isSquare(a[1],a[2],a[3])) res++;
		if (isSquare(a[2],a[3],a[4])) res++;
		if (isSquare(a[3],a[4],a[1])) res++;
		if (isSquare(a[4],a[1],a[2])) res++;
		cout<<res<<endl;
	}	
	return 0;
}
