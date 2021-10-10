#include "InverseProblem.hpp"
#include <limits.h>

const double APPROX = 1, EPSILON = 1e-10;

InverseProblem::InverseProblem(const DirectProblem& dp)
{
   A = dp.A;
   B = dp.B;
   M = dp.M;
   N = dp.N;
   V = dp.V;

   sigma = dp.sigma;

   sources_count = dp.sources_count;
   recievers_count = dp.recievers_count;

   I.resize(dp.sources_count, APPROX);
}

void InverseProblem::GenerateV(vector<double> I)
{
    for (size_t i = 0; i < sources_count; i++)
    {
        double factor = I[i] / (2 * M_PI * sigma);
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

void InverseProblem::SolveProblem()
{
    double normF = DBL_MAX, normPrevF;
    vector<vector<double>> 
        w(sources_count, vector<double>(recievers_count)),
        dV(sources_count, vector<double>(recievers_count)),
        constV = V;
    vector<double> 
        a(sources_count), 
        b(sources_count),
        F(sources_count);

    GenerateV({ 1, 1, 1 });
    dV = V;

    for (size_t i = 0; i < sources_count; i++)
        for (size_t j = 0; j < recievers_count; j++)
            w[i][j] = 1 / constV[i][j];

    GenerateV(I);
    do
    {
        normPrevF = normF;
        for (size_t i = 0; i < sources_count; i++)
            for (size_t j = 0; j < recievers_count; j++)
            {
                a[i] += pow(w[i][j] * dV[i][j], 2);
                b[i] -= w[i][j] * w[i][j] * dV[i][j] * (V[i][j] - constV[i][j]);
            }

        for (size_t i = 0; i < sources_count; i++)
            I[i] += b[i] / a[i];

        GenerateV(I);

        for (size_t i = 0; i < sources_count; i++)
            for (size_t j = 0; j < recievers_count; j++)
            F[i] += pow((w[i][j] * (V[i][j] - constV[i][j])), 2);

        for (size_t i = 0; i < sources_count; i++)
            normF += F[i] * F[i];
        
    } while (normPrevF - normF > EPSILON);
}

void InverseProblem::Output()
{
    cout << endl;
    cout << "InverseProblem" << endl;
    cout << "Source[N]" << setw(20) << "Electric current" << endl;
    cout << scientific;
    for (size_t i = 0; i < sources_count; i++)
        cout << "Source[" << i << "]" << setw(20) << I[i] << endl;
}
