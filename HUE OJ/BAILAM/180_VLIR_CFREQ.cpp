#include <bits/stdc++.h>
long long a[10000];
using namespace std;
int main(){
	char s;
	for (int i=48;i<=122;i++) a[i]=0;
	while (cin>>s){
		if ((s>='0' && s<='9') || (s>='A' && s<='Z') || (s>='a' && s<='z'))
			a[(int)s]++;
	}
	for (int i=48;i<=122;i++)
		if (a[i]>0){
			cout<<(char)i;
			if (a[i]<10) cout<<"   "<<a[i]<<endl;
			else if (a[i]<100) cout<<"  "<<a[i]<<endl;
			else cout<<" "<<a[i]<<endl;
		}
	return 0;
}
