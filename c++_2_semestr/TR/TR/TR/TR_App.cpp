
#include "TR_App.h"

void CreateMatrix(FILE* ft, FILE* flog, TMatrix* Matrix)
{
	if (!isMatrixEmpty(Matrix)) ClearMatrix(Matrix);
	Matrix = (TMatrix*)malloc(sizeof(TMatrix));
	Matrix->CurrentElem = nullptr;
	Matrix->HeadElem = nullptr;
	int N, M;
	fscanf(ft, "%d  %d", &N, &M);
	if (N < 1 || M < 1) { fprintf(flog, "\nнекорректная размерность матрицы\n"); printf("\nнекорректная размерность матрицы\n"); return; }
	if(!MatrixMemoryAllocation(Matrix, N, M)) { fprintf(flog, "\nпереданная матрица не является пустой\n"); printf("\nпереданная матрица не является пустой\n"); return; }
	//TMatrixElem* FIRSTELEM = Matrix->HeadElem;
	for (int MM = 1; MM <= M; MM++)
	{
		printf("\n____________________________________столбец\n");
		GoTo_j_Column(Matrix, MM);
		TElemValue Golova = Matrix->HeadElem->ElemValue;
		int Gol = Golova.Value;
		printf("\nГоловной элемент: %d\n", Gol);
		for (int NN = 1; NN <= N; NN++)
		{
			int Value;
			fscanf(ft, "%d", &Value);
			printf("значение элемента %d ", Value);
			TElemValue ValueOfElem;
			ValueOfElem.Value = Value;
			ChangeValueOfCurrenElem(Matrix, ValueOfElem);
			//ChangeValueOfMatrixElem(Matrix, NN, MM, ValueOfElem);
			TElemValue Zapisali = Matrix->CurrentElem->ElemValue;
			int Zap = Zapisali.Value;
			Golova = Matrix->HeadElem->ElemValue;
			 Gol = Golova.Value;
			printf("\na[%d][%d] = %d Головной элемент равен: %d\n", NN, MM, Zap, Gol);
			GoToNextColumnElem(Matrix);
			Golova = Matrix->HeadElem->ElemValue;
			Gol = Golova.Value;
			printf("\nГоловной элемент после перехода к следующему столбцу: %d\n", Gol);
		}
	}
	GoTo_i_Line(Matrix, 1);
	TElemValue Zapisali = Matrix->CurrentElem->ElemValue;
	int Zap = Zapisali.Value;
	printf("\nТекущий элемент = %d\n", Zap);
	Zapisali = Matrix->HeadElem->ElemValue;
	Zap = Zapisali.Value;
	printf("\nГоловной элемент = %d\n", Zap);
	//Matrix->HeadElem = FIRSTELEM;
	//Matrix->CurrentElem = FIRSTELEM;
	MatrixOutput(flog, Matrix);
	return;
}

void ChangeValueOfMatrixElemFromConsole(FILE* flog, TMatrix* Matrix)
{
	printf("\nВведите индексы i(строки) и j(столбцы) элемента матрицы, которому хотите изменить значение (отсчет индексов идет с единицы): \n");
	int i, j; scanf("%d%d", &i, &j);
	printf("\nВведите новое значение эелемента: \n");
	TElemValue ElemValue; scanf("%d", &ElemValue);
	fprintf(flog,"\nC консоли считано новое значение элемента[%d][%d]: %d\n", i, j, ElemValue);
	if (isMatrixEmpty(Matrix)) { fprintf(flog, "\nМатрица пуста, невозможно поменять элемент по введенным индексам\n"); return; }
	if (i < 1) { fprintf(flog, "\nНекорректный индекс строк\n"); return; }
	if (j < 1) { fprintf(flog, "\nНекорректный индекс столбцов\n"); return; }
	if (!GoTo_i_Line(Matrix, i)) { fprintf(flog, "\nВ матрице меньше строк\n"); return; };
	if (!GoTo_j_Column(Matrix, j)) { fprintf(flog, "\nВ матрице меньше столбцов\n"); return; };
	ChangeValueOfMatrixElem(Matrix, i, j, ElemValue); fprintf(flog, "\nЭлемент Изменен\n"); 
	MatrixOutput(flog, Matrix);
	return;
}

void AddZeroLine(FILE* flog, TMatrix* Matrix)
{
	if(!AddMatrixLine(Matrix)) { fprintf(flog, "\nМатрица пуста, невозможно добавить строку матрице\n"); return; }
	GoTo_i_Line(Matrix, 1);
	while (true)
	{
		//если дошли до последнего элемента в 1 столбце
		if (!GoToNextColumnElem(Matrix)) break;
		else GoToNextColumnElem;
	}
	while (true)
	{
		TElemValue ElemValue; ElemValue.Value = 0;
		ChangeValueOfCurrenElem(Matrix, ElemValue);
		if (!GoToNextLineElem(Matrix)) break;
		else GoToNextLineElem;
	}
	fprintf(flog, "\nНулевая строка добавлена\n"); 
	MatrixOutput(flog, Matrix);
	return;
}

void AddZeroColumn(FILE* flog, TMatrix* Matrix)
{
	if (!AddMatrixLine(Matrix)) { fprintf(flog, "\nМатрица пуста, невозможно добавить строку матрице\n"); return; }
	GoTo_j_Column(Matrix, 1);
	while (true)
	{
		//если дошли до последнего элемента в 1 строке
		if (!GoToNextLineElem(Matrix)) break;
		else GoToNextLineElem;
	}
	while (true)
	{
		TElemValue ElemValue; ElemValue.Value = 0;
		ChangeValueOfCurrenElem(Matrix, ElemValue);
		if (!GoToNextColumnElem(Matrix)) break;
		else GoToNextColumnElem;
	}
	fprintf(flog, "\nНулевой столбец добавлен\n"); 
	MatrixOutput(flog, Matrix); return;
}
