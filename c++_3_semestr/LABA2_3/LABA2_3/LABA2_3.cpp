// LABA2_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <string>
#include <vector>
#include <windows.h> // SetConsoleOutputCP, SetConsoleCP
#include <stdio.h> //printf , fgets
#include <conio.h> // getch
#include <string.h> // strcpy, strncmp, strchr
#include <set>

using namespace std;

 vector <int> add_newelem(vector <int>&Massiv)
{
	string newelem_string;
	cin.ignore(0, '\n') >> newelem_string;
	//cout << newelem<<endl;
	try {
		int newelem = stoi(newelem_string);
		//cout << newelem << endl;
		try
		{
			Massiv.push_back(newelem);
			//cout << "элемент добавлен" << endl;
		}
		catch (...)
		{
			cout << "не удалось добавить элемент в структуру";
		}
	}
	catch (...)
	{
		cout << "некорректный ввод" << endl;
		Massiv = add_newelem(Massiv);
	}
	return Massiv;
}

void create_structure(vector <int>& Massiv)
{
	if (!Massiv.empty()) cout << "изначальный массив не пустой, но мы добавим n элементов в него" << endl;
	cout << "Введите количество элементов, которое хотите добавить: " << endl;
	string n_string;
	cin.ignore(0, '\n') >> n_string;
	try {
		int n = stoi(n_string);
		if (n < 1 or n >10)
		{
			cout << "Некорректное число n [1;10]" << endl;
			cin.clear();
			create_structure(Massiv);
			return;
		}
		cout << "Введите элементы, которые хотите добавить: " << endl;
		for (int i = 0; i < n; i++)
		{
			Massiv = add_newelem(Massiv);
		}
		cout << "массив создан" << endl;
	}
	catch (...)
	{
		cout << "некорректный ввод"<< endl;
		create_structure(Massiv);
		return;
	}
	return;

}

void MassivOutput(vector <int> Massiv)
{
	for (int i = 0; i < Massiv.size(); i++)
	{
		cout << Massiv[i] << " ";
	}
	return;
}

void MassivTransformation(vector <int>& Massiv, vector <int> InitialMassiv)
{
	int count_of_null = 0;
	for (int i = 0; i < Massiv.size(); i++)
	{
		if (Massiv[i] == 0)
		{
			count_of_null++;
			//Massiv_of_null.push_back(Massiv[i]);
			Massiv.erase(Massiv.begin() + i);
			i--;
		}
	}
	if (count_of_null > 0)
	{
		for (int i = 0; i < count_of_null; i++) Massiv.push_back(0);
		if (Massiv == InitialMassiv) cout << endl << "Хотя в массиве и были нули, но они все были в конце, поэтому массив не был преобразован";
		else cout << endl << "Ваш массив был преобразован" << endl;
	}
	else cout << endl << "Нулей в массиве нет" << endl;
	return;
}

void main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	vector <int> Massiv;
	create_structure(Massiv);
	vector <int> InitialMassiv;
	InitialMassiv = Massiv;
	cout << "Ваш массив:" << endl;
	MassivOutput(Massiv);
	if (Massiv.size() == 1) { cout << endl <<"Массив из одного элемента, преобразования не имеют смысл"; return; }
	//vector <int> Massiv_of_null;
	MassivTransformation(Massiv, InitialMassiv);
	cout <<endl<< "Ваш массив в итоге: " << endl;
	MassivOutput(Massiv);
	//Massiv = Massiv + Massiv_of_null;
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
