#include <bits/stdc++.h>
using namespace std;

int main(void) {
	vector<string> s;
	while (!cin.eof()) {
		string s0; cin >> s0;
		s.push_back(s0);
	}
	s.pop_back();
	//for (int i = 0; i < s.size(); i++) cout << s[i] << endl;

	for (int i = 0; i < s.size(); i++) {
		//if (s[i].length() <= 1) continue;

		string t = "";
		for (int j = 0; j < s[i].length()-1; j++) {
			t += s[i][j]; string u = "";
			for (int k = j+1; k < s[i].length(); k++) u += s[i][k];
			//cout << t << " " << u << "." << endl;

			bool b1 = binary_search(s.begin(), s.end(), t);
			bool b2 = binary_search(s.begin(), s.end(), u);
			//cout << b1 << " " << b2 << endl;
			if (b1 && b2) { cout << s[i] << endl; break; }
		}
	}

	return 0;
}
