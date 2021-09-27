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

   DirectProblem(string fileName);
   void GenerateData()
   {

   }
};

