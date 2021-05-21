#include<iostream>
using namespace std;
int allocMatrix(int **A,int m, int n)
{
	*A=new int[m*n];
	if(*A==NULL) return 0;
	return 1;
}

int main()
{
	int m,n;
	int *A, *B, *C;
	cout<<"Nhap so dong cua ma tran: ";
	cin>>m;
	cout<<"Nhap so cot cua ma tran: ";
	cin>>n;
	allocMatrix(&A,m,n);
	cout<<"Nhap cac phan tu cua ma tran: ";
	for(int i=0;i<m*n;i++) cin>>A[i];
	cout<<endl;
	for(int i=0;i<m*n;i++) cout<<A[i]<<" ";
}
