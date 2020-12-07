#include <iostream>
using namespace std;
int a[100000];
int find(int a[],int n,int x){
	int l=0;
	int r=n-1;
	int g=(l+r)/2;
	while (g!=l && g!=r){
		if (a[g]>=x) r=g;
		else l=g;
		g=(l+r)/2;
	}
	for (int g=r;g>=l;g--)
		if (a[g]<=x){
			return g;
			break;
		}
		
}
main(){
	int n,res,x,l,r,g;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<8;i++){
		cout<<"x= ";
		cin>>x;
	    cout<<find(a,n,x)<<endl;
	}

}
