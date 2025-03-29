// bit_file_test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>

//struct TRoute {
//	int Number;
//	struct {
//		char FirstStation[30];
//		char IntermediateStations[30];
//		char LastStation[30];
//	} Stations;
//	double AverageTravelTime;
//	double RushHourInterval;
//};

struct test {
	int Number;
	char SLOVO[30];
	char SLOVO2[30];
	int Number2;
};

void CreateBinaryFile(int argc, char* argv[]) {
	if (argc < 3) {
		printf("Мало параметров\nPress any key");
		system("pause");
		return;
	}
	FILE* ft;
	fopen_s(&ft, argv[2], "rt");
	if (ft == NULL) {
		printf("Error: не удалось открыть файл с исходными данными %s\n", argv[2]);
		system("pause");
		return;
	}
	FILE* fb;
	fopen_s(&fb, argv[1], "wb");
	if (fb == NULL) {
		fclose(ft);
		printf("Error: не удалось создать двоичный файл %s\n", argv[1]);
		system("pause");
		return;
	}
	struct test Route; // либо struct TStud Stud; в С
	int kol = 0, nw = 1;
	char* n;
	char s[30];
	while (nw) {
		//fscanf(ft, "%10s", s); Route.Number = atoi(s);
		fgets(s, 30, ft);
		fflush(ft);
		n = strchr(s, '\n');
		if (n) s[n - s] = '\0';
		Route.Number = atoi(s);
		
		//printf("\n\n%d ", Route.Number);
		
		fgets(Route.SLOVO, 30, ft);
		fflush(ft);
		n = strchr(Route.SLOVO, '\n');
		if (n) Route.SLOVO[n - Route.SLOVO] = '\0';
		//fscanf(ft, "%30s", Route.SLOVO);
		//printf("%s", Route.SLOVO);
		
		
		fgets(Route.SLOVO2, 30, ft);
		fflush(ft);
		n = strchr(Route.SLOVO2, '\n');
		if (n) Route.SLOVO2[n - Route.SLOVO2] = '\0';

		fgets(s, 30, ft);
		fflush(ft);
		n = strchr(s, '\n');
		if (n) s[n - s] = '\0';
		Route.Number2 = atoi(s);

		printf("\n%d и %s и %s и %d", Route.Number, Route.SLOVO, Route.SLOVO2, Route.Number2);

		nw = fwrite(&Route, sizeof(Route), 1, fb);
		kol++;
		if (strcmp(Route.SLOVO, "**") == 0 || feof(ft)) break;
		//if (feof(ft)) nw = NULL;
		//if (feof(ft)) nw = -1;
	}
	if (nw != 1) printf("Error: Ошибка при записи");
	fclose(ft);
	fclose(fb);
	printf("\nСоздан двоичный файл из %d записей по %d байт\n", kol, sizeof(test));
	//printf("Press any key to continue");
	//getch();
	system("pause");
	return;
}

char* ANSIUpperCase(char* s, char* S) {
	S = strcpy(S, s);
	char* ch = S;
	while (*ch) {
		if (*ch >= 'a' && *ch <= 'z' || *ch >= 'а' && *ch <= 'я') *ch =
			*ch - 32;
		if (*ch == 'ё') *ch = 'Ё';
		ch++;
	}
	return S;
}

int main(int argc, char* argv[])
{
	SetConsoleOutputCP(1251);
	char s[30];
	scanf("%s", s);
	char S[30];
	ANSIUpperCase(s, S);
	printf("%s", S);

	//CreateBinaryFile(argc, argv);
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
