#include <iostream>
using namespace std;
int main(){
	int n,m,sl=0;
	cin>>n;
	int a[n];
	for (int i=0;i<n;i++) cin>>a[i];
	cin>>m;
	for (int i=0;i<n;i++)
		if (a[i]==m) sl++;
	if (sl>0){
		cout<<sl<<": ";
		for (int i=0;i<n;i++) 
			if (a[i]==m) cout<<i<<" ";
	}
	else cout<<"NotFound";
	return 0;
}
