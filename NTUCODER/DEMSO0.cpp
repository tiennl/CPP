#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,num,count2=0,count5=0;
	cin>>n;
	for (int i=1;i<=n;i++){
		num=i;
		while (num>0 && (num%2==0 || num%5==0)){
			if (num%2==0){
				count2++;
				num/=2;
			}
			if (num%5==0){
				count5++;
				num/=5;
			}
		}
	}
	cout<<min(count2,count5);
	return 0;
}
