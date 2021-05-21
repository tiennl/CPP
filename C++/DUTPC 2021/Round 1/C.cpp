#include<bits/stdc++.h>

using namespace std;

long long n;
string a,b,c;
map<string, int> m;
map<string, bool> ck;

int main(){
   cin>>n;
   for(int i = 0;i < n;i++){
       cin>>a>>b>>c;
       string s = a+b+c;
       if(!ck[s]){
           ck[s] = true;
           m[c]++;
       }
    }
    map<string,int >::iterator i;
    for (i = m.begin(); i != m.end(); i++){
        cout << i->first<< " " << i->second << " ";
        if(i->second >= 10)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
	return 0;
}
