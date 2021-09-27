#include "InverseProblem.h"

InverseProblem::InverseProblem(const DirectProblem& dp)
{
   A = dp.A;
   B = dp.B;
   M = dp.M;
   N = dp.N;
   V = dp.V;

   sigma = dp.sigma;
   I = 0;

   sources_count = dp.sources_count;
   recievers_count = dp.recievers_count;
}
