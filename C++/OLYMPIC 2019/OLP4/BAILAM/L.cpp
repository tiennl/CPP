#include <bits/stdc++.h>
using namespace std;
long long a[100],b[100],c[100],d[100];
unsigned long long f[100][100];
bool kt[100];
int main(){
	long long n,m,pos;
	unsigned long long maxx=-100000000000,minn;
	minn=maxx;
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i]>>b[i];
	for (int i=1;i<=m;i++) cin>>c[i]>>d[i];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			f[i][j]=abs(a[i]-c[j])+abs(b[i]-d[j]);
			if (f[i][j]>maxx) maxx=f[i][j];
		}
	for (int i=1;i<=m;i++) kt[i]=1;
	for (int i=1;i<=n;i++){
		minn=maxx;
		pos=0;
        for (int j=1;j<=m;j++)
         	if (f[i][j]<minn && kt[j]==1){
         		minn=f[i][j];
         		pos=j;
			}
		kt[pos]=0;
		cout<<pos<<endl;
	
	}
	return 0;
}
