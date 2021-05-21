#include <iostream>
 
using namespace std;
 
int tong(int a[], int left, int right)
{
    return left==right ? a[left] : a[left]+tong(a, left+1, right);
}
 
int main()
{
    int a[100], n;
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i];
   
    int max = a[0], max1;
    int imax = 0, jmax = 0;
   
    for (int i=0; i<n; ++i)
        for (int j=i; j<n; ++j)
        {
            if(i==0 && j==n-1)continue;
            max1 = tong(a, i, j);
            if(max1 > max) {max = max1; imax = i; jmax = j;}
        }
   
    cout << "\nDay ban dau: ";
    for (int i=0; i<n; ++i)
        cout  << a[i] << " ";
       
    cout << "\nDay con co tong max: ";
    for (int i=imax; i<=jmax; ++i)
        cout  << a[i] << " ";  
    cout << "\nn = " << max;
    system("pause");
}
 
