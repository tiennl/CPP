#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i=(a),_b=(b);i<_b;++i)
#define ll long long
#define ull unsigned long long

int main()
{
	int i,j,n;
	long s=0;
	scanf("%d", &n);
	i=1;
	j=1;
	int d=0;
	while (i!=1 || j!=1 || d==0){
		d = 0;
		s=0;
		while (d<n){
			printf("%d ", n*(i-1)+j);
			s += n*(i-1)+j;
			if (j==n){
				j=1;
			}
			else {
				j++;
				if (i==n) i=1;
				else i++;
			}
			d++;
		}
		printf("%ld\n", s);
	}
	return 0;
}
