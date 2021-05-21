#include <bits/stdc++.h>
using namespace std;
int main(){
	long long res=0,k=-1;
	string a,b;
	cin>>a>>b;
	for (int i=0;i<=b.size()-a.size();i++){
		k=-1;
		for (int j=i;j<i+a.size();j++){
			k++;
			if (b[j]==a[k]) res++;
		}
	}
	cout<<res;
	return 0;
}
