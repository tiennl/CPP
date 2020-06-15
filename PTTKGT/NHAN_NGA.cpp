#include <bits/stdc++.h>
using namespace std;
string a,b;

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

string chia(int divisor, string number){ 
    string ans; 
    int idx=0; 
    int temp=number[idx]-'0'; 
    while (temp<divisor) 
       temp=temp*10+(number[++idx]-'0'); 
    while (number.size()>idx){ 
        ans+=(temp/divisor)+'0'; 
        temp=(temp%divisor)*10+number[++idx]-'0'; 
    } 
    if (ans.length()==0) 
        return "0"; 
    return ans; 
} 


int main(){
	cin>>a>>b;
	
	string res="";
	if (string_to_num(a[a.size()-1])%2!=0) res=sum(res,b);
	while (a!="1"){
		a=chia(2,a);
		b=nhan_nho('2',b);
		if (string_to_num(a[a.size()-1])%2!=0) {
		res=sum(res,b);
		cout<<a<<" 		"<<b<<"		"<<res<<endl;}
	}
	return 0;
}
