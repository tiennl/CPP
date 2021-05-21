#include <cstdlib>
#include <ctime>
#include <iostream>
int main()
{
	long long n;
	cin>>n;
	srand(time(NULL));
	int a = rand() % n + 1;
	return 0;
}
