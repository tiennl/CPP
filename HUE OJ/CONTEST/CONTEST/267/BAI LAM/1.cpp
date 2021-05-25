#include <bits/stdc++.h> 
using namespace std; 
  
// To print vector along size 
void printVector(vector<int> v) 
{ 
    // Print vector size 
    cout << v.size() << endl; 
  
    // Print vector elements 
    for (int i = 0; i < v.size(); i++) 
        cout << v[i] << " "; 
  
    cout << endl; 
} 
  
// To divide n in two groups such that 
// absolute difference of their sum is  
// minimum 
void findTwoGroup(int n) 
{ 
    // Find sum of all elements upto n 
    int sum = n * (n + 1) / 2; 
  
    // Sum of elements of group1 
    int group1Sum = sum / 2; 
  
    vector<int> group1, group2; 
  
    for (int i = n; i > 0; i--) { 
  
        // If sum is greater then or equal 
        // to 0 include i in group 1 
        // otherwise include in group2 
        if (group1Sum - i >= 0) { 
  
            group1.push_back(i); 
  
            // Decrease sum of group1 
            group1Sum -= i; 
        } 
        else { 
            group2.push_back(i); 
        } 
    } 
  
    // Print both the groups 
    printVector(group1); 
    printVector(group2); 
} 
  
// Driver program to test above functions 
int main() 
{ 
    int n = 7; 
    findTwoGroup(n); 
    return 0; 
} 
