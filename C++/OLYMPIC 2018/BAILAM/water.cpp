#include <iostream>
using namespace std;
int a[1000];
int b[1000];
int c[1000];
int s[1000000];
main(){
	int n,min,max;
	cin>>n;
	int nuoc=0;
	int thung=n;
	min=10000000;
	max=0;
	for (int i=0;i<n;i++){
		cin>>b[i]>>c[i];
		nuoc=nuoc+b[i];
		s[c[i]]++;
		if (c[i]<min) min=c[i];
		if (c[i]>max) max=c[i];
    }
    int i=min;
    while ((i<=max) && (nuoc>0)){
    	if ((s[i]!=0) && (nuoc>=i)){
    		s[i]--;
    		thung--;
    		nuoc=nuoc-i;
		}
		if (s[i]==0) i++;
	}
    cout<<thung;
}
