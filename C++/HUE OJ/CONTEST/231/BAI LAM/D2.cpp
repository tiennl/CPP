// A hashing based CPP program to find largest d 
// such that a + b + c = d. 
#include <bits/stdc++.h> 
using namespace std; 
  
// The function finds four elements with given sum X 
int findFourElements(int arr[], int n) 
{ 
    // Store sums  (a+b) of all pairs (a,b) in a  
    // hash table 
    unordered_map<int, pair<int, int> > mp; 
    for (int i = 0; i < n - 1; i++) 
        for (int j = i + 1; j < n; j++) 
            mp[arr[i] + arr[j]] = { i, j }; 
  
    // Traverse through all pairs and find (d -c) 
    // is present in hash table 
    int d = INT_MIN; 
    for (int i = 0; i < n - 1; i++) { 
        for (int j = i + 1; j < n; j++) { 
            int abs_diff = abs(arr[i] - arr[j]); 
  
            // If d - c is present in hash table, 
            if (mp.find(abs_diff) != mp.end()) { 
  
                // Making sure that all elements are 
                // distinct array elements and an element 
                // is not considered more than once. 
                pair<int, int> p = mp[abs_diff]; 
                if (p.first != i && p.first != j &&  
                    p.second != i && p.second != j) 
                    d = max(d, max(arr[i], arr[j])); 
            } 
        } 
    } 
    return d; 
} 
  
// Driver program to test above function 
int main() 
{ 
    int arr[] = { 2, 3, 5, 7, 12 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int res = findFourElements(arr, n); 
    if (res == INT_MIN) 
        cout << "No Solution."; 
    else
        cout << res; 
    return 0; 
} 
