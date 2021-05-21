#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	vector<int> ord(N);
	for (int i=0;i<N;i++) ord.push_back(i);
	sort(ord.begin(), ord.end(), [&](int i, int j) -> bool {
		return A[i] < A[j];
	});
	vector<int> inv(N);
	for (int i = 0; i < N; i++) {
		inv[ord[i]] = i;
	}

	for (int i = 0; i < N; i++) {
		if (inv[i] < N/2) {
			cout << A[ord[N/2]] << '\n';
		} else {
			cout << A[ord[N/2-1]] << '\n';
		}
	}

	return 0;
}

