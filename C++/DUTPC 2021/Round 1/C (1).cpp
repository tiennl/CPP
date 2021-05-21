#include<bits/stdc++.h>
using namespace std;



struct SinhVien {
	string hoTen;
	string maHP;
	
	void nhap() {
		string s;
		getline(cin, s);
		hoTen = s.substr(0, s.find_last_of(' '));
		maHP = s.substr(s.find_last_of(' ') + 1);
	}
};

vector<SinhVien> vectorSV;

bool sortMH(SinhVien a, SinhVien b) {
	if(a.maHP == b.maHP) {
		return a.hoTen < b.hoTen;
	}
	return a.maHP < b.maHP;
}

int main() {
	long long n;
	cin >> n;
//	fflush(stdin);
	for(int i = 0; i < n; i++) {
		SinhVien sv;
		sv.nhap();
		vectorSV.push_back(sv);
		sort(vectorSV.begin(), vectorSV.end(), sortMH);
	}
	SinhVien s;
	vectorSV.push_back(s);
	string maHP = vectorSV[0].maHP;
//	cout<<maHP<<endl;
//	long long soluong = 1;
//	for(int i = 1; i < n; i++) {
//		if(vectorSV[i].maHP != maHP) {
//			cout << maHP << " " << soluong;
//			if(soluong >= 10) {
//				cout << " YES" << endl;
//			} else {
//				cout << " NO" << endl;
//			}
//			maHP = vectorSV[i].maHP;
//			soluong = 1;
//		} else {
//			if(vectorSV[i].hoTen != vectorSV[i-1].hoTen) {
//				soluong++;
//			}
//		}
//	}
//	cout << maHP << " " << soluong;
//	if(soluong >= 10) {
//		cout << " YES";
//	} else {
//		cout << " NO" ;
//	}
	return 0;
}

/*
13
NGO NGA TRR
NGUYEN MAI CTDL
NGUYEN TY CTDL
NGUYEN NGAN CTDL
NGO MAI CTDL
LE MAI CTDL
DINH MAI CTDL
PHAN MAI TTT
LE HOA TTT
NGUYEN THINH TTT
NGUYEN CAO TTT
DINH MAI TTT
DINH DAO TTT
*/
