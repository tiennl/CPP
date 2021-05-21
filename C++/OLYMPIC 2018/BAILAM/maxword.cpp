#include <iostream>
#include <string>
using namespace std;
main(){
	string st;
	getline(cin,st);
	int n;
	n=st.size();
	int dem;
	dem=1;
	string A[100];
	for (int i=0; i<n ; i++){
		if (((st[i]>='a')&& (st[i]<='z')) || ((st[i]>='A') && (st[i]<='Z'))){
			A[dem]=A[dem]+st[i];
		}
		else {
			dem++;
		}
	}
	int max;
	max=0;
	for (int i=0; i<=dem; i++)
	    if (A[i].size()>max){
	    	max=A[i].size();
		}
	cout<<max;
}
