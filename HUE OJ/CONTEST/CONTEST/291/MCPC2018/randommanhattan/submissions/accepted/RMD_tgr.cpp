/*

Within a zone:  Z = (l^2+3lr+r^2)w^3/15

Cx(i) = x0 + (l+2r)/(3(l+r))w

*/
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <math.h>
#include <tuple>
using namespace std ;
using ll = long long ;
using t3 = tuple<double, double, double> ;
int main() {
   cout << setprecision(15) ;
   int N{0} ;
   cin >> N ;
   vector<ll> xs(N), ys(N) ;
   for (int i=0; i<N; i++)
      cin >> xs[i] >> ys[i] ;
   double r {} ;
   for (int outer=0; outer<2; outer++) {
      int hix0 = min_element(xs.begin(), xs.end()) - xs.begin() ;
      int lox0 { hix0 } ;
      auto ht=[&](ll x, int p0, int p1) -> double {
         if (x == xs[p0])
            return ys[p0] ;
         if (x == xs[p1])
            return ys[p1] ;
         return ys[p0]+(x-xs[p0])*(ys[p1]-ys[p0])/(double)(xs[p1]-xs[p0]) ;
      } ;
      vector<t3> zones ;
      while (1) {
         int hix1 { (hix0 + 1) % N } ;
         int lox1 { (lox0 + N - 1) % N } ;
         ll x0 = max(xs[hix0], xs[lox0]) ;
         if (x0 == xs[hix1]) {
            hix0 = hix1 ;
            continue ;
         }
         if (x0 == xs[lox1]) {
            lox0 = lox1 ;
            continue ;
         }
         ll x1 { min(xs[hix1], xs[lox1]) } ;
         if (x1 < x0)
            break ;
         if (x1 == x0)
            throw "Failed while building zones" ;
         double lft { ht(x0, hix0, hix1) - ht(x0, lox0, lox1) } ;
         double rgt { ht(x1, hix0, hix1) - ht(x1, lox0, lox1) } ;
         zones.push_back(make_tuple(lft, rgt, (double)(x1-x0))) ;
//  cout << "Adding tuple xs " << x0 << " " << x1 << " heights " << lft << " " << rgt << endl ;
         if (x1 == xs[hix1])
            hix0 = hix1 ;
         if (x1 == xs[lox1])
            lox0 = lox1 ;
      }
      double s {} ;
      double cxa {} ;
      double sa {} ;
      double a2 {} ;
      double x0 {} ;
      for (int i=0; i<zones.size(); i++) {
         t3 &z = zones[i] ;
         double lft { get<0>(z) }, rgt { get<1>(z) }, w { get<2>(z) } ;
         s += (lft*lft+3*lft*rgt+rgt*rgt)*w*w*w/15 ;
         double ta { (lft+rgt)*w/2 } ;
         double cx { x0 + (lft+2*rgt)/(3*(lft+rgt))*w } ;
         if (i)
            s += 2 * (cx - cxa / sa) * sa * ta ;
         a2 += ta*(2*sa+ta) ;
         sa += ta ;
         cxa += cx * ta ;
         x0 += w ;
      }
      r += s / a2 ;
      swap(xs, ys) ;
      reverse(xs.begin(), xs.end()) ;
      reverse(ys.begin(), ys.end()) ;
   }
   cout << r << endl ;
}
