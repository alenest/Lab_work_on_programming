// TR.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS

#include "TR_App.h"

void main(int argc, char* argv[])
{
	if (argc < 3) {
		printf("Мало параметров\nPress any key");
		system("pause");
		return;
	}
	FILE* ft = fopen(argv[1], "rt");
	if (ft == NULL) {
		printf("Error: не удалось открыть файл c исходной матрицей %s\n", argv[1]);
		system("pause");
		return;
	}
	FILE* flog = fopen(argv[2], "w");
	if (flog == NULL) {
		fclose(ft);
		printf("Error: не удалось открыть файл с исходными данными для стека неположительных чисел %s\n", argv[2]);
		system("pause");
		return;
	}

	char ch;
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	TMatrix* Matrix;
	Matrix = (TMatrix*)malloc(sizeof(TMatrix));
	Matrix->CurrentElem = nullptr;
	Matrix->HeadElem = nullptr;
	do {
		printf("\nN - создать матрицу из текстового файла;\nV - изменить элемент по индексам;\n");
		printf("L - добавить нулевую строку;\nC - добавить нулевой столбец;\nD - очистить матрицу\nВаш выбор ? ");
		ch = getchar(); fflush(stdin);
		ch = toupper(ch);
		switch (ch) {
			//-------------------------------------------------
		case 'N': CreateMatrix(ft, flog, Matrix); break;
		//case 'O': MatrixOutput(flog, Matrix); break;
		case 'V': ChangeValueOfMatrixElemFromConsole(flog, Matrix); break;
		case 'L': AddZeroLine(flog, Matrix); break;
		case 'C': AddZeroColumn(flog, Matrix); break;
		case 'D': ClearMatrix(Matrix); break;
		case 'E': fclose(ft); fclose(flog); return;
		default:
			printf("Нет такой команды\nPress any key"); getchar();
		}
		ch = getchar();
	} while (ch != 'E');


	fclose(ft); fclose(flog);
	return;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
