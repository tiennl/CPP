#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	cin>>n;
	for (int i=n;i>0;i--){
		for (int j=i;j>0;j--) cout<<"*";
		if (i>1) cout<<endl;
	}
	return 0;
}
