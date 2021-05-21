#include <bits/stdc++.h> 
using namespace std; 
  
// It's better to use long long 
// to handle big integers 
#define ll long long 
  
// function to count no of digits 
ll dig(ll a) 
{ 
    ll count = 0; 
    while (a > 0) { 
        a /= 10; 
        count++; 
    } 
    return count; 
} 
  
// function to implement above approach 
void required_number(ll num, ll n, ll d) 
{ 
    ll i, j, power, a, flag = 0; 
    for (i = num; i >= 1; i--) { 
        power = pow(10, i); 
        a = n % power; 
  
        // if difference between power 
        // and n doesn't exceed d 
        if (d > a) { 
            flag = 1; 
            break; 
        } 
    } 
    if (flag) { 
        ll t = 0; 
  
        // loop to build a number from the 
        // appropriate no of digits containg only 9 
        for (j = 0; j < i; j++) { 
            t += 9 * pow(10, j); 
        } 
  
        // if the build number is 
        // same as original number(n) 
        if (n % power == t) 
            cout << n; 
        else { 
  
            // observation 
            cout << n - (n % power) - 1; 
        } 
    } 
    else
        cout << n; 
} 
  
// Driver Code 
int main() 
{ 
    ll n = 99, d = 4; 
  
    // variable that stores no of digits in n 
    ll num = dig(n); 
    required_number(num, n, d); 
    return 0; 
} 
