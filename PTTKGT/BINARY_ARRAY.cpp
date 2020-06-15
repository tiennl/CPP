//Liet ke day nhi phan co do dai n
#include <iostream>
using namespace std;
int n,x[20];
void Print(){
	for (int i=1;i<=n;i++) cout<<x[i];
	cout<<endl;
}
void Try(int k){
	for (int j=0;j<=1;j++){
		x[k]=j;
		if (k==n) Print();
		else Try(k+1);
	}
}
int main(){
	cin>>n;
	Try(1);
	return 0;
}
