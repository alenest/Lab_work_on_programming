#pragma once
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <cmath>

void ChooseYourTest(int ParamNumber, char* Param[], int** &matrix, int &i, int& MaxValue);

bool CheckTask(int **matrix, int i, int MaxValue);

void DiagonalAssignment(int** matrix, int i, int* &array);

void ArrayOutput(char* Param[], int i, int* array);

//void Output();