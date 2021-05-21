#include <cstdlib>
#include <iostream>
#include <cmath>
#define EPS 1e-10
#define N 2002
using namespace std;
 
//bzw. mit double-Koordinaten
struct Point { double x, y; int i; double angle;};

Point pts[N];    //gegebene Punkte

int cmp(const void *a, const void *b) {
    Point p1 = *((Point *) a);
    Point p2 = *((Point *) b);
    //cout << " compare " << p1.i << " " << p2.i << ": ";
    if(p1.angle - p2.angle > EPS){
	 //   cout << "1" << endl;
	    return 1;
    }
    if(p1.angle - p2.angle < -EPS) {
	  //  cout << "-1" << endl;
	    return -1;
    }
    //cout << "0" << endl;
    return 0;
}
 
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int num;
		Point center;
		center.x = 0;
		center.y = 0;
		cin >> num;
		for(int i = 0; i< num; i++){
			cin >> pts[i].x >> pts[i].y;
			pts[i].i = i;

			center.x += pts[i].x / (double)num;
			center.y += pts[i].y / (double)num;
		}
		/*
		cout << center.x << endl;
		cout << center.y << endl;
		*/
		for(int i = 0; i< num; i++){
			pts[i].angle = atan2(pts[i].y - center.y, pts[i].x - center.x);
			//cout << "angle pts " << pts[i].i << " is " << pts[i].angle << endl;
		}
		qsort(pts, num, sizeof(Point), cmp);
		for(int i = 0; i< num; i++){
			//cout << "angle pts " << pts[i].i << " is " << pts[i].angle << endl;
		}
		for(int i = 0; i < num - 1; i++) {
			cout << pts[i].i <<  " " ;
		}
		cout << pts[num - 1].i;
		cout << endl;
	}
}
