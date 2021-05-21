#include <bits/stdc++.h> 
#include <set>
#include <iterator>
using namespace std; 
void countSmallerRight(int A[], int len) 
{ 
    set<int> s; 
    int countSmaller[len]; 
    for (int i = len - 1; i >= 0; i--) { 
        s.insert(A[i]); 
        
        countSmaller[i] = distance(s.begin(), s.lower_bound(A[i]) ); 
    } 
  
    for (int i = 0; i < len; i++) 
        cout << countSmaller[i] << " "; 
} 
  
// Driver code 
int main() 
{ 
    int A[] = {12, 1, 2, 3, 0, 11, 4}; 
    int len = sizeof(A) / sizeof(int); 
    countSmallerRight(A, len); 
    return 0; 
} 
