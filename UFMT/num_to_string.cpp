#include <iostream>
#include <string>
#include <sstream>
using namespace std;
template<typename T>
inline std::string tostring(const T& x){
	std::ostringstream o;
	o << x;
	return o.str();
}
int main(){
	int xx,yy;
	std::cin>>xx>>yy;
	std::cout<<tostring(xx)+tostring(yy);
}
