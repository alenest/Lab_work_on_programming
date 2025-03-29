#pragma once

#include <iostream>

#include <windows.h> // SetConsoleOutputCP, SetConsoleCP

#include <stdio.h> //printf , fgets

#include <conio.h> // getch

#include <string.h> // strcpy, strncmp, strchr

struct TInfo {

	double Number;

};

struct TElem { // ������������� ����� �� ������ ������������ ������

	TInfo Info; // ��� struct TInfo Info;

	TElem* Next; // ��� struct TElem *Next; ����� � �����

};

TElem* PushStack(TElem* St, TInfo Info); // �������� ������� � ����

TInfo PopStack(TElem** PSt); //������� ������� �� �����

//_____________________________________________________________________________________

TElem* CreateNonNegativeStack(int argc, char* argv[], TElem* St);

TElem *CreateNonPositiveStack(int argc, char*argv[], TElem* St);


//----------������ �����: ����� ����� �� ����� ------

void OutputStack(TElem*& St);

//----------������ �����: ������� ������ -------------

TElem* Decide(TElem** PSt1, TElem** PSt2, TElem* St3);

//----------��������� �����: ������������ ������ -----

TElem* FreeStack(TElem* St);

//---------------------------------------------------------------------------
