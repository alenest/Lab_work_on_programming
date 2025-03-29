// LABA1_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "MODUL1_2.h"

void main()
{

	TElem* StackTop = NULL; int Number; TInfo Info;

	char ch;

	SetConsoleOutputCP(1251);

	SetConsoleCP(1251);

	do {

		printf("\nN - добавить n элементов в структуру;\nD - удалить первый элемент;\nI - вставить элемент после X;\nC - проверить на наличие одинкаовых элементов;\nV - вывод;\nE - конец.\nВаш выбор ? ");

		ch = getchar(); fflush(stdin);

		ch = toupper(ch);

		switch (ch) {

		case 'N': /*if (StackTop)
		{
			printf("Error: сначала надо освободить память!"); break;
		}*/ try
		{
			printf("\nСколько элементов вы хотите добавить?: \n");
			int n;
			scanf("%d", &n);
			if (n < 1 or n > 20) { printf("\nНекорректное число элементов: \n"); break; }
			fflush(stdin);
			printf("\nВведите новые элементы: \n");
			while (n != 0)
			{
				scanf("%d", &Number);
				fflush(stdin);
				Info.Number = Number;
				StackTop = PushElemToStructure(StackTop, Info);
				n--;
			}
			printf("Содержимое списка :\n"); OutputStructure(StackTop);
			fflush(stdin);
			//fflush(stdin);
			break;
		}
		catch(int a)
		{
			printf("\nЯ не вывез такого количсетвва эдементов...((((\n");
		}
		case 'D':
			if (StackTop == NULL) { printf("\nСписок пуст \n"); break; };
			TInfo Info;
			Info = PopElemFromStructure(&StackTop);
			printf("\nМы удалили элемент: %5d\n", Info.Number);
			printf("Содержимое списка :\n"); OutputStructure(StackTop);
			break;

		case 'V':
			printf("Содержимое списка :\n"); OutputStructure(StackTop);
			break;

		case 'I':
			printf("Изначальное содержимое списка :\n"); OutputStructure(StackTop);
			if (StackTop == NULL) { printf("\nСписок пуст \n"); break; }
			printf("\nВведите значение X (значение, после которого нужно вставить новый элемент): \n");
			int X;
			scanf("%d", &X);
			TInfo XInfo; XInfo.Number = X;
			printf("\nВведите значение нового эдемента: \n");
			int m;
			scanf("%d", &m);
			TInfo MInfo; MInfo.Number = m;
			InsertElemAfterX(StackTop, MInfo, XInfo);
			printf("Новое содержимое списка : \n"); OutputStructure(StackTop);
			break;
		case 'C':
			printf("содержимое списка : \n"); OutputStructure(StackTop);
			if (StackTop == NULL) { printf("\nСписок пуст \n"); break; }
			bool containIndential;
			StackTop = CheckForIndential(StackTop, containIndential);
			if (containIndential) printf("В списке есть одинаковые элементы\n");
			else printf("В списке все элементы уникальны\n");
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

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
