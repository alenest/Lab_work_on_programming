#pragma once

#include <iostream>
#include <windows.h>

#include <stdio.h>
#include <conio.h>
#include <locale.h>

using namespace std;

const int MAX_WORD_LENGTH = 50; //������������ ����� �����
const char* MAX_WORD_LENGTH_STR = "50"; //������������ ����� ����� (������)
const char* ALL_NUMBERS = "0123456789"; //��� �����
const char* SENTENCE_SEPARATORS = ".!?"; //����������� �����������
const char* WORDS_SEPARATORS = " ,:;\n\r\t"; //����������� ����


unsigned char Current_Char; //������� ������
int Sentence_Count = 0, Number_Sentence = 0; //���������� �����������, ����� ���������� ����������� ��� ����� �� ����
char Current_Word[MAX_WORD_LENGTH + 1] = ""; //������� �����
