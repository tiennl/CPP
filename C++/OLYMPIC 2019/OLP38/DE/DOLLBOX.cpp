#include <bits/stdc++.h>
#define debug(x) cerr<<#x<<" = "<<x<<"\n"
using namespace std;

const int MAX=20;
int n,a[MAX],b[MAX];
int64_t f[1<<MAX];

int getBit(int x,int k)
{
	return (x>>k)&1;
}

int turnBit(int x,int k)
{
	return x^(1<<k);
}

int main() {
#ifdef ACM
	freopen("input","r",stdin);
#endif
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];
	f[0]=1;
	for(int mask=1;mask<(1<<n);mask++)
	{
		int tmp=__builtin_popcount(mask);
		for(int i=0;i<n;i++)
			if(getBit(mask,i)==1&&a[tmp-1]<=b[i])
				f[mask]+=f[turnBit(mask,i)];
	}
	cout<<f[(1<<n)-1];
}

