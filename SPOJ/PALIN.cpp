#include <bits/stdc++.h>
using namespace std;
int main(){
	int i,j,k,l,start,end,m,mstart,mend;
	char c;
  	string s;
  	unsigned short A[1000002];
  	cin>>i;
  	while(i--){
    	l=1;
    	cin>>s;
    	while(l<=s.length()){
      	A[l]=s[l-1] -'0';
      	l++;
    }
    start=1;
    end=l-1;
    mend=end;         
    A[end]++; 
    while(A[end] > 9){
      	A[end]=A[end]-10;
      	end--;
      	A[end]++;
    }
    if(end < start){
      	start--;
      	A[start]=1;
    }
    mstart=start;        
    end=mend;
    while(mstart<mend){
      	if(A[mstart]>A[mend]) A[mend]=A[mstart];
        else if(A[mstart]<A[mend]){
			if(mstart+1==mend){
	  			A[mstart]++;
	  			A[mend]=A[mstart];
			}
			else{   
				A[mend]=A[mstart];
	  			m=mend-1;
	  			A[m]++;
	  			while(A[m] > 9){
	    			A[m]=A[m]-10;
	    			m--;
	    			A[m]++;
	  			}
			}
      	}
      	mstart++;
     	mend--;
    } 
    mstart=start;
    mend=end;
    while(mstart<mend){
      	A[mend]=A[mstart];
      	mstart++;
      	mend--;
    }                                                                      
    for(j=start;j<=end;j++){
      	cout<<A[j];
    }
    cout<<endl;
  }
  return 0;
              
}

