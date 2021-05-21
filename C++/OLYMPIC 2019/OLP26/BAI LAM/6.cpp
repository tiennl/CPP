#include <iostream>
using namespace std;
int *A;
int max(int *B, int j) {
	int i, max1 = B[0];
	for (i = 0; i < j; i++)
		if (B[i] > max1)
			max1 = B[i];
	return max1;
		
}

int main() {
	int i, n;
	
	cout << "Nhap so phan tu cua mang : ";
	cin >> n;
    A = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "A[" << i << "] = ";
		cin >> A[i];
	}

	int lonnhat;
	lonnhat = max(A, n);
	cout << "max = " << lonnhat << endl;
        delete A;
	return 0;
}
