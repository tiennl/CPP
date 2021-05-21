#include <stdio.h> 
void printArray (int arr[], int n);
int AreAll9s (int num[], int n ); 
void generateNextPalindromeUtil (int num[], int n ) 
{ 
    int mid = n/2; 
    bool leftsmaller = false; 
    int i = mid - 1; 
    int j = (n % 2)? mid + 1 : mid; 
    while (i >= 0 && num[i] == num[j]) 
        i--,j++; 
    if ( i < 0 || num[i] < num[j]) 
        leftsmaller = true; 
    while (i >= 0) 
    { 
        num[j] = num[i]; 
        j++; 
        i--; 
    } 
    if (leftsmaller == true) 
    { 
        int carry = 1; 
        i = mid - 1; 
        if (n%2 == 1) 
        { 
            num[mid] += carry; 
            carry = num[mid] / 10; 
            num[mid] %= 10; 
            j = mid + 1; 
        } 
        else
            j = mid; 
        while (i >= 0) 
        { 
            num[i] += carry; 
            carry = num[i] / 10; 
            num[i] %= 10; 
            num[j++] = num[i--]; // copy mirror to right 
        } 
    } 
} 
void generateNextPalindrome( int num[], int n ) 
{ 
    int i; 
  
    printf("Next palindrome is:");  
    if( AreAll9s( num, n ) ) 
    { 
        printf( "1 "); 
        for( i = 1; i < n; i++ ) 
            printf( "0 " ); 
        printf( "1" ); 
    } 
    else
    { 
        generateNextPalindromeUtil ( num, n ); 
        printArray (num, n); 
    } 
} 
  
// A utility function to check if num has all 9s 
int AreAll9s( int* num, int n ) 
{ 
    int i; 
    for( i = 0; i < n; ++i ) 
        if( num[i] != 9 ) 
            return 0; 
    return 1; 
} 
  
/* Utility that prints out an array on a line */
void printArray(int arr[], int n) 
{ 
    int i; 
    for (i=0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
  
// Driver Program to test above function 
int main() 
{ 
    int num[] = {7,5,3,7,8,4,6,5}; 
  
    int n = sizeof (num)/ sizeof(num[0]); 
  
    generateNextPalindrome( num, n ); 
  
    return 0; 
} 
