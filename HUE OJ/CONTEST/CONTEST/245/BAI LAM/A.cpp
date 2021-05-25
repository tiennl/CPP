#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	int s = 0;
	
	cin >> n;
	for (int i = 1; i <= sqrt(n); i++) 
	{
		if (n % i == 0) 
		{
			int j = n/i;
			if (i == j) 
			{
				s = s + i;
			} else 
			{
				s = s + i + j;
			}
		}
	}
	if(s-n>n)cout<<"YES";
	else cout<<"NO";
	
	return 0;	
}
