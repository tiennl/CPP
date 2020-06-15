#include <iostream>
#include <math.h>
#include <cstdlib>
int a[100];
using namespace std;
bool isPrime(int x){
	if (x<2) return false;
	for (int i=2;i<=sqrt(x);i++)
		if (x%i==0) return false;
	return true;
}
void RandomNum(int n,int a[]){
	for (int i=0;i<n;i++)
		a[i]=rand()%2018+0;
}
void SelectionSort(int n, int a[]){
	for (int i=0;i<n-1;i++){
		int max=a[i];
		int maxpos=i;
		for (int j=i+1;j<n;j++)
			if (a[j]>max){
				max=a[j];
				maxpos=j;
			}
		swap(a[i],a[maxpos]);
	}
}
void DeletePrime(int &n, int a[]){
	int i=0;
	while (i<n){
		if (!isPrime(a[i])) i++;
		else{
			for (int j=i;j<n-1;j++) a[j]=a[j+1];
			n--;
		}
	}
}
int main(){
	int n=100;
	RandomNum(n,a);
	SelectionSort(n,a);
	DeletePrime(n,a);
	for (int i=0;i<n;i++) cout<<a[i]<<" ";
	return 0;
}
