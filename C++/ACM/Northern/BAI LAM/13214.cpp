#include <bits/stdc++.h>

using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long 
#define ull unsigned long long
#define N 1000005

ull A[N],A_sq[N];

int main(){
	FIO
	ll n;
	cin>>n;
	for (int i=0;i<n;i++) cin>>A[i];
	sort(A,A+n);
            for (int i = 0; i < n; i++){
                A_sq[i] = A[i] * A[i];
            }
              int acute = 0, right = 0, obtuse = 0;
            for (int i = 0; i < n-2; i++)
            {
                for (int j = i + 1; j < n-1; j++)
                {
                    int k = j + 1;
                    int AiPlusAj = A[i] + A[j];

                    while (k < n)
                    {
                        int squareSum = A_sq[i] + A_sq[j];
                        if (AiPlusAj <= A[k])
                        {
                            break;
                        }
                        else if (squareSum > A_sq[k])
                        {
                            acute++;
                        }
                        else if (squareSum < A_sq[k])
                        {
                            obtuse++;
                        }
                        else
                        {
                            right++;
                        }
                        k++;
                    }
                }
            }
            
            cout<< acute << " " << right << " " << obtuse;
	return 0;
}
