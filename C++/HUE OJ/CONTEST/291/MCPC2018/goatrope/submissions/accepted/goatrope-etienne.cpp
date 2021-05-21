#include <iostream>
#include <cmath>
#include <iomanip>

double dist(double x1, double y1, double x2, double y2)
{
    return std::sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}

int main()
{
    int x,y,x1,y1,x2,y2;
    std::cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    double mindist = dist(x, y, x1, y1);
    mindist = std::min(mindist, dist(x, y, x2, y1));
    mindist = std::min(mindist, dist(x, y, x1, y2));
    mindist = std::min(mindist, dist(x, y, x2, y2));
    if(x1 <= x && x <= x2)
    {
        mindist = std::min(mindist, fabs(y-y1));
        mindist = std::min(mindist, fabs(y-y2));
    }
    if(y1 <= y && y <= y2)
    {
        mindist = std::min(mindist, fabs(x-x1));
        mindist = std::min(mindist, fabs(x-x2));
    }
    std::cout << std::setprecision(30) << mindist << std::endl;
}
