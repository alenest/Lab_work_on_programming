#include "TR_App.h"

TMatrix CreateMatrix(FILE* ft, FILE* flog)
{
	int N, M;
	fscanf(ft, "%d  %d", &N, &M);
	if (N < 1 || M < 1) { fprintf(flog, "\nнекорректная размерность матрицы\n"); printf("\nнекорректная размерность матрицы\n"); }
	else
	{
		TMatrix Matrix = MatrixMemoryAllocation(N, M);
		/*printf("Головной Элемент: %d\n", Matrix.HeadElem->ElemValue);
		printf("Текущий Элемент: %d\n", Matrix.CurrentPosition->ElemValue);
		printf("___________________________________________________\n");*/
		for (int NN = 1; NN <= N; NN++)
		{
			//printf("\n____________________________________строка\n");
			GoTo_i_Line(&Matrix, NN);
			for (int MM = 1; MM <= M; MM++)
			{
				int Value;
				fscanf(ft, "%d", &Value);
				//printf("значение элемента %d\n", Value);
				ChangeValueOfCurrenElem(&Matrix, Value);
				/*printf("Головной Элемент: %d\n", Matrix.HeadElem->ElemValue);
				printf("Текущий Элемент: %d\n\n", Matrix.CurrentPosition->ElemValue);*/
				GoToNextColumnElem(&Matrix);
			}	
		}
		MatrixOutput(flog, &Matrix);
		return Matrix;
		//if (!isMatrixEmpty(PMatrix)) ;
	}
}

void ChangeValueOfMatrixElemFromConsole(FILE* flog, TMatrix* Matrix)
{
	printf("\nВведите индексы i(строки) и j(столбцы) элемента матрицы,\nкоторому хотите изменить значение (отсчет индексов идет с единицы): \n");
	int i, j; scanf("%d%d", &i, &j);
	printf("Введите новое значение элемента: \n");
	int ElemValue; scanf("%d", &ElemValue);
	fprintf(flog, "\nC консоли считано новое значение элемента[%d][%d]: %d\n", i, j, ElemValue);
	if (MatrixIsEmpty(Matrix)) { fprintf(flog, "\nМатрица пуста, невозможно поменять элемент по введенным индексам\n");
	printf("\nМатрица пуста, невозможно поменять элемент по введенным индексам\n"); return; }
	if (i < 1) { fprintf(flog, "\nНекорректный индекс строк\n"); printf("\nНекорректный индекс строк\n");  return; }
	if (j < 1) { fprintf(flog, "\nНекорректный индекс столбцов\n"); printf("\nНекорректный индекс столбцов\n"); return; }
	if (!GoTo_i_Line(Matrix, i)) { fprintf(flog, "\nВ матрице меньше строк\n"); printf("\nВ матрице меньше строк\n"); return; };
	if (!GoTo_j_Column(Matrix, j)) { fprintf(flog, "\nВ матрице меньше столбцов\n"); printf("\nВ матрице меньше столбцов\n"); return; };
	ChangeValueOfMatrixElem(Matrix, i, j, ElemValue); fprintf(flog, "\nЭлемент Изменен\n"); printf("\nЭлемент Изменен\n");
	MatrixOutput(flog, Matrix);
	return;
}

void AddZeroLine(FILE* flog, TMatrix* Matrix)
{
	if (!AddMatrixLine(Matrix)) { fprintf(flog, "\nМатрица пуста, невозможно добавить строку матрице\n"); return; }
	GoTo_i_Line(Matrix, 1);
	while (true)
	{
		//если дошли до последнего элемента в 1 строке
		if (!GoToNextLineElem(Matrix)) break;
		else GoToNextLineElem;
	}
	while (true)
	{
		int ElemValue = 0;
		ChangeValueOfCurrenElem(Matrix, ElemValue);
		if (!GoToNextColumnElem(Matrix)) break;
		else GoToNextColumnElem;
	}
	fprintf(flog, "\nНулевая строка добавлена\n");
	MatrixOutput(flog, Matrix); return;
}

void AddZeroColumn(FILE* flog, TMatrix* Matrix)
{
	if (!AddMatrixColumn(Matrix)) { fprintf(flog, "\nМатрица пуста, невозможно добавить столбец матрице\n"); return; }
	GoTo_j_Column(Matrix, 1);
	while (true)
	{
		//если дошли до последнего элемента в 1 строке
		if (!GoToNextColumnElem(Matrix)) break;
		else GoToNextColumnElem;
	}
	while (true)
	{
		int ElemValue = 0;
		ChangeValueOfCurrenElem(Matrix, ElemValue);
		if (!GoToNextLineElem(Matrix)) break;
		else GoToNextLineElem;
	}
	fprintf(flog, "\nНулевой столбец добавлен\n");
	MatrixOutput(flog, Matrix); return;
}

