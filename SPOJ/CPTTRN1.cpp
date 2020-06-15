#include <bits/stdc++.h>
using namespace std;
int main(){
	long long t,l,c;
	cin>>t;
	while (t--){
		cin>>l>>c;
		for (int i=1;i<=l;i++){
			if (i%2!=0)
				for (int j=1;j<=c;j++)
					if (j%2!=0) cout<<"*";
					else cout<<".";
			else  
				for (int j=1;j<=c;j++)
					if (j%2==0) cout<<"*";
					else cout<<".";
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
