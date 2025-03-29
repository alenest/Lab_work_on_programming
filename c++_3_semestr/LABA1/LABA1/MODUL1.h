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

//TElem* CreateStructure(int argc, char* argv[], TElem* St);

TElem* PushElemToStructure(TElem* St, TInfo Info);

TInfo PopElemFromStructure(TElem** St);

//TInfo PopElemFromStack(TElem** PSt); //извлечь элемент из стека

TElem* FreeStructure(TElem* St);

void OutputStructure(TElem*& St);

//TElem* ExitFromStructure(TElem* St);

TElem* SwitchStackToQueue(TElem* St);


//TElem* CreateNonNegativeStack(int argc, char* argv[], TElem* St);
//
//TElem* CreateNonPositiveStack(int argc, char* argv[], TElem* St);
//
//
//void OutputStack(TElem*& St);
//
//TElem* Decide(TElem** PSt1, TElem** PSt2, TElem* St3);



