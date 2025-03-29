#pragma once

#include <iostream>
#include <windows.h>

#include <stdio.h>
#include <conio.h>
#include <locale.h>

using namespace std;

const int MAX_WORD_LENGTH = 50; //Максимальная длина слова
const char* MAX_WORD_LENGTH_STR = "50"; //Максимальная длина слова (строка)
const char* ALL_NUMBERS = "0123456789"; //Все цифры
const char* SENTENCE_SEPARATORS = ".!?"; //Разделители предложений
const char* WORDS_SEPARATORS = " ,:;\n\r\t"; //Разделители слов


unsigned char Current_Char; //Текущий символ
int Sentence_Count = 0, Number_Sentence = 0; //Количество предложений, номер последнего предложения без слова из цифр
char Current_Word[MAX_WORD_LENGTH + 1] = ""; //Текущее слово
