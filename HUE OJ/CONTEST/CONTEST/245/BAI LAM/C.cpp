#include <bits/stdc++.h> 
using namespace std; 
long long a[10000001];

int main() { 
	int n; 
	cin >> n; 	 	
	for(int i =0; i < n; i++) 
	     cin>>a[i]; 
	map<long long,int> fs; 	 
	fs[0] = 1; 	 
	long long s = 0; 	 
	long long dem = 0; 	 
	for(int i =0; i < n; i++) { 	
	    s += a[i]; 	 	 
	    dem += fs[s]++; 
	    if(dem > 0){
	        cout << "YES";
	        return 0;
        }
	}  	 
	cout << "NO"; 
	return 0; 
}
