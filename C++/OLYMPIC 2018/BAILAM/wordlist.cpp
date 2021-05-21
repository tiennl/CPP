#include <iostream>
#include <string>
using namespace std;
main(){
	string st;
	getline(cin,st);
	while ((st[1]<'A') || ((st[1]>'Z') && (st[1]<'a')) || (st[1]>'z')){
		st.erase(1,1);
	}
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
			if (((st[i+1]>='a')&& (st[i+1]<='z')) || ((st[i+1]>='A') && (st[i+1]<='Z'))){
			    dem++;
		    }
		}
	}
	for (int i=1; i<dem; i++){
		if (A[i]!=" "){
	        cout<<A[i]<<endl;
		}
    }
    cout<<A[dem];
}
