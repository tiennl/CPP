#include <string> 
#include <iostream>
#include <sstream>
using namespace std;
string tostring (int a)
{
    ostringstream temp;
    temp<<a;
    return temp.str();
}
int main(){
    int a;
    cin>>a;
    cout<<tostring(a);
    return 0;
}
