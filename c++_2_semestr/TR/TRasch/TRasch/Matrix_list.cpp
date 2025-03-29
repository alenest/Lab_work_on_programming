#include "Matrix_list.h"

bool MatrixIsEmpty(TMatrix* PMatrix)
{
	if (PMatrix->HeadElem == nullptr) return true;
	else return false;
}

TMatrix MatrixMemoryAllocation(int N, int M)
{
	TMatrix* PMatrix;
	PMatrix = (TMatrix*)malloc(sizeof(TMatrix));

	TMatrixElem* PElem1;
	PElem1 = (TMatrixElem*)malloc(sizeof(TMatrixElem));
	PElem1 ->NextColumnElem =  nullptr;
	PElem1->NextLineElem = nullptr;
	//PElem1->ElemValue = 101;
	PMatrix->HeadElem = PElem1;
	PMatrix->CurrentPosition = PElem1;
	/*printf("[%d][%d]\n", N, M);
	printf("������� a[1][1]\n");
	printf("������� ������� �������: %d\n", PElem1->ElemValue);
	printf("������ �������\n");*/
	//������� ������ ������� (���� N<2, �� �� �� ������ � ����)
	for (int i = 2; i <= N; i++)
	{
		TMatrixElem* PElem2;
		PElem2 = (TMatrixElem*)malloc(sizeof(TMatrixElem));
		PElem2->NextLineElem = nullptr;
		PElem2->NextColumnElem = nullptr;
		//PElem2->ElemValue = i * 100 + 1;
		PElem1->NextLineElem = PElem2;
		//printf("���������� ��������� ��: %d\n", PElem1->NextLineElem->ElemValue);
		PElem1 = PElem2;
		/*printf("������� a[%d][1]\n", i);
		printf("������� ������� �������: %d\n", PElem1->ElemValue);*/
	}
	//printf("������ ������ �����������\n");
	TMatrixElem* FirstElemOfPreviousColumn = PMatrix->HeadElem;
	for (int j = 2; j <= M; j++)
	{
		TMatrixElem* ElemOfPreviousColumn = FirstElemOfPreviousColumn;
		TMatrixElem* ElemOfPreviousLine;
		ElemOfPreviousLine = (TMatrixElem*)malloc(sizeof(TMatrixElem));
		ElemOfPreviousLine->NextColumnElem = nullptr;
		ElemOfPreviousLine->NextLineElem = nullptr;
		//ElemOfPreviousLine->ElemValue = 100 + j;
		/*printf("������� a[1][%d]\n", j);
		printf("������� ������� �������: %d\n", ElemOfPreviousLine->ElemValue);*/
		FirstElemOfPreviousColumn = ElemOfPreviousLine;

		ElemOfPreviousColumn->NextColumnElem = ElemOfPreviousLine;
		ElemOfPreviousColumn = ElemOfPreviousColumn->NextLineElem;

		for (int i = 2; i <= N; i++)
		{
			TMatrixElem* NewElem;
			NewElem = (TMatrixElem*)malloc(sizeof(TMatrixElem));
			NewElem->NextColumnElem = nullptr;
			NewElem->NextLineElem = nullptr;
			//NewElem->ElemValue = 100 * i + j;

			/*printf("������� a[%d][%d], ", i, j);
			printf("������� ������� �������: %d\n", NewElem->ElemValue);*/

			ElemOfPreviousColumn->NextColumnElem = NewElem;
			ElemOfPreviousLine->NextLineElem = NewElem;

			ElemOfPreviousColumn = ElemOfPreviousColumn->NextLineElem;
			ElemOfPreviousLine = NewElem;
		}

	}
	TMatrix Matrix;
	Matrix.HeadElem = PMatrix->HeadElem;
	Matrix.CurrentPosition = PMatrix->CurrentPosition;
	return Matrix;
}

bool GoTo_i_Line(TMatrix* PMatrix, int i)
{
	if(MatrixIsEmpty(PMatrix)) return false;
	TMatrixElem* CurrentElem;
	CurrentElem = (TMatrixElem*)malloc(sizeof(TMatrixElem));
	CurrentElem = PMatrix->HeadElem;
	
	for (int ii = 2; ii <= i; ii++)
	{
		CurrentElem = CurrentElem->NextLineElem;
		if (CurrentElem->NextLineElem == nullptr && ii < i) return false;
	}
	PMatrix->CurrentPosition = CurrentElem;
	return true;
}

bool GoTo_j_Column(TMatrix* PMatrix, int j)
{
	if (MatrixIsEmpty(PMatrix)) return false;
	TMatrixElem* CurrentElem;
	CurrentElem = (TMatrixElem*)malloc(sizeof(TMatrixElem));
	CurrentElem = PMatrix->HeadElem;

	for (int jj = 2; jj <= j; jj++)
	{
		CurrentElem = CurrentElem->NextColumnElem;
		if (CurrentElem->NextColumnElem == nullptr && jj < j) return false;
	}
	PMatrix->CurrentPosition = CurrentElem;
	return true;
}

