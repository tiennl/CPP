#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define N 1000005

int main(){
	FIO
	ll n;
	cin>>n;
	switch (n){
		case 1: cout<<"January";
				break;
		case 2: cout<<"February";
				break;
		case 3: cout<<"March";
				break;
		case 4: cout<<"April";
				break;
		case 5: cout<<"May";
				break;
		case 6: cout<<"June";
				break;
		case 7: cout<<"July";
				break;
		case 8: cout<<"August";
				break;
		case 9: cout<<"September";
				break;
		case 10: cout<<"October";
				break;
		case 11: cout<<"November";
				break;
		case 12: cout<<"December";
				break;	
		default: cout<<"invalid Month number!";
				break;
	}	
	return 0;
}
