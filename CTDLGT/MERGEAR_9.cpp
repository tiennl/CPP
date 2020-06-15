#include <iostream>
#include <algorithm>
unsigned long long a[10000000];
using namespace std;
int main(){
	unsigned long long m,n;
	cin>>m>>n;
	for (int i=1;i<=m+n;i++) cin>>a[i];
	sort(a+1,a+m+n+1);
	cout<<m+n<<endl;
	for (int i=1;i<=m+n;i++) cout<<a[i]<<" ";
	return 0;
}
