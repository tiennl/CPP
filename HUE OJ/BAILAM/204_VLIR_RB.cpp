#include <bits/stdc++.h>
using namespace std;
long long stol(string x){
	long long c=0;
	stringstream str2num(x);
				str2num>>c;
	return c;
}
bool ktra_do_uong(string s){
	if (s=="ABSINTH"||s=="BEER"||s=="BRANDY"||s=="CHAMPAGNE"||s=="GIN"||s=="RUM"||s=="SAKE"
	||s=="TEQUILA"||s=="VODKA"||s=="WHISKEY"||s=="WINE"
	  ||s=="Absinth"||s=="Beer"||s=="Brandy"||s=="Champagne"||s=="Gin"||s=="Rum"||s=="Sake"
	||s=="Tequila"||s=="Vodka"||s=="Whiskey"||s=="Wine")
	return true;
	return false;
}
int main(){
	long long n,res=0,age=0;
	string s;
	cin>>n;
	while (n--){
		cin>>s;
		if ((s[0]>='a' && s[0]<='z') || (s[0]>='A' && s[0]<='Z')){
			if (ktra_do_uong(s)) res++;
		}
		else{
			age=stol(s);
			if (age!=16 && age<18) res++;
		}
	}
	cout<<res;
	return 0;
}
