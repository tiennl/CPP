#include <bits/stdc++.h>
using namespace std;
bool square(long long x){
	if (x%4==0) return true;
	return false;
}
long long rectangle(long long x){
	long long ans=0,j;
	for (int i=1;i<=sqrt(x);i++){
		j=x/2-i;
		if (j>i && (i+j)*2==x) ans++;
	}
	return ans;
}
long long triangle(long long x){
	long long ans=0,k;
	for (int i=1;i<x;i++)
		for (int j=i;j<x;j++){
			k=x-i-j;
			if (k>=i && k>=j){
				if (i+j>k && i+k>j && j+k>i && abs(i-j)<k && abs(i-k)<j && abs(j-k)<i) ans++;
			}
		}
	return ans;
}
int main(){
	long long t,n,squares=0,triangles=0,rectangles=0;
	cin>>t;
	while (t--){
		cin>>n;
		squares=0;
		triangles=0;
		rectangles=0;
		if (square(n)) squares=1;
		cout<<"Triangles: "<<triangle(n)<<endl;
		cout<<"Squares: "<<squares<<endl;
		cout<<"Rectangles: "<<rectangle(n)<<endl<<endl;
	}
	return 0;
}
