#include <bits/stdc++.h>
#include <string>
using namespace std;
int string_to_num(char c){
	return c-'0';
}
char num_to_string(int n){
	return (char)(n+48);
}
void chuan_hoa(string &a, string &b){ 
    int l1=a.length(), l2=b.length();
    if (l1>=l2){
    	b.insert(0,l1-l2,'0');
	}
	else{
		a.insert(0,l2-l1,'0');
	}
}
string sum(string a, string b){    
	string s="";
	chuan_hoa(a,b);
	int l=a.length();
	int temp=0;
	for (int i=l-1;i>=0;i--){
		temp=string_to_num(a[i])+string_to_num(b[i])+temp;
		s.insert(0,1,num_to_string(temp%10));
		temp=temp/10;
	}
	if (temp>0){
		s.insert(0,1,num_to_string(temp));
	}
	return s;
}
int main(){
	long long n;
	string a,b,s;
	cin>>n;
	while (n--){
		cin>>a>>b;
		cout<<sum(a,b)<<endl;
	}
	return 0;
}





