#include <iostream>
#include <string>
#include <sstream>
using namespace std;
string xaudao(string x){
    string ss="";
    for (int h=x.size()-1;h>=0;h--) ss+=x[h];
    return ss;
}
template<typename T>
inline std::string tostring(const T& x){
	std::ostringstream o;
	o << x;
	return o.str();
}
main(){
    int a,b;
    long long max,a1,a2,a3;
    string s;
    cin>>a>>b;
    cin>>a1>>a2>>a3;
    max=a1;
    if (a2>max) max=a2;
    if (a3>max) max=a3;
    s=tostring(a)+tostring(b);
    while (s.size()<max) s+=xaudao(s);
    cout<<((int)s[a1-1]-48)+((int)s[a2-1]-48)+((int)s[a3-1]-48);
    
}