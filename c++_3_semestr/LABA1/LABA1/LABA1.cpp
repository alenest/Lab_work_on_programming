// LABA1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "MODUL1.h"



void main()
{

	TElem* StackTop = NULL; double Number; TInfo Info;

	char ch;

	SetConsoleOutputCP(1251);

	SetConsoleCP(1251);

	do {

		printf("\nN - добавить элемент в стек;\nV - вывод;\nD - удалить элемент;\nF - освободить память;\nS - преобразовать стек в очередь;\nE - конец.\nВаш выбор ? ");

		ch = getchar(); fflush(stdin);

		ch = toupper(ch);

		switch (ch) {

		case 'N': /*if (StackTop)
		{
			printf("Error: сначала надо освободить память!"); break;
		}*/
				printf("\nВведите значение нового элемента: \n");
				fflush(stdin);
				scanf("%lf", &Number);
				Info.Number = Number;
				StackTop = PushElemToStructure(StackTop, Info);
				break;
		case 'V':
			printf("Содержимое структуры :\n"); OutputStructure(StackTop);
			
			break;

		case 'F':
			StackTop = FreeStructure(StackTop);

			printf("Вся память под структуру особождена\n");

			break;

		case 'D': 
			if (StackTop == NULL) { printf("\nСтек пуст\n"); break; };
			TInfo Info;
			Info = PopElemFromStructure(&StackTop);
			printf("\nМы удалили элемент: %5.2lf\n", Info.Number);
			break;

		case 'S':
			StackTop = SwitchStackToQueue(StackTop);
			printf("\nСтек преобразован в очередь\n");
			break;
			
		case 'E': return;

		default:
			fflush(stdin);
			printf("Нет такой команды\nPress any key"); getchar();

		}
		fflush(stdin);
		ch = getchar();
	} while (ch != 'E');

	return;
}
	/*do {

		printf("\nN - добавить элемент в стек;\nV - вывод;\nD - решение;\nF - освободить;\nE - конец.\nВаш выбор ? ");

		ch = getchar(); fflush(stdin);

		ch = toupper(ch);

		switch (ch)
		{

		case 'N': if (StackTop)
		{
			printf("Error: сначала надо освободить память!"); break;
		}
				printf("\nВведите значение нового элемента: \n");
				
				scanf("lf", &Number);
				PInfo->Number = Number;
				StackTop = PushElemToStructure(StackTop, *PInfo);
				break;

				case 'E': return;
				default:
				printf("Нет такой команды\nPress any key"); getchar();
				}
				ch = getchar();
		} while (ch != 'E');
	return;
}*/

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
