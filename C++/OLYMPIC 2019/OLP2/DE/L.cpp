#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector<long long> v;


int main(int argc, char const *argv[])
{

	int t, n;

	cin >> t;

	long long a;


	for (int i = 0; i < t; ++i)
	{
		
		cin >> n;


		v.clear();
		for (int j = 0; j < n; ++j)
		{

			cin >> a;
			
			v.push_back(a);

		}


		long long maxSum = -10000000000;
		long long maxSumSofar = v[0];



		

		long long s = 0;
		long long maxNeg = v[0];
		for (int j = 1; j < v.size(); ++j)
		{

		
			maxSumSofar += v[j];
			if(maxSumSofar > maxSum){
				maxSum = maxSumSofar;
			}else{
				maxSumSofar = v[j];
			}
			if(v[j] > 0){
				s += v[j];
			}

			if(maxNeg < v[j]){
				maxNeg = v[j];
			}
			
		}

		if(s < 0){
			s = maxNeg;
		}

	
		cout << maxNeg << " " << maxSum << endl; 


	}

	
	return 0;
}