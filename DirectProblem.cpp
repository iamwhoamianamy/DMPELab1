#include <fstream>
#include "DirectProblem.h"

DirectProblem::DirectProblem(string fileName)
{
   ifstream fin(fileName, ios_base::in);

   string _;
   fin >> _;

   int sources_count;
   fin >> sources_count;

   A.resize(sources_count);
   B.resize(sources_count);

   for (size_t i = 0; i < sources_count; i++)
   {
      double x, y, z;

      fin >> x >> y >> z;
      A[i] = Point(x, y, z);

      fin >> x >> y >> z;
      B[i] = Point(x, y, z);
   }

   fin >> _;

   int recievers_count;
   fin >> recievers_count;

   M.resize(recievers_count);
   N.resize(recievers_count);

   for (size_t i = 0; i < recievers_count; i++)
   {
      double x, y, z;

      fin >> x >> y >> z;
      M[i] = Point(x, y, z);

      fin >> x >> y >> z;
      N[i] = Point(x, y, z);
   }

   fin >> _ >> sigma >> I;

   fin.close();

   V = vector<vector<double>>(sources_count, 
                              vector<double>(recievers_count));
}
