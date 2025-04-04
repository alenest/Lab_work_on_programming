﻿// LABA7again.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include "modul7.h"

int main(int argc, char* argv[])
{
	char ch;
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	do {
		printf("N - создать новый тип.файл;\nF - сразу поиск;\nC - коррекция;\nP - вывести все записи из двоичного файла\nE - конец.\nВаш выбор?");
		//ch = getchar();
		ch = getchar(); fflush(stdin);
		ch = toupper(ch);
		switch (ch) {
			//----------первая часть: создание двоичного из текстового
		case 'N': CreateBinaryFile(argc, argv); break;
			//-------------- вторая часть: поиск в двоичном файле ----
		case 'F': FindRoute(argc, argv); break;
			//-------третья часть: корректировка в двоичном файле ----
		case 'C': CorrectFile(argc, argv); break;
			//-------четвертая часть: вывод записей из двоичного файла ----
		case 'P': RouteOutput(argc, argv); break;
			//-----------выход----------------------------------------
		case 'E': return 0;
			//--------------------------------------------------------
		default:
			printf("Нет такой команды\n");
			getchar();
			//system("pause");
			//getch();
		}
	} while (ch != 'E');
	return 0;
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
