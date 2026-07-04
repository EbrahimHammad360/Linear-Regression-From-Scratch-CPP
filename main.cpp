

#include <iostream>
#include "LinearRegressionModel.h";
using namespace std;


int main()
{
    vector<double> Xtrain =
    {
        1,2,3,4,5,6,7,8,9,10
    };

    vector<double> Ytrain =
    {
        5,8,11,14,17,20,23,26,29,32
    };

    LinearRegressionModel Model;

    Model.Fit(Xtrain, Ytrain);

    cout << endl;

    cout << "Theta0 = " << Model.GetTheta0() << endl;
    cout << "Theta1 = " << Model.GetTheta1() << endl;
    cout << endl;

    vector<double> Xpredict = {11,12,13,14,15,16,17,18,19,20};
    vector<double> YActual =
    {
        35,
        38,
        41,
        44,
        47,
        50,
        53,
        56,
        59,
        62
    };

    cout << "Predict 20 = "
        << Model.Predict(20)
        << endl;
    cout << endl;

    vector<double>Vpred =  Model.Predict(Xpredict);
    Model.PrintPrediction(Vpred);
    cout << endl;

    cout << "MSE = "
        << Model.CalcMSE(Xpredict, YActual)
        << endl;
}











