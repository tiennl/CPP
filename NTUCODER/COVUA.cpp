#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	cin>>n;
	for (int i=0;i<n;i++){
		if (i%2==0) 
			for (int j=0;j<n;j++)
				if (j%2==0) cout<<"W";
				else cout<<"B";
		else 	
			for (int j=0;j<n;j++)
				if (j%2==0) cout<<"B";
				else cout<<"W";
		cout<<endl;
	}
	return 0;
}
