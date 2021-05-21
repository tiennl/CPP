#include <iostream>
#include <fstream>

using namespace std;

const int N = 1e6 + 10;
int coord[3][N], n;


long long f(int dest[] ) {
    long long sumDist = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j)  {
            // From base to dragon balls
            sumDist += abs(coord[j][i] - coord[j][0]);
            // From dragon ball to destination
            sumDist += abs(coord[j][i] - dest[j]);
        }
    }
    return sumDist;
}

int main(int argc, char * argv[]) {
    ifstream correct_in(argv[1]);
    ifstream correct_out(argv[2]);
    ifstream contestant_out(argv[3]);
    
    correct_in >> n;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) correct_in >> coord[j][i];
    }
    long long correct_SumDist;
    correct_out >> correct_SumDist;
    long long contestant_SumDist;
    contestant_out >> contestant_SumDist;
    int contestant_dest[3];
    for (int i = 0; i < 3; ++i) contestant_out >> contestant_dest[i];
    if (correct_SumDist != contestant_SumDist || f(contestant_dest) != correct_SumDist) {
        cout << 0;
        return 0;
    }
    cout << 1;
}