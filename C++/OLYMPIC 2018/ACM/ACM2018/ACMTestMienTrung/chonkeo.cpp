#include <iostream>
using namespace std;
long long a[5000];
main(){
	int t,n,k,dem,th1;
	cin>>t;
	for (int i=0;i<t;i++){
		cin>>n>>k;
		th1=0;
		for (int j=0;j<n;j++){
			cin>>a[j];
			b[a[i]]++;
			if (b[a[i]]==n) th1=1;
		}
		if (th1==1){
			cout<<(n-2)*(n-1)*n<<endl;
		}
		else{
			
		}
	}
}
