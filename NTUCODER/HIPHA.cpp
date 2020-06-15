#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,num,coun1=0,coun2=0;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>num;
		if (num==1) coun1++;
		else coun2++;
	}
	cout<<abs(coun1-coun2);
	return 0;
}