bool GoToNextColumnElem(TMatrix* Matrix)
{
	if (MatrixIsEmpty(Matrix)) return false;
	//���� � ���� ������� ��� ������ ���������, �� ������� �� ������
	if (Matrix->CurrentPosition->NextColumnElem == nullptr) return false;

	Matrix->CurrentPosition = Matrix->CurrentPosition->NextColumnElem;
	return true;
}

bool GoToNextLineElem(TMatrix* Matrix)
{
	if (MatrixIsEmpty(Matrix)) return false;
	//���� � ���� ������ ��� ������ ���������, �� ������� �� ������
	if (Matrix->CurrentPosition->NextLineElem == nullptr) return false;
	Matrix->CurrentPosition = Matrix->CurrentPosition->NextLineElem;
	return true;
}

bool ReadValueOfCurrentElem(TMatrix* Matrix, int& Value)
{
	if (MatrixIsEmpty(Matrix)) return false;
	Value = Matrix->CurrentPosition->ElemValue; return true;
}

bool ChangeValueOfCurrenElem(TMatrix* Matrix,int Value)
{
	if (MatrixIsEmpty(Matrix)) return false;
	Matrix->CurrentPosition->ElemValue = Value; return true;
}

void MatrixOutput(FILE* flog, TMatrix* PMatrix)
{
	if (MatrixIsEmpty(PMatrix))
	{
		fprintf(flog, "\n������� ������\n");
		printf("\n������� ������\n");
		return;
	}
	//TMatrixElem* Elem = PMatrix->HeadElem;
	/*TMatrix* MatrixClone = Matrix;*/
	PMatrix->CurrentPosition = PMatrix->HeadElem;
	//printf("\n�������\n");
	int i = 1;
	while (PMatrix->CurrentPosition->NextColumnElem != nullptr or PMatrix->CurrentPosition->NextLineElem != nullptr)
	{
		if (PMatrix->CurrentPosition->NextColumnElem != nullptr)
		{
			int Value;
			ReadValueOfCurrentElem(PMatrix, Value);
			fprintf(flog, "%7d ", Value);
			printf("%5d ", Value);
			/*printf("\n�������� �������: %d\n", PMatrix->HeadElem->ElemValue);
			printf("������� �������: %d\n\n", PMatrix->CurrentPosition->ElemValue);
			printf("��������� �������: %d\n\n", PMatrix->CurrentPosition->NextColumnElem->ElemValue);*/
			GoToNextColumnElem(PMatrix);
		}
		else
		{
			int Value;
			ReadValueOfCurrentElem(PMatrix, Value);
			fprintf(flog, "%7d\n", Value);
			printf("%5d\n", Value);
			/*printf("\n�������� �������: %d\n", PMatrix->HeadElem->ElemValue);
			printf("������� �������: %d\n\n", PMatrix->CurrentPosition->ElemValue);*/
			i++;
			GoTo_i_Line(PMatrix, i);
			/*printf("\n�������� �������: %d\n", PMatrix->HeadElem->ElemValue);
			printf("������� �������: %d\n\n", PMatrix->CurrentPosition->ElemValue);*/
		}
		
	}
	int Value;
	ReadValueOfCurrentElem(PMatrix, Value);
	fprintf(flog, "%5d\n", Value);
	printf("%5d\n", Value);
	PMatrix->CurrentPosition = PMatrix->HeadElem;
	/*printf("\n�������� �������: %d\n", PMatrix->HeadElem->ElemValue);
	printf("������� �������: %d\n\n", PMatrix->CurrentPosition->ElemValue);*/
}

bool ChangeValueOfMatrixElem(TMatrix* Matrix, int i, int j, int Value)
{
	if (MatrixIsEmpty(Matrix)) return false;
	//TMatrixElem* Elem = Matrix->HeadElem;
	TMatrix* MatrixClone;
	MatrixClone = (TMatrix*)malloc(sizeof(TMatrix));
	MatrixClone = Matrix;
	MatrixClone->CurrentPosition = Matrix->HeadElem;
	//���������� false ���� �������� ������������ ���������� �������
	if (!GoTo_i_Line(MatrixClone, i)) return false;
	for (int jj = 2; jj <= j; jj++)
	{
		//���������� false ���� �������� ������������ ���������� ��������
		if (!GoToNextColumnElem(MatrixClone)) return false;
	}
	MatrixClone->CurrentPosition->ElemValue = Value;
	return true;
}

bool ReadValueOfMatrixElem(TMatrix* Matrix, int i, int j, int& Value)
{
	if (MatrixIsEmpty(Matrix)) return false;
	//TMatrixElem* Elem = Matrix->HeadElem;
	TMatrix* MatrixClone = Matrix;
	MatrixClone->CurrentPosition = Matrix->HeadElem;
	//���������� false ���� �������� ������������ ���������� �������
	if (!GoTo_i_Line(MatrixClone, i)) return false;
	for (int jj = 2; jj <= j; jj++)
	{
		//���������� false ���� �������� ������������ ���������� ��������
		if (!GoToNextColumnElem(MatrixClone)) return false;
	}
	Value = MatrixClone->CurrentPosition->ElemValue;
	return true;
}


