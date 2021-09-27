#include <iostream>
#include "DirectProblem.h"

int main()
{
   DirectProblem dp("sources_recievers.txt");
   dp.GenerateData();

   for (size_t i = 0; i < dp.sources_count; i++)
   {
      for (size_t j = 0; j < dp.recievers_count; j++)
      {
         cout << dp.V[i][j] << " ";
      }

      cout << endl;
   }
}