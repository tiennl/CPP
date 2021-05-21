//tim v tri cua x
#include <iostream>
using namespace std;
int a[100000];
main(){
	int n,res,x,l,r,g;
	bool find;
	cin>>n>>x;
	for (int i=0;i<n;i++) cin>>a[i];
	l=0;
	r=n-1;
	find=false;
	while (l<=r && !find){
		g=(l+r)/2;
		if (x==a[g]) find=true;
		else 
			if (x<a[g]) r=g-1;
			else l=g+1;	
	}
	if (find) res=g;
	else res=-1;
	cout<<res;
}
