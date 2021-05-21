#include <bits/stdc++.h>
#include <string.h>
#include <vector>
#include <map>

using namespace std;
vector<string> v;
map<char, int> m;

int main(){
	
	string s,st;
	getline(cin,s);
	getline(cin,st);
	
	string t = "";
	
	
	for(int i = 0; i< s.size(); i++){
		m[s[i]] = 0;
	}
	
	for(int i = 0; i< s.size(); i++){
		m[s[i]] ++;
	}
	
	
	for(int i =0; i< st.size(); i++){
		if(st[i] != ' '){
			t+= st[i];
		}
		
		if(st[i] == ' ' || i == st.size() -1){
			
			v.push_back(t);
			t = "";
		}
	}
	
	
	
	int A[v.size() -1];
	
	for(int i = 0; i < v.size(); i++){
		A[i] = 0;
	}
	
	
	string tt = "";
	int deleteCount = 0;
	
	for(int i =0; i< s.size(); i++){
		for(int j = 0; j < v.size(); j++){
			if(A[j] == 1){
				continue;
			}
			
			tt = v[j];
			
			if(tt.size() > 0 && tt[0] == s[i]){
				
				deleteCount ++;
				A[j] = 1;
				cout << v[j] << ' ';
				m[s[i]] --;
				cout << "test:" << s[i] << ": "<< m[s[i]] << endl;
				if(m[s[i]] > 0){
					break;
				}
			
			
				
			
			}
		}
	}
	


	return 0;
}
