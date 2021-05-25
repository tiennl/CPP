#include <bits/stdc++.h>
using namespace std;
int main(){
	char ch;
	long long a,b,c,d;
	cin>>a>>ch>>b>>c>>ch>>d;
	if (pow(a,b)>pow(c,d)) cout<<a<<"^"<<b;
	else cout<<c<<"^"<<d;
	return 0;
}
