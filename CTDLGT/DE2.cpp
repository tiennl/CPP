#include <iostream>
#include <math.h>
#include <cstdlib>
int a[99];
using namespace std;
bool isSquare(int x){
	int k=sqrt(x);
	if (k*k==x) return true;
	else return false;
}
void RandomNum(int n,int a[]){
	for (int i=0;i<n;i++)
		a[i]=rand()%2019+0;
}
void InsertionSort (int n,int a[]){
 	int t,j;
 	for	(int i=1;i<n;i++){
  		j=i-1;
  		t=a[i];
  		while(j>=0&&t>a[j]){
   			a[j+1]=a[j];
   			j--;
  		}
  		a[j+1]=t;
 	}
}
void DeleteSquare(int &n, int a[]){
	int i=0;
	while (i<n){
		if (!isSquare(a[i])) i++;
		else{
			for (int j=i;j<n-1;j++) a[j]=a[j+1];
			n--;
		}
	}
}
int main(){
	int n=99;
	RandomNum(n,a);
	InsertionSort(n,a);
	DeleteSquare(n,a);
	for (int i=0;i<n;i++) cout<<a[i]<<" ";cout<<endl;
	return 0;
}
