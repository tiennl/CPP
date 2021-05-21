// C++ implementation of the above approach 
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to find previous number 
void findPrevious(string number, int n) 
{ 
    int i, j; 
  
    // I) Start from the right most digit 
    // and find the first digit that is 
    // smaller than the digit next to it. 
    for (i = n - 1; i > 0; i--) 
        if (number[i] < number[i - 1]) 
            break; 
  
    // If no such digit is found 
    // then all digits are in ascending order 
    // means there cannot be a smallest number 
    // with same set of digits 
    if (i == 0) { 
        cout << "Previous number is not possible"; 
        return; 
    } 
  
    // II) Find the greatest digit on 
    // right side of (i-1)'th digit that is 
    // smaller than number[i-1] 
    int x = number[i - 1], greatest = i; 
    for (j = i; j < n; j++) 
        if (number[j] < x && number[j] > number[greatest]) 
            greatest = j; 
  
    // III) Swap the above found smallest digit with number[i-1] 
    swap(number[greatest], number[i - 1]); 
  
    // IV) Sort the digits after (i-1) in descending order 
    sort(number.begin() + i, number.begin() + n, greater<char>()); 
  
    cout << "Greatest smaller number with same set of digits is " << number; 
  
    return; 
} 
  
// Driver code 
int main() 
{ 
    string digits = "1243"; 
    int n = digits.length(); 
  
    findPrevious(digits, n); 
  
    return 0; 
} 
