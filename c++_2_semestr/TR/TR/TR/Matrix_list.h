#pragma once
//struct TElem {
//	int Num;
//	TElem* Line;
//	TElem* Column;
//};
//
//struct TMatrix {
//	TElem* Head;
//	TElem* Now;
//	int i, j;
//	int n, m;
//};

#include <iostream>
#include <windows.h> // SetConsoleOutputCP, SetConsoleCP
#include <stdio.h> //printf , fgets
#include <conio.h> // getch
#include <string.h> // strcpy, strncmp, strchr

struct TElemValue
{
	int Value;
};

struct TMatrixElem
{
	TElemValue ElemValue;
	TMatrixElem* NextLineElem;
	TMatrixElem* NextColumnElem;
};

struct TMatrix
{
	//MatrixElem* CurrentElem;
	TMatrixElem* HeadElem;
	TMatrixElem* CurrentElem;
};

bool isMatrixEmpty(TMatrix* Matrix);

bool MatrixMemoryAllocation(TMatrix* Matrix, int N, int M);

bool AddMatrixColumn(TMatrix* Matrix);

bool AddMatrixLine(TMatrix* Matrix);

void ClearMatrix(TMatrix* Matrix);

bool GoTo_i_Line(TMatrix* Matrix, int i);

bool GoTo_j_Column(TMatrix* Matrix, int j);

bool GoToNextColumnElem(TMatrix* Matrix);

bool GoToNextLineElem(TMatrix* Matrix);

bool ReadValueOfCurrentElem(TMatrix* Matrix, TElemValue& Value);

bool ChangeValueOfCurrenElem(TMatrix* Matrix, TElemValue Value);

bool ChangeValueOfMatrixElem(TMatrix* Matrix, int i, int j, TElemValue Value);

bool ReadValueOfMatrixElem(TMatrix* Matrix, int i, int j, TElemValue& Value);

void MatrixOutput(FILE* f, TMatrix* Matrix);


