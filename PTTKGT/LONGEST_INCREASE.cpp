// Day con tang dan dai nhat
#include <iostream>
using namespace std;

// Brute Force
int coun(int n, int a[]){
	if (n==0) return 0;
	int r=1,c=0;
	for (int i=0;i<n-1;i++){
		c=1;
		for (int j=i+1;j<n;j++)
			if (a[j]>a[j-1]) c++;
		else break;
		r=max(r,c);
	}
	return r;
}

// DP
int counDP(int n, int a[]){
	int dp[n];
	int r=1;
	if (n==0) return 0;
	dp[0]=1;
	for (int i=1;i<n;i++){
		if (a[i]>a[i-1]) dp[i]=dp[i-1]+1;
		else dp[i]=1;
		r=max(r,dp[i]);
	}
	return r;
}

int main(){
	int n=10;
	int a[n]={2,5,1,3,4,6,10,4,7,8};
	cout<<coun(n,a);
	return 0;
}
