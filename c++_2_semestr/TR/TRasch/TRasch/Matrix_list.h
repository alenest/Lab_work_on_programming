#pragma once

#include <iostream>
#include <windows.h> // SetConsoleOutputCP, SetConsoleCP
#include <stdio.h> //printf , fgets
#include <conio.h> // getch
#include <string.h> // strcpy, strncmp, strchr

struct TMatrixElem
{
	int ElemValue;
	TMatrixElem* NextLineElem;
	TMatrixElem* NextColumnElem;
};

struct TMatrix
{
	//MatrixElem* CurrentElem;
	TMatrixElem* HeadElem;
	TMatrixElem* CurrentPosition;
};

bool MatrixIsEmpty(TMatrix* PMatrix);

TMatrix MatrixMemoryAllocation(int N, int M);

bool GoTo_i_Line(TMatrix* PMatrix, int i);

bool GoTo_j_Column(TMatrix* PMatrix, int j);

bool GoToNextColumnElem(TMatrix* Matrix);

bool GoToNextLineElem(TMatrix* Matrix);

bool ReadValueOfCurrentElem(TMatrix* Matrix, int& Value);

bool ChangeValueOfCurrenElem(TMatrix* Matrix, int Value);

void MatrixOutput(FILE* flog, TMatrix* PMatrix);

bool ChangeValueOfMatrixElem(TMatrix* Matrix, int i, int j, int Value);

bool ReadValueOfMatrixElem(TMatrix* Matrix, int i, int j, int& Value);

bool AddMatrixColumn(TMatrix* Matrix);

bool AddMatrixLine(TMatrix* Matrix);

void ClearMatrix(TMatrix* Matrix);


