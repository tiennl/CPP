#include <bits/stdc++.h>
using namespace std;

main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
    	long long n;
    	int a;
    	int s = 0;
    	cin>>n;
    	if(n<0) n = -n;
    	while(n != 0){
    		a = n%10;
    		if(a%2 == 0) s += a;
    		n /= 10;
		}
		cout << s << "\n";
	}
    return 0;
}
