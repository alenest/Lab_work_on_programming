// LABA6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include "modul6.h"

void main(int argc, char* argv[]) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    if (argc < 3) {
        printf("Мало параметров\nPress any key");
        system("pause");
        return;
    }
    FILE* ft;
    fopen_s(&ft, argv[1], "rt");
    if (ft == NULL) {
        printf("Error: не удалось открыть файл с исходными данными %s\n", argv[1]);
        system("pause");
        return;
    }
    FILE* fw;
    fopen_s(&fw, argv[2], "w");
    if (ft == NULL) {
        printf("Error: не удалось открыть файл для записи %s\n", argv[2]);
        system("pause");
        return;
    }

    int i = 0; //Текущая буква в слове
    bool Is_Number = true; //Только из цифр?
    int Sentence_Length = 0; //Длина предложения
    bool Word_only_numb = false; //Есть ли слово из цифр
    do {
        Current_Char = fgetc(ft); //Считываем символ
        if (strchr(SENTENCE_SEPARATORS, Current_Char) != 0 || strchr(WORDS_SEPARATORS, Current_Char) != 0 || feof(ft)) {
            //Отсекаем слово
            if (i == 0) {
                Is_Number = false;
            }
            if (Is_Number) {
                Word_only_numb = true;
            }
            //printf("\tisNumber: %d\n", Is_Number);
            Is_Number = true;
            Current_Word[i] = '\0';
            Sentence_Length += i;
            i = 0;
        }
        else {
            //Формируем слово
            Current_Word[i] = Current_Char;
            //printf("%c", Current_Char);
            i++;
            if (Is_Number) Is_Number = strchr(ALL_NUMBERS, Current_Char) != 0; //Проверка символа на цифру
            if (i >= MAX_WORD_LENGTH) {
                //Слово длиннее допустимой длины
                Number_Sentence = -1;
                fputs("Word length > ", fw);
                fputs(MAX_WORD_LENGTH_STR, fw);
                break;
            }
        }
        if (strchr(SENTENCE_SEPARATORS, Current_Char) != 0 || feof(fw)) {
            //Отсекаем предложение
            Current_Word[0] = '\0';
            if (Sentence_Length > 0) { //Если полноценное предложение
                Sentence_Count++;
                if (!Word_only_numb) {//Если нет слова из чисел
                    Number_Sentence = Sentence_Count;
                    break;
                }
                //printf("Word_only_numb: %d\n", Word_only_numb);
                //printf("Number_Sentence: %d\n", Number_Sentence);
            }
            i = 0;
            Sentence_Length = 0;
            Is_Number = true;
            Word_only_numb = false;
        }

    } while (!feof(ft));

    //printf("Sentence_Count: %d\n", Sentence_Count);

    if (Number_Sentence != -1) {
        if (Number_Sentence == 0) {
            //Предложение со словом из цифр не найдено
            //fputs("Предложениий без слов из цифр нет", fw);
            printf("Предложениий без слов из цифр нет\n");
        }
        else {
            //Предложение со словом из цифр найдено
            char p[10];
            itoa(Number_Sentence, p, 10);
            fputs("Первое предложение, без слов из цифр: ", fw);
            fputs(p, fw);
            printf("Первое предложение, без слов из цифр: %d\n", Number_Sentence);
        }
    }
    //Закрытие потоков
    fclose(ft);
    fclose(fw);
    system("pause");
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
