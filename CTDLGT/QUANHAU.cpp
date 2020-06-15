#include <iostream>
using namespace std;
bool a[100],b[100],c[100];
int n=8;
int x[100];
void inres(int j,int n){
	for (int i=1;i<=n;i++)
		cout<<"("<<i<<","<<x[i]<<")";
	cout<<endl;
}
void Try(int j, int n){
	for (int i=1;i<=n;i++)
		if (a[i] && b[i+j] && c[i-j]){
			x[j]=i;
			a[i]=0;
			b[i+1]=0;
			c[i-j]=0;
			if (j==8) inres(j,n);
			else Try(j+1,n);
			a[i]=1;
			b[i+j]=1;
			c[i-j]=1;
		}
}
int main(){
	Try(1,8);
	return 0;
}
