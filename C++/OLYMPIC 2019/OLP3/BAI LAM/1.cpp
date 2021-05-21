#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<long long, int> map;

int main()
{
	int n,k;

	cin >> n >> k;

	long long A[n];
	long long soDu;
	int total = 0;

	for (int i = 0; i <n ; ++i)
	{
		cin >> A[i];

		soDu = A[i] %k;

		if(map[k-soDu] != 1){
			total ++;
			map[soDu] = 1;
		}


	}


	cout << total;

	return 0;
}
