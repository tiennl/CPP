#include <bits/stdc++.h> 
using namespace std; 
  
// function to check minimum number of digits 
// should be removed to make this number 
// a perfect square 
int perfectSquare(string s) 
{ 
    // size of the string 
    int n = s.size(); 
  
    // our final answer 
    int ans = -1; 
  
    // to store string which is perfect square. 
    string num; 
  
    // We make all possible subsequences 
    for (int i = 1; i < (1 << n); i++) { 
        string str = ""; 
          
        for (int j = 0; j < n; j++) { 
              
            // to check jth bit is set or not. 
            if ((i >> j) & 1) { 
                str += s[j]; 
            } 
        } 
  
        // we do not consider a number with leading zeros 
        if (str[0] != '0') { 
              
            // convert our temporary string into integer 
            int temp = 0; 
            for (int j = 0; j < str.size(); j++) 
                temp = temp * 10 + (int)(str[j] - '0'); 
  
            int k = sqrt(temp); 
  
            // checking temp is perfect square or not. 
            if (k * k == temp) { 
                  
                // taking maximum sized string 
                if (ans < (int)str.size()) { 
                    ans = (int)str.size(); 
                    num = str; 
                } 
            } 
        } 
    } 
  
    if (ans == -1) 
        return ans; 
    else { 
          
        // print PerfectSquare 
        cout << num << " "; 
        return n - ans; 
    } 
} 
  
// Driver code 
int main() 
{ 
    cout << perfectSquare("8314") << endl; 
    cout << perfectSquare("625") << endl;   
    return 0; 
} 
