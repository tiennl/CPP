#include <iostream>
#include <math.h>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <functional>
#include <numeric>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    if(a == b) return a;
    if(a < b) return gcd(b, a);
    if(b == 0) return a;
    return gcd(b, a % b);
}
int main(){
    int limit = 12;
    int* triangles = new int[limit + 1];
    memset(triangles, 0, sizeof(int) * (limit + 1));
 
    int result = 0;
    int mlimit = (int)sqrt((double)limit / 2);
 
    for (long m = 2; m < mlimit; m++) {
        for (long n = 1; n < m; n++) {
            if (((n + m) % 2) == 1 && gcd(n, m) == 1) {
                long a = m * m + n * n;
                long b = m * m - n * n;
                long c = 2 * m * n;
                long p = a + b + c;
                while(p <= limit){
                    triangles[p]++;
                    if (triangles[p] == 1) result++;
                    if (triangles[p] == 2) result--;
                    p += a + b + c;
                }
            }
        }
    }

    cout<<"Result "<<result<<endl;

    int wait = 0;
    cin>>wait;

    return 0; 
}
