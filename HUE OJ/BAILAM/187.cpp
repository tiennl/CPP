#include <bits/stdc++.h>
long long a[10000000];
using namespace std;
int main(){
	long long n,x,p,sum=0;
	char s;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	while (cin>>s){
		if (s=='i'){
			cin>>x;
			n++;
			a[n]=x;
			sum+=x;
		}
		else if (s=='d'){
			cin>>p;
			if (p>=1 && p<=n){
				sum-=a[p];
				for (int i=p;i<n;i++) a[i]=a[i+1];
				n--;
			}
		}
		else if (s=='s'){
			cout<<sum<<endl;
			
		}
		else if (s=='0'){
			cin>>x;
			break;
		}
	}
	return 0;
}
