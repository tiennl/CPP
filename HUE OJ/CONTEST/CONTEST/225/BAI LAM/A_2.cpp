#include <bits/stdc++.h>
using namespace std;
typedef vector<long long> IntVec;
typedef vector<IntVec> Matrix;

int main(){
    int n;
    cin >> n;
    IntVec X(n+1,0);
    IntVec Y(n+1,0);
    IntVec SX(n+1,0);
    IntVec SY(n+1,0);

    for (int i = 0; i < n; i++)
    {
        cin >> X[i] >> Y[i];
    }
    SX[n-1] = X[n-1];
    SY[n-1] = Y[n-1];

    for (int i = n-2; i >=0 ; i--)
    {
        SX[i] = SX[i+1]+ X[i];
        SY[i] = SY[i+1] + Y[i];
    }

    long long rs = 0;
    for (int i = 0; i < n-1; i++)
    {
        rs += (X[i]*SX[i+1]);
        rs += (Y[i]*SY[i+1]);
    }

    rs *= -2;
    for (int i = 0; i < n; i++)
    {
        rs += (n-1)*(long long)X[i]*X[i];
        rs += (n-1)*(long long)Y[i]*Y[i];
    }
    cout << rs;
    return 0;
}
