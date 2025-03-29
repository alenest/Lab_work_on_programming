// LABA1_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <windows.h> // SetConsoleOutputCP, SetConsoleCP

#include <stdio.h> //printf , fgets

#include <conio.h> // getch

#include <string.h> // strcpy, strncmp, strchr


void main()
{
    SetConsoleOutputCP(1251);

    SetConsoleCP(1251);

    printf("\nИз скольких элементов будет состоять массив (от 1 до 20): \n");
    int N;
    scanf("%d", &N);
    if (N <1 or N> 20) {
        printf("\nНекорректное число элементов\n"); return;
    }
    int* massiv{ new int[N] };

    printf("\nВаш массив содержит элементы: \n");
    int count_non_null = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &massiv[i]);
        if (massiv[i] != 0) { count_non_null++; }
    }
    int* non_null_massiv{ new int[count_non_null] };
    int j = 0;
    for (int i = 0; i < N; i++)
    {
        if (massiv[i] != 0) { non_null_massiv[j] = massiv[i]; j++; }
    }
    for (int i = 0; i < N;i++)
    {
        if (i < count_non_null)  massiv[i] = non_null_massiv[i];
        else massiv[i] = 0;
    }
    printf("\nПреобразованный массив: \n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", massiv[i]);
    }

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
