#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "Matrix_list.h"

//bool MatrixMemoryAllocation(TMatrix* Matrix, int N, int M);
//void ClearMatrix(TMatrix* Matrix);

TMatrix CreateMatrix(FILE* ft, FILE* flog);

void ChangeValueOfMatrixElemFromConsole(FILE* flog, TMatrix* Matrix);

void AddZeroLine(FILE* flog, TMatrix* Matrix);

void AddZeroColumn(FILE* flog, TMatrix* Matrix);

void MatrixFree(FILE* flog, TMatrix* Matrix);

void Search(FILE* flog, TMatrix* Matrix);

//void MatrixOutput(FILE* f, TMatrix* Matrix);
