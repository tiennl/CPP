#include <bits/stdc++.h>
unsigned long long a[100000000];
using namespace std;
long long stol(string x){
	long long c=0;
	stringstream str2num(x);
				str2num>>c;
	return c;
}
int main(){
	long long n,k=-1;
	string s,num="";
	cin>>n;
	while (n--){
		cin>>s;
		s+=" ";
		num="";
		for (int i=0;i<=s.size();i++)
			if (s[i]>='0' && s[i]<='9'){
				num+=s[i];
				if (!(s[i+1]>='0' && s[i+1]<='9') || s[i+1]==' '){
					k++;
					a[k]=stol(num);
					num="";
				} 
			}
	}
	k++;
	sort(a,a+k);
	for (int i=0;i<k;i++) cout<<a[i]<<endl;
	return 0;
}
