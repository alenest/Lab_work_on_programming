// LABA9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <windows.h>

bool CheckArr(double* arr, int i, int n)
{
    if (i == n) {return pow(abs(arr[i - 1]) + 1, 1 / 3.) <= i; }
    if(abs(i-n) == 1) return CheckArr(arr, i, n-1) and CheckArr(arr, i + 1, n);
    return CheckArr(arr, i, i + ((n-i+1) / 3) - 1) and CheckArr(arr, i + ((n -i+1)/ 3), n);
}
bool CheckArr2(double* arr, int i, int n)
{
    if (i == n) return pow(abs(arr[i - 1]) + 1, 1 / 3.) <= i;
    if (abs(i - n) == 1)
    {
        if (CheckArr2(arr, i, n - 1)) return CheckArr2(arr, i + 1, n);
        else return false;
    }
    if(CheckArr2(arr, i, i + ((n - i + 1) / 3) - 1)) return CheckArr2(arr, i + ((n - i + 1) / 3), n);
    else return false;
}

void main(int argc, char* argv[])
{
    if (argc < 3) {
        printf("Мало параметров\nPress any key");
        system("pause");
        return;
    }
    FILE* ft = fopen(argv[2], "rt");
    if (ft == NULL) {
        printf("Error: не удалось открыть файл с исходными данными %s\n", argv[2]);
        system("pause");
        return;
    }
    FILE* fw = fopen(argv[1], "wt");
    if (fw == NULL) {
        fclose(ft);
        printf("Error: не удалось открыть файл для записи %s\n", argv[1]);
        system("pause");
        return;
    }
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int N;
    //printf("N - ? "); 
    fscanf(ft, "%d",&N);
    if (N <= 0) { printf("Error: недопустимое значение N\n"); return; };
    double* arr; 
    arr = new double[N];
    for (int i = 0; i < N; i++) fscanf(ft, "%lf", &arr[i]);
    
    if (CheckArr2(arr, 1, N)) { fprintf(fw, "ДА, ВСЕ ЭЛЕМЕНТЫ УДОВЛЕТВОРЯЮТ УСЛОВИЮ"); printf("ДА, ВСЕ ЭЛЕМЕНТЫ УДОВЛЕТВОРЯЮТ УСЛОВИЮ"); }
    else { fprintf(fw, "НЕТ, НЕ ВСЕ ЭЛЕМЕНТЫ УДОВЛЕТВОРЯЮТ УСЛОВИЮ"); printf("НЕТ, НЕ ВСЕ ЭЛЕМЕНТЫ УДОВЛЕТВОРЯЮТ УСЛОВИЮ"); }

    delete[] arr;
    fclose(ft); fclose(fw);
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
