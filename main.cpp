#include <iostream>
#include <iomanip>
#include "DirectProblem.hpp"
#include "InverseProblem.hpp"

int main()
{
   DirectProblem dp("sources_recievers.txt");
   dp.GenerateData();
   dp.Output();
   InverseProblem ip(dp);
   ip.SolveProblem();
   ip.Output();
}