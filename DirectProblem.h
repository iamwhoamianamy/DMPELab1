#pragma once
#include <vector>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Point.h"

using namespace std;

class DirectProblem
{
public:
   vector<Point> A, B, M, N;
   double sigma;
   double I;
   vector<vector<double>> V;
   int sources_count;
   int recievers_count;

   DirectProblem(string fileName);
   void GenerateData();
};

