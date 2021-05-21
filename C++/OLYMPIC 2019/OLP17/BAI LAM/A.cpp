#include <bits/stdc++.h>
long long a[10000000],b[10000000],m[10],n[10],p[10],q[10];
using namespace std;
int main(){
	long long nn,k;
	double minn=1000000000;
	double num=0;
	string s;
	cin>>nn>>k;
	for (int i=0;i<nn;i++) cin>>a[i]>>b[i];
	cin>>s;
	for (int i=0;i<nn-1;i++)
		for (int j=i+1;j<nn;j++){
			m[1]=m[2]=m[3]=a[i]+1;
			m[4]=m[5]=m[6]=a[i]-1;
			n[1]=n[4]=b[i]+1;
			n[2]=n[5]=b[i];
			n[3]=n[6]=b[i]-1;
			m[7]=m[8]=a[i];
			n[7]=b[i]+1;
			n[8]=b[i]-1;
			p[1]=p[2]=p[3]=a[i]+1;
			p[4]=p[5]=p[6]=a[i]-1;
			q[1]=q[4]=b[i]+1;
			q[2]=q[5]=b[i];
			q[3]=q[6]=b[i]-1;
			p[7]=p[8]=p[i];
			q[7]=b[i]+1;
			q[8]=b[i]-1;
			minn=sqrt((m[1]-p[1])*(m[1]-p[1])+(n[1]-q[1])*(n[1]-q[1]));
			for (int h=1;h<8;h++)
				for (int l=h+1;l<=8;l++){
					num=sqrt((m[h]-p[l])*(m[h]-p[l])+(n[h]-q[l])*(n[h]-q[l]));
					minn=min(minn,num);
				}
			
		}
	cout<<minn;
	return 0;
}