void MatrixFree(FILE* flog, TMatrix* Matrix)
{
	if (MatrixIsEmpty(Matrix)) 
	{
		fprintf(flog, "\nМатрица пуста.\n");
		printf("\nМатрица пуста.\n"); return;
	}
	ClearMatrix(Matrix);
	fprintf(flog, "\nМатрица очищена.\n");
	printf("\nМатрица очищена.\n"); 
	MatrixOutput(flog, Matrix); 
	return;
}

void Search(FILE *flog, TMatrix* Matrix)
{
	if (MatrixIsEmpty(Matrix)) { fprintf(flog, "\nМатрица пуста, невозможно произвести поиск\n"); printf("\nМатрица пуста, невозможно произвести поиск\n"); return; }
	int lastchetn;
	int i = 1, j = 1;
	int i_lastchetn = -1; int j_lastchetn = -1;
	//bool flag = false;
	while (GoTo_j_Column(Matrix, j))
	{
		i = 1;
		int Value;
		ReadValueOfCurrentElem(Matrix, Value);
		if (Value % 2 == 0) { i_lastchetn = i; j_lastchetn = j; }
		//переходим к первому элементу j строки
		while (GoToNextLineElem(Matrix))
		{
			//int Value;
			i++;
			ReadValueOfCurrentElem(Matrix, Value);
			//если нашли четное число, то запоминаем его индексы
			if (Value % 2 == 0) { i_lastchetn = i; j_lastchetn = j; }
			
		}
		j++;
	}
	if((i_lastchetn == -1) && (j_lastchetn == -1)) { fprintf(flog, "\nВ матрице не оказалось четных элементов\n"); printf("\nВ матрице не оказалось четных элементов\n"); return; }

	fprintf(flog, "\nПоследнее четное число в матрице лежит под индексами : a[%d][%d]\n", i_lastchetn, j_lastchetn);
	printf("Последнее четное число в матрице лежит под индексами : a[%d][%d]\n", i_lastchetn, j_lastchetn);
	int Value; ReadValueOfMatrixElem(Matrix, i_lastchetn, j_lastchetn, Value);
	fprintf(flog, "Последнее четное число: %d\n", Value);
	printf( "Последнее четное число: %d\n", Value);
	if (i_lastchetn == 1 && j_lastchetn == 1) { fprintf(flog, "\nНе осталось диапазона для поиска нечетных элементов\n"); printf("\nНе осталось диапазона для поиска нечетных элементов\n"); return; }
	int i_maxnechet = -1; int j_maxnechet = -1;
	int maxnechetn; 
	bool flag = false;
	i = 1; j = 1;
	for (int j = 1; j <= j_lastchetn; j++)
	{
		GoTo_j_Column(Matrix, j);
		i = 1;
		if (j < j_lastchetn)
		{
			while (GoToNextLineElem(Matrix))
			{
				int Value;
				ReadValueOfMatrixElem(Matrix, i, j, Value);
				//флаг нужен для того, чтобы взять его за максимальное нечетное
				if (Value % 2 != 0 && !flag) { flag = true; maxnechetn = Value;  i_maxnechet = i; j_maxnechet = j; }
				else if (Value % 2 != 0 && flag) { if (maxnechetn <= Value) { maxnechetn = Value;  i_maxnechet = i; j_maxnechet = j; } }
				//printf("\nСчитали значение: %d\n", Value);
				i++;
			}
		}
		else
		{
			while (i != i_lastchetn)
			{
				//GoToNextLineElem(Matrix);
				int Value;
				ReadValueOfMatrixElem(Matrix, i, j, Value);
				//флаг нужен для того, чтобы взять его за максимальное нечетное
				if (Value % 2 != 0 && !flag) { flag = true; maxnechetn = Value;  i_maxnechet = i; j_maxnechet = j; }
				else if (Value % 2 != 0 && flag) { if (maxnechetn <= Value) { maxnechetn = Value;  i_maxnechet = i; j_maxnechet = j; } }
				//printf("\nСчитали значение: %d\n", Value);
				i++;
			}
		}
		
	}
	if (!flag) { fprintf(flog, "\nНе нашлось нечетных элементов до последнего четного\n"); printf("\nНе нашлось нечетных элементов до последнего четного\n"); return; }
	fprintf(flog, "\nМаксимальное нечетное число, лежащее до последнего четного числа, в матрице лежит под индексами : a[%d][%d]\n", i_maxnechet, j_maxnechet);
	printf("\nМаксимальное нечетное число, лежащее до последнего четного числа, в матрице лежит под индексами : a[%d][%d]\n", i_maxnechet, j_maxnechet);
	ReadValueOfMatrixElem(Matrix, i_maxnechet, j_maxnechet, Value);
	fprintf(flog, "Максимальное нечетное число, лежащее до последнего четного числа: %d\n", Value);
	printf( "Максимальное нечетное число, лежащее до последнего четного числа: %d\n", Value);
	return;
}
