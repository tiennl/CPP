// Liet ke hoan vi cua n 
#include <iostream>
using namespace std;
int n, x[20];
bool b[20];
void Init(){
	cout<<"Nhap n: ";
	cin>>n;
	for (int i=1;i<=n;i++) b[i]=true;
}
void Print(){
	for (int i=1;i<=n;i++) cout<<x[i]<<" ";
	cout<<endl;
}
void Try(int i){
	int j;
	for (int j=1;j<=n;j++)
		if (b[j]){
			x[i]=j;
			b[j]=false;
			if (i==n) Print();
			else Try(i+1);
			b[j]=true;
		}
}
int main(){
	Init();
	Try(1);
	return 0;
}
