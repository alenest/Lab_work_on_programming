#include "modul8.h"
const double pi = 3.1415926535;
const double EULER = 2.71828182845904523536;

double f1(double x)
{

    //double y = 6 / 7;
    //printf("\n%.5lf\n", y);
    //y = 
    //return log1p(x) - 0.95 * sin(x * pi/180 ) + (6.0 / 7.0) - x;
    return log1p(x) - 0.95 * sin(x) + (6.0 / 7.0) - x;
    //return 0.0;
}

double f2(double x)
{
    return 1/(pow(EULER,pow(x, 0.2)) - sqrt(x) + log1p(x) + (4.0/9.0)) - x;
}



double BisectionMethod(double(*f)(double), double A, double B, double CalcError, int&iterations)
{
    //bool AllowableError = false;
    double midpoint;
    iterations = 0;
    while(iterations < 1000)
    {
        midpoint = (A + B) / 2;
        if (f(midpoint) * f(B) < 0) A = midpoint;
        else B = midpoint; iterations++;
        if (abs(B - A) < CalcError) return midpoint;
        //midpoint = (A + B) / 2;
        
    }
    return midpoint;
}

double g(double x, double c, double(*f)(double))
{
    return x + c * f(x);
}

//bool CheckCoef(double(*f)(double)), double c,  double A, double B, double CalcError)
//{
//    for (int x = A; x <= B; x += CalcError)
//    {
//        if ((x + c * f(x)) >= 0.5) return false;
//    }
//    return true;
//}

double SimpleIterationMethod(double(*f)(double), double A, double B, double CalcError, int& iterations)
{
    double c = 0.75;
    double x1 = (A + B) / 2;
    double x2;
    iterations = 0;
    while(iterations < 1000)
    {
        x2 = x1 + c * f(x1);
        iterations++;
        if (abs(x2 - x1) < CalcError) return x2;
        x1 = x2;  
        
    }
    return x1;
}


