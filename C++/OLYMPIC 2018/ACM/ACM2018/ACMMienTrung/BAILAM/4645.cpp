#include <iostream>
#include <vector>
#include <algorithm>

#define FOR(i,a,b)  for(int i=a;i<=b;i++)
using namespace std;
vector<char> v;
int main()
{
    string s;
    cin>>s;
    int a[30];
    int n=s.length()-1;
    int mark=0;
    int count=0;
    int m=(-0x7fffffffffffffffL-1);
    FOR(i,0,n)
    {
        count=1;
        FOR(j,mark,i-1)
            if (s[i]!=s[j]) {
                count++;

                v.push_back(s[i]);

            }

            else mark=j+1;

        m=max(m,count);


        //cout << "m:" << m << " count: " << cout;
    }

    char lastC = '-';

    int inc = 0;

    for (int k = 0; k < v.size(); ++k) {
        if(lastC != v[k] && inc < m){
            cout << v[k];
            inc ++;
        }
        lastC = v[k];
    }



}
