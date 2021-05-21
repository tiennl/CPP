#include <iostream>
using namespace std;
 
int main() {
 
   string str = "This is text";
 
  
   // Tr? v? chu?i con t? ch? s? th? 3 t?i cu?i chu?i.
   string substr = str.substr(3);
 
   cout << "- str.substr(3)=" << substr << endl;
 
  
   // Tr? v? chu?i con t? ch? s? th? 2 cho t?i ch? s? 7
   substr = str.substr(2,7);
 
   cout << "- str.substr(2, 7) =" << substr << endl;
 
}
