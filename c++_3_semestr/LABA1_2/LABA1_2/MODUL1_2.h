#pragma once

#include <iostream>

#include <windows.h> // SetConsoleOutputCP, SetConsoleCP

#include <stdio.h> //printf , fgets

#include <conio.h> // getch

#include <string.h> // strcpy, strncmp, strchr

#include <set>

struct TInfo {

	int Number;

};

struct TElem { // ������������� ����� �� ������ ������������ ������

	TInfo Info; // ��� struct TInfo Info;

	TElem* Next; // ��� struct TElem *Next; ����� � �����

};

TInfo PopElemFromStructure(TElem** PSt);

TElem* PushElemToStructure(TElem* St, TInfo Info);

void OutputStructure(TElem*& St);

void InsertElemAfterX(TElem*& St, TInfo Info, TInfo X);

TElem* CheckForIndential(TElem* St, bool &containIndential);

