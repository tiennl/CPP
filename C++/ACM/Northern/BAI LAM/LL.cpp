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
                  	ll max_obtuse = upper_bound(A+j+1, A+n, A[i] + A[j]) -A ;
			        ll max_right = upper_bound(A_sq+j+1, A_sq+n, A_sq[i] + A_sq[j]) - A_sq ;
			        ll max_acute = lower_bound(A_sq+j+1, A_sq+n, A_sq[i] + A_sq[j]) - A_sq;
			
			        
			        if (max_obtuse>j && max_obtuse<n && max_right>j && max_right<n) obtuse += max_obtuse - max_right;
			        if (max_acute>j && max_acute<n && max_right>j && max_right<n)right += max_right - max_acute;
			        if (max_acute>j && max_acute<n) acute += max_acute - j  ;
                    
                }
            }
            cout<< acute << " " << right << " " << obtuse;
	return 0;
}
