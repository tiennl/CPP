#include <iostream>
#include <string>
using namespace std;
int string_to_num(char c){
	return c-'0';
}
char num_to_string(int n){
	return (char)(n+48);
}
void chuan_hoa(string &a, string &b){ // lam 2 xau co length bang nhau
    int l1=a.length(), l2=b.length();
    if (l1>=l2){
    	b.insert(0,l1-l2,'0');
	}
	else{
		a.insert(0,l2-l1,'0');
	}
}
// cong 2 so lon
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
// nhan so 1 chu so voi so nhieu chu so
string nhan_nho(char a, string b){
	string s="";
	int temp=0;
	for (int i=b.length()-1; i>=0; i--){
		temp=string_to_num(a)*string_to_num(b[i])+temp;
		s.insert(0,1,num_to_string(temp%10));
		temp=temp/10;
	}
	if (temp>0){
		s.insert(0,1,num_to_string(temp));
	}
	return s;
}
// nhan 2 so lon
string nhan(string a, string b){
	string s="";
	int l=a.length();
	string s1[l];
	for (int i=l-1; i>=0; i--){
	    s1[i]=nhan_nho(a[i],b);
	    s1[i].insert(s1[i].length(),l-i-1,'0');
	    s=sum(s,s1[i]);
	}
	return s;
}
int main(int argc, char **argv){
	string a,b,s;
	getline(cin,a);
	getline(cin,b);
	s=sum(a,b);
	cout<<s<<endl;
	s=nhan(a,b);
	cout<<s;
	return 0;
}
