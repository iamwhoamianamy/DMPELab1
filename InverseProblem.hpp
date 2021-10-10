#pragma once
#include "DirectProblem.hpp"

class InverseProblem
{
public:
   vector<Point> A, B, M, N;
   double sigma;
   vector<double> I;
   vector<vector<double>> V;
   int sources_count;
   int recievers_count;

   InverseProblem(const DirectProblem& dp);
   void GenerateV(vector<double> I);
   void SolveProblem();
   void Output();
};

