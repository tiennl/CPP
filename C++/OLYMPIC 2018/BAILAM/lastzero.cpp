#include <iostream>
using namespace std;
main(){
	int n,dem,kt,i,ii;
	cin>>n;
	dem=0;
	kt=0;
	i=0;
	while (kt==0){
		i++;
		if (5*i<=n){
			dem++;
			ii=i;
			while (ii>=5){
				if (ii%5==0){
					dem++;
					ii=ii/5;
				}
				else break;
			}
		}
		else{
			kt=1;
			break;
		}
	}
    cout<<dem;
}
