#pragma once
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class LinearRegressionModel
{
private:

    double Theta0;
    double Theta1;

    vector<double> CalcH(const vector<double>& X)
    {
        vector<double> H;

        for (double x : X)
            H.push_back(Theta0 + Theta1 * x);

        return H;
    }

    double CalcCost(const vector<double>& H,
        const vector<double>& Y)
    {
        double Cost = 0;

        for (size_t i = 0; i < H.size(); i++)
        {
            double Error = H[i] - Y[i];
            Cost += Error * Error;
        }

        return Cost / (2.0 * H.size());
    }

public:

    LinearRegressionModel(double theta0 = 0,
        double theta1 = 0)
    {
        Theta0 = theta0;
        Theta1 = theta1;
    }

    void Fit(const vector<double>& X,
        const vector<double>& Y,
        double alpha = 0.01,
        int maxIteration = 10000)
    {
        const double EPS = 1e-9;

        double OldCost = 1e18;

        for (int iteration = 1; iteration <= maxIteration; iteration++)
        {
            vector<double> H = CalcH(X);

            double Cost = CalcCost(H, Y);

            if (iteration % 100 == 0)
            {
                cout << "Iteration : " << iteration << endl;
                cout << "Theta0 = " << Theta0 << endl;
                cout << "Theta1 = " << Theta1 << endl;
                cout << "Cost = " << Cost << endl;
                cout << "----------------------" << endl;
            }

            if (fabs(OldCost - Cost) < EPS)
                break;

            OldCost = Cost;

            double Sum0 = 0;
            double Sum1 = 0;

            for (size_t i = 0; i < X.size(); i++)
            {
                double Error = H[i] - Y[i];

                Sum0 += Error;
                Sum1 += Error * X[i];
            }

            Theta0 -= alpha * Sum0 / X.size();
            Theta1 -= alpha * Sum1 / X.size();
        }
    }

    double Predict(double X) const
    {
        return Theta0 + Theta1 * X;
    }

    vector<double> Predict(const vector<double>& X) const
    {
        vector<double> Result;

        for (double x : X)
            Result.push_back(Theta0 + Theta1 * x);

        return Result;
    }
    void PrintPrediction(const vector<double>& Prediction)
    {
        cout << "{ ";

        for (double value : Prediction)
            cout << value << " ";

        cout << "}" << endl;
    }

    double CalcMSE(const vector<double>& X,
        const vector<double>& Y) const
    {
        vector<double> Prediction = Predict(X);

        double Sum = 0;

        for (size_t i = 0; i < Prediction.size(); i++)
        {
            double Error = Prediction[i] - Y[i];
            Sum += Error * Error;
        }

        return Sum / Prediction.size();
    }

    double GetTheta0() const
    {
        return Theta0;
    }

    double GetTheta1() const
    {
        return Theta1;
    }
};