#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,y,res=0;
	cin>>n;
	while (n--){
		cin>>y;
		if (y%19==0 || y%19==3 || y%19==6 || y%19==9 || y%19==11 || y%19==14 || y%19==17)
			res++;
	}
	cout<<res;
	return 0;
}
