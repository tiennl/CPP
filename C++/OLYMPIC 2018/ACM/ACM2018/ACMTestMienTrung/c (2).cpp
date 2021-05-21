#include <iostream>
#include <string>

using namespace std;



int main(){
    
    string s,t;
    getline(cin,s);
    
    /*while (s[0]=='/' && s[1]=='/') s.erase(0,1);
   for (int i=0;i<s.size();i++){
        if (s[i]=='/' && s[i+1]=='/') s.erase(i,1);
    
    while (s[s.size()-1]=='/') s.erase(s.size()-1,1);
    cout<<s;*/
    
    
    
    
    
    char last = 'c';
    
    
    for (int i =0; i < s.size(); i++) {
       
        if(last == '/' && s[i] == '/'){
            continue;
        }
        
    

        last = s[i];
        
        t += s[i];
        
    }
    
    
    int lenght = (int)t.size();
    for (int i =0; i < t.size(); i++) {
        if(i == lenght -1 && t[i] == '/'){
            continue;
        }
        cout << t[i];
    }
    
    return 0;
}
//usr///local//nginx/sbin//
