// LABA2_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Modul1.h"

using namespace std;


stack <double> add_newelem(stack <double>& St)
{
	string newelem_string;
	cin.ignore(0, '\n') >> newelem_string;
	//cout << newelem<<endl;
	try {
		double newelem = stod(newelem_string);
		cout << newelem << endl;
		try
		{
			St.push(newelem);
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
		St = add_newelem(St);
	}
	return St;
}

queue <double> add_newelem(queue <double>& Que)
{
	string newelem_string;
	cin.ignore(0, '\n') >> newelem_string;
	//cout << newelem<<endl;
	try {
		double newelem = stod(newelem_string);
		cout << newelem << endl;
		try
		{
			Que.push(newelem);
			cout << "элемент добавлен в очередь" << endl;
		}
		catch (...)
		{
			cout << "не удалось добавить элемент в очередь";
		}
	}
	catch (...)
	{
		cout << "некорректный ввод" << endl;
		Que = add_newelem(Que);
	}
	return Que;
}

void create_structure(stack <double>& St)
{
	if (!St.empty()) cout << "изначальный стек не пустой, но мы добавим n элементов в него"<<endl;
	cout << "Введите количество элементов, которое хотите добавить: " << endl;
	string n_string;
	cin.ignore(0, '\n') >> n_string;
	try {
		int n = stoi(n_string);
		if (n < 1 or n >10)
		{
			cout << "Некорректное число n [1;10]" << endl;
			cin.clear();
			create_structure(St);
			return;
		}
		cout << "Введите элементы, которые хотите добавить: " << endl;
		for (int i = 0; i < n; i++)
		{
			St = add_newelem(St);
		}
		cout << "стек создан" << endl;
	}
	catch (...)
	{
		cout << "некорректный ввод";
		create_structure(St);
		return;
	}
	return;
	/*int n; cin.ignore(0, '\n') >> n; 
	if (n < 1 or n >10)
	{
		cout << "Некорректное число n [1;10]" << endl;
		create_structure(St);
		return;
	}
	cout << "Введите элементы, которые хотите добавить: " << endl;
	for (int i = 0; i < n; i++)
	{
		St = add_newelem(St);
	}
	cout << "стек создан" << endl;*/
}

void create_structure(queue <double>& Que)
{
	if (!Que.empty()) cout << "изначальная очередь не пустая, но мы добавим n элементов в неё" << endl;
	cout << "Введите количество элементов, которое хотите добавить: " << endl;
	string n_string;
	cin.ignore(0, '\n') >> n_string;
	try {
		int n = stoi(n_string);
		if (n < 1 or n >10)
		{
			cout << "Некорректное число n [1;10]" << endl;
			cin.clear();
			create_structure(Que);
			return;
		}
		cout << "Введите элементы, которые хотите добавить: " << endl;
		for (int i = 0; i < n; i++)
		{
			Que = add_newelem(Que);
		}
		cout << "очередь создана" << endl;
	}
	catch (...)
	{
		cout << "некорректный ввод";
		create_structure(Que);
		return;
	}
	return;
	/*int n; cin.ignore(0, '\n') >> n;
	if (n < 1 or n >10)
	{
		cout << "Некорректное число n [1;10]" << endl;
		create_structure(Que);
		return;
	}
	cout << "Введите элементы, которые хотите добавить: " << endl;
	for (int i = 0; i < n; i++)
	{
		Que = add_newelem(Que);
	}
	cout << "стек создан" << endl;*/
}

void output_strutcture(stack <double> St) {

	if (St.empty()) { cout << "структура пуста"; return; }
	else
	{
		cout << "Стек: " << endl;
		stack<char> TempSt;
		while (!St.empty()) {
			cout << St.top() << endl;
			TempSt.push(St.top());
			St.pop();
		}
		while (!TempSt.empty()) {
			St.push(TempSt.top());
			TempSt.pop();
		}
	}
	return;
}

void output_strutcture(queue <double> Que) {

	if (Que.empty()) { cout << "структура пуста"; return; }
	else
	{
		cout << "Очередь: " << endl;
		queue <char> TempQue;
		while (!Que.empty()) {
			cout << Que.front() << endl;
			TempQue.push(Que.front());
			Que.pop();
		}
		while (!TempQue.empty()) {
			Que.push(TempQue.front());
			TempQue.pop();
		}
		cout << endl;
	}
	return;
}

void free_structure(stack <double> St)
{
	if (St.empty()) {
		cout << "Стек пуст"; return;
	}
	else
	{
		while (!St.empty()) {
			St.pop();
		}
		cout << "Вся память под стек освобождена" << endl;
	}
	return;
}

void free_structure(queue <double> Que)
{
	if (Que.empty()) {
		cout << "Очередь пуста"; return;
	}
	else
	{
		while (!Que.empty()) {
			Que.pop();
		}
		cout << "Вся память под очередь освобождена" << endl;
	}
	return;
}

//queue<char> stack_to_queue(stack<char> st, queue<char> que) {
//	if (!st.empty()) {
//		while (!st.empty()) {
//			que.push(st.top());
//			st.pop();
//		}
//		cout << "Стек преобразован в очередь" << endl;
//	}
//	else {
//		cout << "Стек пуст" << endl;
//	}
//	return que;
//}
queue <double> SwitchStackToQueue(stack <double>& St)
{
	queue <double> Que;
	if (St.empty())
	{
		cout << "Стек пуст" << endl;
	}
	else
	{
		
		while (!St.empty()) 
		{
			Que.push(St.top());
			St.pop();
		}
		cout << "Стек был преобразован в очередь. Изначальный стек теперь пуст" << endl;
	}
	return Que;
}


void main()
{
	char ch;
	string newelem_string;

	stack <double> St;
	queue <double> Que;
	//stack <double> St;

	SetConsoleOutputCP(1251);

	SetConsoleCP(1251);

	do {

		printf("\nC - сформировать стек из n элементов;\nс - сформировать очередь из n элементов;\nN - добавить элемент в стек;\nn - добавить элемент в очередь;\nV - вывод стека\nv - вывод очереди;\nD - удалить элемент из стека;\nd - удалить элемент из очереди;\nF - освободить память стека;\nf - освободить память очереди;\nS - преобразовать стек в очередь;\nE - конец.\nВаш выбор ? ");

		ch = getchar(); fflush(stdin);

		//ch = toupper(ch);

		switch (ch) {

		case 'C':
			create_structure(St);
			break;
		case 'c':
			create_structure(Que);
			break;

		case 'N':
			cout << "\nВведите значение нового элемента стека: \n";
			St = add_newelem(St);
			break;
		case 'n':
			cout << "\nВведите значение нового элемента очереди: \n";
			Que = add_newelem(Que);
			break;
		case 'V':
			//printf("Содержимое структуры :\n"); OutputStructure(StackTop);
			//cout << "содержимое стека: "<<endl;
			output_strutcture(St);
			break;
		case 'v':
			//cout << "содержимое очереди: " << endl;
			output_strutcture(Que);
			break;
		case 'D':
			if (St.empty()) cout << "Стек пуст";
			else
			{
				St.pop();
				cout << "элемент удален" << endl;
			}
			break;
		case 'd':
			if (Que.empty()) cout << "Очередь пуста";
			else
			{
				Que.pop();
				cout << "элемент удален" << endl;
			}
			break;
		case 'F':
			free_structure(St);
			break;
		case 'f':
			free_structure(Que);
			break;

		case 'S':
			if (!Que.empty())
			{
				cout << "так как очерель не пуста перед преобразованием стека в очередь мы ее освободим" << endl;
				free_structure(Que);
			}
			Que = SwitchStackToQueue(St);
			//printf("\nСтек преобразован в очередь\n");
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


//void main()
//{
//	SetConsoleOutputCP(1251);
//	SetConsoleCP(1251);
//
//    stack <double> St;
//	string input;
//
//	double elem;
//	cin.ignore(6, '\n') >>elem;
//
//	cout << elem;
//
//	return;
//}
/*void main()
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
		}
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
