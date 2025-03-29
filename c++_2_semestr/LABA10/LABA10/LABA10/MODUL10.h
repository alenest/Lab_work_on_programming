#pragma once

#include <iostream>

#include <windows.h> // SetConsoleOutputCP, SetConsoleCP

#include <stdio.h> //printf , fgets

#include <conio.h> // getch

#include <string.h> // strcpy, strncmp, strchr

struct TInfo {

	double Number;

};

struct TElem { // моделирование стека на основе односвязного списка

	TInfo Info; // или struct TInfo Info;

	TElem* Next; // или struct TElem *Next; здесь и далее

};

TElem* PushStack(TElem* St, TInfo Info); // добавить элемент в стек

TInfo PopStack(TElem** PSt); //извлечь элемент из стека

//_____________________________________________________________________________________

TElem* CreateNonNegativeStack(int argc, char* argv[], TElem* St);

TElem *CreateNonPositiveStack(int argc, char*argv[], TElem* St);


//----------вторая часть: вывод стека на экран ------

void OutputStack(TElem*& St);

//----------третья часть: решение задачи -------------

TElem* Decide(TElem** PSt1, TElem** PSt2, TElem* St3);

//----------четвертая часть: освобождение памяти -----

TElem* FreeStack(TElem* St);

//---------------------------------------------------------------------------
