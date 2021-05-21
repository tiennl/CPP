#include <iostream>
long long** arr,brr;
using namespace std;
int main(){
	long long n,m, vertical=1e5;
	cin>>n>>m;
	arr=new long long*[vertical+1];
	
    for(int i=0; i<n; i++)
    {
    	for (int j=0;j<m;j++){
			arr[i]=new long long[n];
        	cin>>arr[i][j]; 
        }
    }
    cout<<"ahihi";
    return 0;
}
