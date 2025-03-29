#include "TR_App.h"

TMatrix CreateMatrix(FILE* ft, FILE* flog)
{
	int N, M;
	fscanf(ft, "%d  %d", &N, &M);
	if (N < 1 || M < 1) { fprintf(flog, "\n������������ ����������� �������\n"); printf("\n������������ ����������� �������\n"); }
	else
	{
		TMatrix Matrix = MatrixMemoryAllocation(N, M);
		/*printf("�������� �������: %d\n", Matrix.HeadElem->ElemValue);
		printf("������� �������: %d\n", Matrix.CurrentPosition->ElemValue);
		printf("___________________________________________________\n");*/
		for (int NN = 1; NN <= N; NN++)
		{
			//printf("\n____________________________________������\n");
			GoTo_i_Line(&Matrix, NN);
			for (int MM = 1; MM <= M; MM++)
			{
				int Value;
				fscanf(ft, "%d", &Value);
				//printf("�������� �������� %d\n", Value);
				ChangeValueOfCurrenElem(&Matrix, Value);
				/*printf("�������� �������: %d\n", Matrix.HeadElem->ElemValue);
				printf("������� �������: %d\n\n", Matrix.CurrentPosition->ElemValue);*/
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
	printf("\n������� ������� i(������) � j(�������) �������� �������,\n�������� ������ �������� �������� (������ �������� ���� � �������): \n");
	int i, j; scanf("%d%d", &i, &j);
	printf("������� ����� �������� ��������: \n");
	int ElemValue; scanf("%d", &ElemValue);
	fprintf(flog, "\nC ������� ������� ����� �������� ��������[%d][%d]: %d\n", i, j, ElemValue);
	if (MatrixIsEmpty(Matrix)) { fprintf(flog, "\n������� �����, ���������� �������� ������� �� ��������� ��������\n");
	printf("\n������� �����, ���������� �������� ������� �� ��������� ��������\n"); return; }
	if (i < 1) { fprintf(flog, "\n������������ ������ �����\n"); printf("\n������������ ������ �����\n");  return; }
	if (j < 1) { fprintf(flog, "\n������������ ������ ��������\n"); printf("\n������������ ������ ��������\n"); return; }
	if (!GoTo_i_Line(Matrix, i)) { fprintf(flog, "\n� ������� ������ �����\n"); printf("\n� ������� ������ �����\n"); return; };
	if (!GoTo_j_Column(Matrix, j)) { fprintf(flog, "\n� ������� ������ ��������\n"); printf("\n� ������� ������ ��������\n"); return; };
	ChangeValueOfMatrixElem(Matrix, i, j, ElemValue); fprintf(flog, "\n������� �������\n"); printf("\n������� �������\n");
	MatrixOutput(flog, Matrix);
	return;
}

void AddZeroLine(FILE* flog, TMatrix* Matrix)
{
	if (!AddMatrixLine(Matrix)) { fprintf(flog, "\n������� �����, ���������� �������� ������ �������\n"); return; }
	GoTo_i_Line(Matrix, 1);
	while (true)
	{
		//���� ����� �� ���������� �������� � 1 ������
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
	fprintf(flog, "\n������� ������ ���������\n");
	MatrixOutput(flog, Matrix); return;
}

void AddZeroColumn(FILE* flog, TMatrix* Matrix)
{
	if (!AddMatrixColumn(Matrix)) { fprintf(flog, "\n������� �����, ���������� �������� ������� �������\n"); return; }
	GoTo_j_Column(Matrix, 1);
	while (true)
	{
		//���� ����� �� ���������� �������� � 1 ������
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
	fprintf(flog, "\n������� ������� ��������\n");
	MatrixOutput(flog, Matrix); return;
}

void MatrixFree(FILE* flog, TMatrix* Matrix)
{
	if (MatrixIsEmpty(Matrix)) 
	{
		fprintf(flog, "\n������� �����.\n");
		printf("\n������� �����.\n"); return;
	}
	ClearMatrix(Matrix);
	fprintf(flog, "\n������� �������.\n");
	printf("\n������� �������.\n"); 
	MatrixOutput(flog, Matrix); 
	return;
}

void Search(FILE *flog, TMatrix* Matrix)
{
	if (MatrixIsEmpty(Matrix)) { fprintf(flog, "\n������� �����, ���������� ���������� �����\n"); printf("\n������� �����, ���������� ���������� �����\n"); return; }
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
		//��������� � ������� �������� j ������
		while (GoToNextLineElem(Matrix))
		{
			//int Value;
			i++;
			ReadValueOfCurrentElem(Matrix, Value);
			//���� ����� ������ �����, �� ���������� ��� �������
			if (Value % 2 == 0) { i_lastchetn = i; j_lastchetn = j; }
			
		}
		j++;
	}
	if((i_lastchetn == -1) && (j_lastchetn == -1)) { fprintf(flog, "\n� ������� �� ��������� ������ ���������\n"); printf("\n� ������� �� ��������� ������ ���������\n"); return; }

	fprintf(flog, "\n��������� ������ ����� � ������� ����� ��� ��������� : a[%d][%d]\n", i_lastchetn, j_lastchetn);
	printf("��������� ������ ����� � ������� ����� ��� ��������� : a[%d][%d]\n", i_lastchetn, j_lastchetn);
	int Value; ReadValueOfMatrixElem(Matrix, i_lastchetn, j_lastchetn, Value);
	fprintf(flog, "��������� ������ �����: %d\n", Value);
	printf( "��������� ������ �����: %d\n", Value);
	if (i_lastchetn == 1 && j_lastchetn == 1) { fprintf(flog, "\n�� �������� ��������� ��� ������ �������� ���������\n"); printf("\n�� �������� ��������� ��� ������ �������� ���������\n"); return; }
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
				//���� ����� ��� ����, ����� ����� ��� �� ������������ ��������
				if (Value % 2 != 0 && !flag) { flag = true; maxnechetn = Value;  i_maxnechet = i; j_maxnechet = j; }
				else if (Value % 2 != 0 && flag) { if (maxnechetn <= Value) { maxnechetn = Value;  i_maxnechet = i; j_maxnechet = j; } }
				//printf("\n������� ��������: %d\n", Value);
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
				//���� ����� ��� ����, ����� ����� ��� �� ������������ ��������
				if (Value % 2 != 0 && !flag) { flag = true; maxnechetn = Value;  i_maxnechet = i; j_maxnechet = j; }
				else if (Value % 2 != 0 && flag) { if (maxnechetn <= Value) { maxnechetn = Value;  i_maxnechet = i; j_maxnechet = j; } }
				//printf("\n������� ��������: %d\n", Value);
				i++;
			}
		}
		
	}
	if (!flag) { fprintf(flog, "\n�� ������� �������� ��������� �� ���������� �������\n"); printf("\n�� ������� �������� ��������� �� ���������� �������\n"); return; }
	fprintf(flog, "\n������������ �������� �����, ������� �� ���������� ������� �����, � ������� ����� ��� ��������� : a[%d][%d]\n", i_maxnechet, j_maxnechet);
	printf("\n������������ �������� �����, ������� �� ���������� ������� �����, � ������� ����� ��� ��������� : a[%d][%d]\n", i_maxnechet, j_maxnechet);
	ReadValueOfMatrixElem(Matrix, i_maxnechet, j_maxnechet, Value);
	fprintf(flog, "������������ �������� �����, ������� �� ���������� ������� �����: %d\n", Value);
	printf( "������������ �������� �����, ������� �� ���������� ������� �����: %d\n", Value);
	return;
}
