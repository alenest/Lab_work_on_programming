#pragma once


#include <iostream>
#include <cmath>
#include <windows.h>
#include <stdio.h>
#include <conio.h>

double f1(double x);

double f2(double x);

double BisectionMethod(double(*f)(double), double A, double B, double CalcError, int &iterations);

double SimpleIterationMethod(double(*f)(double), double A, double B, double CalcError, int& iterations);


