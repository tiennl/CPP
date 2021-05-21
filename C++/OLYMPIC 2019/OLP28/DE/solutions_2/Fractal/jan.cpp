/*
  [NWERC'09] FRACTAL
  by: Jan Kuipers
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <complex>

using namespace std;

const double eps = 1e-10;

int main () {

  int runs;
  cin>>runs;

  while (runs--) {

    int N,D;
    double f;
    
    cin>>N;
    vector<complex<double> > x(N),dx(N-1);
    for (int i=0; i<N; i++) {
      cin>>x[i].real()>>x[i].imag();
      if (i) dx[i-1]=x[i]-x[i-1];
    }
    cin>>D>>f;

    double L=0;
    for (int i=0; i<N-1; i++) L+=abs(dx[i]);

    double s = L / abs(x[N-1]-x[0]);
    double dist = f * L;

    complex<double> X=x[0], b=1;
 
    for (int d=0; d<D; d++) {
      int i=0;
      while (i<N-1 && abs(b*dx[i])<dist*(1-eps)) {
	dist -= abs(b*dx[i]);
	X += b*dx[i];
	i++;
      }

      if (d==D-1) X += dist * b*dx[i]/abs(b*dx[i]);
      b *= dx[i]/(x[N-1]-x[0]);
      dist *= s;
    }

    cout<<setprecision(10)<<X<<endl;
  }
	    
  return 0;
}
