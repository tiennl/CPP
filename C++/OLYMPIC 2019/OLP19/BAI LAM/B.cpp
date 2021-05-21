#include <bits/stdc++.h>
long long s1[1000000],s2[1000000];
using namespace std;
int main(){
	long long n,m,c1,c2,pos=0,coun=0,minn=0;
	cin>>n>>m>>c1>>c2;
	for (int i=0;i<n;i++) cin>>s1[i];
	for (int i=0;i<m;i++) cin>>s2[i];
	sort(s1,s1+n);
	sort(s2,s2+m);
	minn=abs(s1[0]-s2[0])+abs(c1-c2);
	for (int i=0;i<n;i++){
		pos=lower_bound(s2,s2+m,s1[i])-s2;
		if (pos>=0 && pos<m) minn=min(minn,abs(s1[i]-s2[pos])+abs(c1-c2));
		if (pos-1>=0 && pos-1<m) minn=min(minn,abs(s1[i]-s2[pos-1])+abs(c1-c2));
		if (pos+1>=0 && pos+1<m) minn=min(minn,abs(s1[i]-s2[pos+1])+abs(c1-c2));
	}
	for (int i=0;i<n;i++){
		pos=lower_bound(s2,s2+m,s1[i])-s2;
		if (pos>=0 && pos<m && abs(s1[i]-s2[pos])+abs(c1-c2)==minn) coun++;
		if (pos-1>=0 && pos-1<m && abs(s1[i]-s2[pos-1])+abs(c1-c2)==minn) coun++;
		if (pos+1>=0 && pos+1<m && abs(s1[i]-s2[pos+1])+abs(c1-c2)==minn) coun++;
	}
	cout<<minn<<" "<<coun;
	return 0;
}
