#include<iostream>

using namespace std;

int x[11];
void printArray(int a[], int n){
	for (int i = 1; i <= n; i++){
		cout << a[i];
	}
	cout <<" ";
}
void dequy(int h, int k, int n){
	for (int i = x[h-1] + 1; i <= n - (k-h); i++){
		x[h] = i;
		if (h == k) printArray(x, k);
		else {
			dequy(h+1, k, n);
		}
	}
}
int main(){
	int n, k;
	cin >> n >> k;
	x[0] = 0;
	dequy(1, k, n);
}
