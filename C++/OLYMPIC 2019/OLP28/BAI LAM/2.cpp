#include <iostream> 
#include <sstream> 
using namespace std; 
  
int main() 
{ 
    string s = "12345"; 
  
    // object from the class stringstream 
    stringstream str2num(s); 
  
    // The object has the value 12345 and stream 
    // it to the integer x 
    int x = 0; 
    str2num >> x; 
  
    // Now the variable x holds the value 12345 
    cout << "Value of x : " << x; 
  
    return 0; 
}
