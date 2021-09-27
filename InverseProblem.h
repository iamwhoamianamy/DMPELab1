#pragma once
#include "DirectProblem.h"

class InverseProblem
{
public:
   vector<Point> A, B, M, N;
   double sigma;
   double I;
   vector<vector<double>> V;
   int sources_count;
   int recievers_count;

   InverseProblem(const DirectProblem& dp);
};

