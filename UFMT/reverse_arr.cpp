#include <iostream>
#include <algorithm>
using namespace std;
 int a[1000];
int main()
{
	int n;
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	reverse(a,a+n); 
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}