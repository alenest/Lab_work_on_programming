#pragma once

/*
- очистить матрицу (освободить память);
- создать матрицу, считав размеры и значения элементов из текстового файла;
- изменить один элемент по индексам, на основе данных введенных в
интерактивном режиме (с клавиатуры или с формы);
- изменить размер матрицы, добавив строку или столбец из 0(нулей);
- поиск: решить задачу из нижеприведенного списка задач для Задания Д. 
*/

#define _CRT_SECURE_NO_WARNINGS

#include "Matrix_list.h"

//bool MatrixMemoryAllocation(TMatrix* Matrix, int N, int M);
void ClearMatrix(TMatrix* Matrix);

void CreateMatrix(FILE* ft, FILE* flog, TMatrix* Matrix);

void ChangeValueOfMatrixElemFromConsole(FILE* flog, TMatrix* Matrix);

void AddZeroLine(FILE* flog, TMatrix* Matrix);

void AddZeroColumn(FILE* flog, TMatrix* Matrix);

void MatrixOutput(FILE* f, TMatrix* Matrix);
