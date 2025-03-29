// LABA10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS

#include "MODUL10.h"

void main(int argc, char* argv[])
{
	if (argc < 3) {
		printf("Мало параметров\nPress any key");
		system("pause");
		return;
	}
	FILE* ft1 = fopen(argv[1], "rt");
	if (ft1 == NULL) {
		printf("Error: не удалось открыть файл с исходными данными для стека неотрицательных чисел %s\n", argv[1]);
		system("pause");
		return;
	}
	FILE* ft2 = fopen(argv[2], "rt");
	if (ft2 == NULL) {
		fclose(ft1);
		printf("Error: не удалось открыть файл с исходными данными для стека неположительных чисел %s\n", argv[2]);
		system("pause");
		return;
	}
	fclose(ft1); fclose(ft2);


	TElem* StackTop1 = NULL, * StackTop2 = NULL, * StackTop3 = NULL;

	char ch;

	SetConsoleOutputCP(1251);

	SetConsoleCP(1251);

	do {

		printf("\nN - создать новый стек;\nV - вывод;\nD - решение;\nF - освободить;\nE - конец.\nВаш выбор ? ");

		ch = getchar(); fflush(stdin);

		ch = toupper(ch);

		switch (ch) {

			//----------первая часть: создание стека из текстового

		case 'N': if (StackTop1 && StackTop2) {

			printf("Error: сначала надо освободить память!"); break;

		}
				StackTop1 = CreateNonNegativeStack(argc, argv, StackTop1);
				StackTop2 = CreateNonPositiveStack(argc, argv, StackTop2);
				break;

				//----------вторая часть: вывод стеков на экран ------

		case 'V': 
			printf("Стек неположительных чисел:\n"); OutputStack(StackTop1);
			printf("Стек неотрицательных чисел:\n"); OutputStack(StackTop2);
			printf("\nCтек чисел без нулей:\n"); OutputStack(StackTop3);

			break;

			//----------третья часть: решение задачи -------------

		case 'D': StackTop3 = Decide(&StackTop1,&StackTop2, StackTop3);

			break;

			//----------четвертая часть: освобождение памяти -----

		case 'F': 
			StackTop1 = FreeStack(StackTop1);
			StackTop2 = FreeStack(StackTop2);
			StackTop3 = FreeStack(StackTop3);

			printf("Вся память под стеки особождена\n");

			break;

			//-----------------------выход------------------------

		case 'E': return;

		default:

			printf("Нет такой команды\nPress any key"); getchar();

		}
		ch = getchar();
	} while (ch != 'E');

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
