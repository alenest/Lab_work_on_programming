
#include "TR_App.h"

void CreateMatrix(FILE* ft, FILE* flog, TMatrix* Matrix)
{
	if (!isMatrixEmpty(Matrix)) ClearMatrix(Matrix);
	Matrix = (TMatrix*)malloc(sizeof(TMatrix));
	Matrix->CurrentElem = nullptr;
	Matrix->HeadElem = nullptr;
	int N, M;
	fscanf(ft, "%d  %d", &N, &M);
	if (N < 1 || M < 1) { fprintf(flog, "\n������������ ����������� �������\n"); printf("\n������������ ����������� �������\n"); return; }
	if(!MatrixMemoryAllocation(Matrix, N, M)) { fprintf(flog, "\n���������� ������� �� �������� ������\n"); printf("\n���������� ������� �� �������� ������\n"); return; }
	//TMatrixElem* FIRSTELEM = Matrix->HeadElem;
	for (int MM = 1; MM <= M; MM++)
	{
		printf("\n____________________________________�������\n");
		GoTo_j_Column(Matrix, MM);
		TElemValue Golova = Matrix->HeadElem->ElemValue;
		int Gol = Golova.Value;
		printf("\n�������� �������: %d\n", Gol);
		for (int NN = 1; NN <= N; NN++)
		{
			int Value;
			fscanf(ft, "%d", &Value);
			printf("�������� �������� %d ", Value);
			TElemValue ValueOfElem;
			ValueOfElem.Value = Value;
			ChangeValueOfCurrenElem(Matrix, ValueOfElem);
			//ChangeValueOfMatrixElem(Matrix, NN, MM, ValueOfElem);
			TElemValue Zapisali = Matrix->CurrentElem->ElemValue;
			int Zap = Zapisali.Value;
			Golova = Matrix->HeadElem->ElemValue;
			 Gol = Golova.Value;
			printf("\na[%d][%d] = %d �������� ������� �����: %d\n", NN, MM, Zap, Gol);
			GoToNextColumnElem(Matrix);
			Golova = Matrix->HeadElem->ElemValue;
			Gol = Golova.Value;
			printf("\n�������� ������� ����� �������� � ���������� �������: %d\n", Gol);
		}
	}
	GoTo_i_Line(Matrix, 1);
	TElemValue Zapisali = Matrix->CurrentElem->ElemValue;
	int Zap = Zapisali.Value;
	printf("\n������� ������� = %d\n", Zap);
	Zapisali = Matrix->HeadElem->ElemValue;
	Zap = Zapisali.Value;
	printf("\n�������� ������� = %d\n", Zap);
	//Matrix->HeadElem = FIRSTELEM;
	//Matrix->CurrentElem = FIRSTELEM;
	MatrixOutput(flog, Matrix);
	return;
}

void ChangeValueOfMatrixElemFromConsole(FILE* flog, TMatrix* Matrix)
{
	printf("\n������� ������� i(������) � j(�������) �������� �������, �������� ������ �������� �������� (������ �������� ���� � �������): \n");
	int i, j; scanf("%d%d", &i, &j);
	printf("\n������� ����� �������� ���������: \n");
	TElemValue ElemValue; scanf("%d", &ElemValue);
	fprintf(flog,"\nC ������� ������� ����� �������� ��������[%d][%d]: %d\n", i, j, ElemValue);
	if (isMatrixEmpty(Matrix)) { fprintf(flog, "\n������� �����, ���������� �������� ������� �� ��������� ��������\n"); return; }
	if (i < 1) { fprintf(flog, "\n������������ ������ �����\n"); return; }
	if (j < 1) { fprintf(flog, "\n������������ ������ ��������\n"); return; }
	if (!GoTo_i_Line(Matrix, i)) { fprintf(flog, "\n� ������� ������ �����\n"); return; };
	if (!GoTo_j_Column(Matrix, j)) { fprintf(flog, "\n� ������� ������ ��������\n"); return; };
	ChangeValueOfMatrixElem(Matrix, i, j, ElemValue); fprintf(flog, "\n������� �������\n"); 
	MatrixOutput(flog, Matrix);
	return;
}

void AddZeroLine(FILE* flog, TMatrix* Matrix)
{
	if(!AddMatrixLine(Matrix)) { fprintf(flog, "\n������� �����, ���������� �������� ������ �������\n"); return; }
	GoTo_i_Line(Matrix, 1);
	while (true)
	{
		//���� ����� �� ���������� �������� � 1 �������
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
	fprintf(flog, "\n������� ������ ���������\n"); 
	MatrixOutput(flog, Matrix);
	return;
}

void AddZeroColumn(FILE* flog, TMatrix* Matrix)
{
	if (!AddMatrixLine(Matrix)) { fprintf(flog, "\n������� �����, ���������� �������� ������ �������\n"); return; }
	GoTo_j_Column(Matrix, 1);
	while (true)
	{
		//���� ����� �� ���������� �������� � 1 ������
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
	fprintf(flog, "\n������� ������� ��������\n"); 
	MatrixOutput(flog, Matrix); return;
}
