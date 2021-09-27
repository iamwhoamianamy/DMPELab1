#include "Point.h"
#include <math.h>

Point::Point() : x(0.0), y(0.0), z(0.0)
{
}

Point::Point(double x, double y, double z) : x(x), y(y), z(z)
{
}

double Point::Distance(Point a, Point b)
{
   return sqrt((a.x - b.x) * (a.x - b.x) + 
               (a.y - b.y) * (a.y - b.y) + 
               (a.z - b.z) * (a.z - b.z));
}
