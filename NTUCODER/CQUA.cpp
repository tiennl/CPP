#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,num,count1=0,count2=0;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>num;
		if (num==100) count1++;
		else count2++;
	}
	if (count1%2!=0 || (count1==0 && count2%2!=0)) cout<<"NO";
	else cout<<"YES";
	return 0;
}
