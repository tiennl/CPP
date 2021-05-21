#include <iostream>
#include <cstring>

using namespace std;

char digits[664579][10];
bool isnotprime[10000000];

int main() {
    char buffer[16], given[10];
    int t, primes = 0;

    for (int i = 2; i < 10000000; ++i) {
        if (!isnotprime[i]) {
            for (int j = i + i; j < 10000000; j += i) isnotprime[j] = true;
            for (int j = i; j > 0; j /= 10) ++digits[primes][j % 10];
            ++primes;
        }
    }

    for (cin >> t; t > 0; --t) {
        cin >> buffer;
        memset(given, 0, sizeof given);
        for (char *p = buffer; *p; ++p) ++given[*p - '0'];

        int result = 0;

        for (int j, i = 0; i < primes; ++i) {
            for (j = 0; j < 10; ++j) if (given[j] < digits[i][j]) break;
            if (j >= 10) ++result;
        }

        cout << result << endl;
    }

    return 0;
}