bool AddMatrixColumn(TMatrix* Matrix)
{
	//���� ������� �������� ������, �� ������� �� ���������
	if (MatrixIsEmpty(Matrix)) return false;
	TMatrixElem* CurrentElem = Matrix->HeadElem;
	//������� �� ���������� �������� 1 ������
	while (CurrentElem->NextColumnElem != nullptr)
	{
		CurrentElem = CurrentElem->NextColumnElem;
	}
	//TMatrixElem* PreviousColumnElem = CurrentElem->NextLineElem;
	//������ ������� ������ �������
	TMatrixElem* NewElem;
	NewElem = (TMatrixElem*)malloc(sizeof(TMatrixElem));
	NewElem->NextLineElem = nullptr;
	NewElem->NextColumnElem = nullptr;
	CurrentElem->NextColumnElem = NewElem;

	TMatrixElem* PreviousLineElem = NewElem;
	TMatrixElem* PreviousColumnElem = CurrentElem -> NextLineElem;

	while (PreviousColumnElem->NextLineElem != nullptr)
	{
		TMatrixElem* NextElem;
		NextElem = (TMatrixElem*)malloc(sizeof(TMatrixElem));
		NextElem->NextLineElem = nullptr;
		NextElem->NextColumnElem = nullptr;
		PreviousLineElem->NextLineElem = NextElem;
		PreviousColumnElem->NextColumnElem = NextElem;

		PreviousColumnElem = PreviousColumnElem->NextLineElem;
		PreviousLineElem = NextElem;
	}
	TMatrixElem* NextElem;
	NextElem = (TMatrixElem*)malloc(sizeof(TMatrixElem));
	NextElem->NextLineElem = nullptr;
	NextElem->NextColumnElem = nullptr;

	PreviousLineElem->NextLineElem = NextElem;
	PreviousColumnElem->NextColumnElem = NextElem;
	return true;
}

bool AddMatrixLine(TMatrix* Matrix)
{
	//���� ������� �������� ������, �� ������ �� ���������
	if (MatrixIsEmpty(Matrix)) return false;
	TMatrixElem* CurrentElem = Matrix->HeadElem;
	//������� �� ���������� �������� 1 ������
	while (CurrentElem->NextLineElem != nullptr)
	{
		CurrentElem = CurrentElem->NextLineElem;
	}
	//������ ������� ����� ������
	TMatrixElem* NewElem;
	NewElem = (TMatrixElem*)malloc(sizeof(TMatrixElem));
	NewElem->NextColumnElem = nullptr;
	NewElem->NextLineElem = nullptr;
	CurrentElem->NextLineElem = NewElem;

	TMatrixElem* PreviousColumnElem = NewElem;
	TMatrixElem* PreviousLineElem = CurrentElem->NextColumnElem;

	while (PreviousLineElem->NextColumnElem != nullptr)
	{
		TMatrixElem* NextElem;
		NextElem = (TMatrixElem*)malloc(sizeof(TMatrixElem));
		NextElem->NextColumnElem = nullptr;
		NextElem->NextLineElem = nullptr;
		PreviousColumnElem->NextColumnElem = NextElem;
		PreviousLineElem->NextLineElem = NextElem;

		PreviousLineElem = PreviousLineElem->NextColumnElem;
		PreviousColumnElem = NextElem;
	}
	TMatrixElem* NextElem;
	NextElem = (TMatrixElem*)malloc(sizeof(TMatrixElem));
	NextElem->NextColumnElem = nullptr;
	NextElem->NextLineElem = nullptr;

	PreviousColumnElem->NextColumnElem = NextElem;
	PreviousLineElem->NextLineElem = NextElem;
	return true;
}

void ClearMatrix(TMatrix* Matrix)
{
	if (MatrixIsEmpty(Matrix)) return;
	TMatrixElem* CurrentElem = Matrix->HeadElem;
	TMatrixElem* NextColumnElem = CurrentElem->NextColumnElem;
	TMatrixElem* NextLineElem;
	while (CurrentElem->NextColumnElem != nullptr)
	{
		while (CurrentElem->NextLineElem != nullptr)
		{
			NextLineElem = CurrentElem->NextLineElem;
			free(CurrentElem);
			CurrentElem = NextLineElem;
		}
		free(CurrentElem);
		CurrentElem = NextColumnElem;
		NextColumnElem = CurrentElem->NextColumnElem;
	}
	Matrix->HeadElem = nullptr;
	Matrix->CurrentPosition = nullptr;
	//free(Matrix);
	//Matrix = nullptr;
	return;
}



