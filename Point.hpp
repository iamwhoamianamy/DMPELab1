#pragma once
class Point
{
public:
   double x, y, z;

   Point();
   Point(double x, double y, double z);
   static double Distance(Point a, Point b);
};

