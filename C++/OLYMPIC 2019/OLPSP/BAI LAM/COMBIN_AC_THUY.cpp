#include<bits/stdc++.h>
using namespace std;

int a[100000] ;
int k , n, m,  dem = 0;
void printResult() { 
    for(int i = 1 ; i <=k ; i++) {
        cout<<a[i]<<" " ;
    }
}
void backtrack(int i) { 
    for(int j = a[i-1]+1 ; j<=n-k+i ; j++ ) { 
        a[i] = j ; 
        if(i == k ) { 
			dem ++;
//			cout << dem<<" \n";
			if(dem == m + 1)
	            printResult() ;
        }
        else {
            backtrack(i+1) ;
        }
 
    }
}
void toHop() {
    if(k>=0 && k <=n ) {
        a[0] = 0 ; 
        backtrack(1) ;
    } 
}
 
 
int main()
{
    cin >> n >> k >> m;
    toHop()  ;
    return 0;
}
