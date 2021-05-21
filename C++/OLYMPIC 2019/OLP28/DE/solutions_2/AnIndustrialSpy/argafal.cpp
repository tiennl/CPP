#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#define MAX 10000000
#include <set>
using namespace std;
bool notprime[MAX+1][2];
int digits[7];

//Berechnet Array notprime im Intervall [0,MAX]
void eratosthenes() {
	notprime[0][0] = notprime[1][0] = true;
	for (int i = 2; i*i <= MAX; i++) {
		if (notprime[i][0]) continue;
		for (int j = i*i; j <= MAX; j += i) notprime[j][0] = true;
	}
}

int main() {
	int tc;
	cin >> tc;
	eratosthenes();
	while (tc--) {
		string temp;
		int dgn = 0;
		int count = 0;
		set<int> S;
		cin >> temp;

		for(unsigned int i = 0; i < temp.length(); i++){
			digits[dgn++] = temp[i] - '0';
		}
		sort(digits, digits + dgn);
		do{
			for(int i = 1; i <= dgn; i++){
				int temp = 0;
				int faktor = 1;
				for(int j = 0; j < i; j++){
					temp += digits[dgn - j - 1] * faktor;
					faktor *= 10;
				}
				if(notprime[temp][0] == false && S.find(temp) == S.end()) {
					S.insert(temp);
					count++;
				}
			}
		} while(next_permutation(digits, digits + dgn));
		cout << count << endl;
	}

}
