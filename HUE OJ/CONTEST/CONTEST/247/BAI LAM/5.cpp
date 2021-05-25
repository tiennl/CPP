#include <bits/stdc++.h>
using namespace std;
bool isTandemRepeat(std::string inputString)
{
    int n=inputString.size();
    if (n%2!=0) return false;
    string s1=inputString.substr(0,n/2),s2=inputString.substr(n/2+1,n);
    if (s1==s2) return true;
    return false;
}
int main(){
	string s="1111";
	int n=s.size();
	string s1=s.substr(0,n/2),s2=s.substr(n/2,n);
	cout<<s1<<endl<<s2;
	return 0;
}

