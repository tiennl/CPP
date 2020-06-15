#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,res=0,num;
	cin>>n;
	for (int i=0;i<n;i++){
		res=0;
		for (int j=0;j<n;j++){
			cin>>num;
			res+=num;
		}
		cout<<res<<endl;
	}
	return 0;
}
