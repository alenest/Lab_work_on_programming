// LABA2_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <list>
#include <windows.h> // SetConsoleOutputCP, SetConsoleCP
#include <stdio.h> //printf , fgets
#include <conio.h> // getch
#include <string.h> // strcpy, strncmp, strchr
#include <set>

using namespace std;

list <int> add_newelem(list <int>& Mylist)
{
	string newelem_string;
	cin.ignore(0, '\n') >> newelem_string;
	//cout << newelem<<endl;
	try {
		int newelem = stoi(newelem_string);
		cout << newelem << endl;
		try
		{
			Mylist.push_back(newelem);
			cout << "элемент добавлен" << endl;
		}
		catch (...)
		{
			cout << "не удалось добавить элемент в структуру";
		}
	}
	catch (...)
	{
		cout << "некорректный ввод" << endl;
		Mylist = add_newelem(Mylist);
	}
	return Mylist;
}

void create_structure(list <int>& Mylist)
{
	if (!Mylist.empty()) cout << "изначальный список не пустой, но мы добавим n элементов в него" << endl;
	cout << "Введите количество элементов, которое хотите добавить: " << endl;
	string n_string;
	cin.ignore(0, '\n') >> n_string;
	try {
		int n = stoi(n_string);
		if (n < 1 or n >10)
		{
			cout << "Некорректное число n [1;10]" << endl;
			cin.clear();
			create_structure(Mylist);
			return;
		}
		cout << "Введите элементы, которые хотите добавить: " << endl;
		for (int i = 0; i < n; i++)
		{
			Mylist = add_newelem(Mylist);
		}
		cout << "список создан" << endl;
	}
	catch (...)
	{
		cout << "некорректный ввод";
		create_structure(Mylist);
		return;
	}
	return;

}

void output_strutcture(list <int> Mylist) 
{

	if (Mylist.empty()) { cout << "Списко пуст"; return; }
	else
	{
		cout << "Список: " << endl;
		for (list<int>::iterator it = Mylist.begin(); it != Mylist.end(); ++it)
			cout << *it << endl;
	}
	return;
}

void insert_elem_afterX(list <int> &Mylist)
{
	if (Mylist.empty()) { cout << "Список пуст" << endl; return; }
	cout << "Введите значение нового элемента: ";
	string newelem_string;
	cin.ignore(0, '\n') >> newelem_string;
	//cout << newelem<<endl;
	try {
		int newelem = stoi(newelem_string);
		cout << newelem << endl;
		cout << "Введите значение элемента, после которого нужно вставить новый(после первого соотвествующего): ";

		cin.ignore(0, '\n') >> newelem_string;
		try
		{
			int X = stoi(newelem_string);
			try
			{
				list<int>::iterator itX = find(Mylist.begin(), Mylist.end(), X);
				try 
				{
					Mylist.insert(++itX, newelem);
					cout << "Вставили элемент " << newelem << " после первого элемента со значением " << X << endl;
				}
				catch (...)
				{
					cout << "элемента " << X << " не нашлось" << endl;
					return;
				}
				
			}
			catch (...)
			{
				cout << "элемента " << X <<" не нашлось" << endl;
				return;
			}
		}
		catch (...)
		{
			cout << "некорректный ввод" << endl;
			insert_elem_afterX(Mylist);
			return;
		}
	}
	catch (...)
	{
		cout << "некорректный ввод" << endl;
		insert_elem_afterX(Mylist);
		return;
	}
	return;
}

bool CheckforIdentials(list <int> Mylist)
{
	set <int> numbers;
	for (list<int>::iterator it = Mylist.begin(); it != Mylist.end(); ++it)
	{
		if (numbers.count(*it)) return true;
		numbers.insert(*it);
	}
	return false;

	//while (St)
	//{
	//	inf = PopElemFromStructure(&St);
	//	//printf("%5d\n", inf.Number);
	//	Dop = PushElemToStructure(Dop, inf);
	//	if (numbers.count(inf.Number)) { containIndential = true; }
	//	numbers.insert(inf.Number);
	//}
}

void CheckList(list <int> Mylist)
{
	if (Mylist.empty()) { cout << "список пуст, в нем не может быть идентичных элементов " << endl; }
	else if (Mylist.size() == 1) { cout << "список состоит из 1 элемента, в нем не может быть идентичных элементов " << endl; }
	else if (CheckforIdentials(Mylist)) { cout << "в списке есть идентичные элементы " << endl; }
	else cout << "в списке нет идентичных элементов" << endl;
	return;
}

void main()
{
	char ch;
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	list <int> Mylist;
	do {

		printf("\nN - добавить n элементов в структуру;\nD - удалить первый элемент;\nI - вставить элемент после X;\nC - проверить на наличие одинкаовых элементов;\nV - вывод;\nE - конец.\nВаш выбор ? ");

		ch = getchar(); fflush(stdin);

		ch = toupper(ch);

		switch (ch) {

		case 'N': 
			create_structure(Mylist);
			break;
		case 'D':
			if (Mylist.empty()) { cout << "Список пуст"; }
			else 
			{
				Mylist.erase(Mylist.begin());
				cout << "Первый элемент удалён" << endl;
			}
			
			break;

		case 'V':
			output_strutcture(Mylist);
			break;

		case 'I':
			insert_elem_afterX(Mylist);
			break;
		case 'C':
			CheckList(Mylist);
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
