#include "modul.h"

void ChooseYourTest(int ParamNumber, char* Param[], int**& matrix, int& i, int& MaxValue)
{
	int n; 
	printf("����� ����� (1 ; %d) = ", (ParamNumber - 2));
	scanf_s("%d/n", &n);

	FILE* f;
	printf("���� ����� : %s \n", Param[n + 1]);
	fopen_s(&f, Param[n + 1], "rt");
	FILE* fw;
	printf("���� ������ : %s \n", Param[1]);
	fopen_s(&fw, Param[1], "w");

	fscanf_s(f, "%d/n", &i);

	matrix = new int* [i];
	for (int u = 0; u < i; u++) matrix[u] = new int[i];

	fprintf(fw, "���� �������: \n");

	for (int ii = 0; ii < i; ii++)
	{
		for (int jj = 0; jj < i; jj++)
		{
			fscanf_s(f, "%d", &matrix[ii][jj]);
			fprintf(fw, "%d ", matrix[ii][jj]);
		}
		fprintf(fw, "\n");
	}

	fscanf_s(f, "%d/n", &MaxValue);
	fprintf(fw, "����� R: %d\n", MaxValue);

	fclose(f); fclose(fw);
}

bool CheckTask(int** matrix, int i, int MaxValue)
{
	int max, min;
	for (int ii = 0; ii < i; ii++)
	{
		max = matrix[ii][0];
		min = matrix[ii][0];
		for (int jj = 1; jj < i; jj++)
		{
			if (matrix[ii][jj] > max) max = matrix[ii][jj];
			if (matrix[ii][jj] < min) min = matrix[ii][jj];
		}
		//std::cout << max << " " << min << " " << (max - min) << std::endl;
		if (abs(max - min) > MaxValue) return false;
		
	}
	return true;
}

void DiagonalAssignment(int** matrix, int i, int* &array)
{
	//array = new int[i];
	for (int u = 0; u < i; u++)
	{
		array[u] = matrix[u][u];
	}
	return;
}

void ArrayOutput(char* Param[], int i ,int* array)
{
	FILE* fa;
	fopen_s(&fa, Param[1], "a");

	fprintf(fa, "������� ������������� �������.\n������ ��������� ������� ��������� �������:\n");
	for (int u = 0; u < i; u++)
	{
		fprintf(fa, "%d ", array[u]);
	}

	fclose(fa);
	return;
}

/*void ChooseYourTest(int ParamNumber, char* Param[], int** &matrix, int &i, int &MaxValue)
{
	//char fn[3];
	int n;
	printf("����� ����� (1 ; %d) = ", (ParamNumber-2));
	//scanf_s("%s/n", &fn, 3);
	scanf_s("%d/n", &n);
	FILE* f;
	fopen_s(&f, Param[n-1], "rt");
	if (!f) { // ��� if (f ==NULL) { 
		printf("Error: ������ ��� �������� ����� %s ��� ������\nPress any key", Param[n-1]);
		//getch(); // �������� ������� �������
		system("pause");
		return;
	}

	//int i;
	fscanf_s(f, "%d/n", &i);

	matrix = new int* [i];
	for (int u = 0; u < i; u++) matrix[u] = new int[i];

	//matrix = (int**)calloc(i, sizeof(int*)); // 2x3
	//for (int u = 0; u < i; u++)
	//	matrix[u] = (int*)calloc(i, sizeof(int));
	//printf("������");
	FILE* fw;
	//printf("���������");
	fopen_s(&fw, Param[1], "w");
	//fw = fopen(Param[1], "w");
	//printf("��������������");
	if (!fw) { // ��� if (f ==NULL) {

		printf("Error: ������ ��� �������� ����� %s ��� ������\nPress any key", Param[1]);
		//getch(); // �������� ������� �������
		system("pause");
		return;
	}

	fprintf(fw, "���� �������: \n");

	for (int ii = 0; ii < i; ii++)
	{
		for (int jj = 0; jj < i; jj++)
		{
			fscanf_s(f, "%d", &matrix[ii][jj]);
			fprintf(fw,"%d ", matrix[ii][jj]);
		}
		fprintf(fw, "\n");
	}
	/*for (int ii = 0; ii < i; ii++)
	{
		for (int jj = 0; jj < i; jj++)
		{
			fprintf(fw, "%d ", matrix[ii][jj]);
		}
		fprintf(fw, "\n");
	}

fscanf_s(f, "%d/n", &MaxValue);

fclose(f);
fclose(fw);
return;
}*/

