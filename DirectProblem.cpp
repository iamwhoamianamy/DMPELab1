#include <fstream>
#include "DirectProblem.h"

DirectProblem::DirectProblem(string fileName)
{
   ifstream fin(fileName, ios_base::in);

   string _;
   fin >> _;

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

void DirectProblem::GenerateData()
{
   double factor = I / (2 * M_PI * sigma);

   for (size_t i = 0; i < sources_count; i++)
   {
      for (size_t j = 0; j < recievers_count; j++)
      {
         double r_AM = Point::Distance(A[i], M[j]);
         double r_BM = Point::Distance(B[i], M[j]);

         double r_AN = Point::Distance(A[i], N[j]);
         double r_BN = Point::Distance(B[i], N[j]);

         V[i][j] = factor * (
            1.0 / r_BM - 
            1.0 / r_AM - 
            1.0 / r_BN + 
            1.0 / r_AN);
      }
   }
}
