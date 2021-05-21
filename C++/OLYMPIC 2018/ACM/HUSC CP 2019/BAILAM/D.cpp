#include <bits/stdc++.h>
#include <string>
using namespace std;
int a[1000],kt[1000][1000],so[1000],so2[1000];
int string_to_num(char c){
	return c-'0';
}
char num_to_string(int n){
	return (char)(n+48);
}
string sum(string a, string b){    
	string s="";
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
	int n,k=0,d=0;
	string s1="",s2="",res="";
	cin>>n;
	n*=2;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	k=0;d=0;
	for (int i=1;i<=n-1;i+=2){
		kt[a[i]][a[i+1]]++;
		kt[a[i+1]][a[i]]++;
		if (a[i]>0 && a[i+1]>0)
			if (a[i]>a[i+1]){
				k++;
				so[k]=a[i];
			}
			else{
				k++;
				so[k]=a[i+1];
			}
		else{
			if (a[i]>a[i+1]){
				d++;
				so2[d]=a[i];
			}
			else{
				d++;
				so2[d]=a[i+1];
			}
		}
	}
	sort(so+1,so+k+1);
	sort(so2+1,so2+d+1);
	for (int i=k;i>=1;i--){
		s1+=(char)(so[i]+48);
		for (int j=9;j>=0;j--)
			if (kt[so[i]][j]>0 || kt[j][so[i]]>0){
				s2+=(char)(j+48);
				kt[so[i]][j]--;
				kt[j][so[i]]--;
				break;
			}
			
	}
	for (int i=d;i>=1;i--){
		s1+=(char)(so2[i]+48);
		for (int j=9;j>=0;j--)
			if (kt[so2[i]][j]>0 || kt[j][so2[i]]>0){
				s2+=(char)(j+48);
				kt[so2[i]][j]--;
				kt[j][so2[i]]--;
				break;
			}
			
	}
//	cout<<s1<<endl<<s2<<endl;
	cout<<sum(s1,s2);
	return 0;
}

