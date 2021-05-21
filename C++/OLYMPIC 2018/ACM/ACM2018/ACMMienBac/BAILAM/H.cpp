#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Autocomplete{
	char prefix;
	string s;

};


vector<string> originalArr;
vector<Autocomplete> autocompleteArr;

Autocomplete autocomplete;


bool isUniqueAutocomplete(string s){

	for (int i = 0; i < autocompleteArr.size(); ++i){
		if(autocompleteArr[i].s == s){
			return false;
		}
	}
	return true;
}


bool sortNextCharAsc(string a, string b){
	char c1 = 0;
	char c2 = 0;

	if(a.size() > 2){
		c1 = a[1];
	}
	if(b.size() > 2){
		c2  = b[1];
	}

	return c1 < c2;
}

int findAutocompleteIndex(string s){

	vector<string> v;

	for (int i = 0; i < autocompleteArr.size(); ++i){
		if(autocompleteArr[i].prefix == s[0]){
			// tim cac chuoi trong autocomplete ky tu dau tien giong typing...
			v.push_back(autocompleteArr[i].s);
		}
	}
	// sort array tang dan theo chu cai thu 2
	sort(v.begin(), v.end(), sortNextCharAsc);

	for (int i = 0; i < v.size(); ++i){
		if(v[i] == s){
			return i;
		}
	}

	return -1;
}

void addAutocomplete(string s){
	char c = s[0];
	if(isUniqueAutocomplete(s)){
		autocomplete.prefix = c;
		autocomplete.s = s;
		autocompleteArr.push_back(autocomplete);
	}
	
}

int main(){
	int n;
	string s;

	cin >> n;

	long long totalTime = 0;

	// input data
	for (int i = 0; i < n; ++i){
		cin >> s;
		int completeIndex = findAutocompleteIndex(s);
		if(completeIndex == -1){
			// khong co sugesstion nao, vay phai go tat ca
			totalTime += s.size();
		}else{
			// ton tai sugesstion ta xem no vi tri bao nhieu
			totalTime += (completeIndex +1);
			totalTime ++; // vi phai enter 1 lan
		}

		originalArr.push_back(s);
		// add autocomplete to list
		addAutocomplete(s);
	}

	cout << totalTime;


	return 0;
}