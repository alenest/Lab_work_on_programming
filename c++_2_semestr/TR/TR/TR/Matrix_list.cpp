#define _CRT_SECURE_NO_WARNINGS

#include "Matrix_list.h"

bool isMatrixEmpty(TMatrix* Matrix)
{
    if (Matrix->HeadElem == nullptr) return true;
    else return false;
}

bool MatrixMemoryAllocation(TMatrix* Matrix, int N, int M)
{
    //если переданы некорректные параметры для строчек или столбцов, то возвращаем false(мы не выделили память)
    if (N < 1 or M < 1) return false;
    //если матрица не является пустой, то память не выделяем
    if (!isMatrixEmpty(Matrix)) return false;
    //Matrix = (TMatrix*)malloc(sizeof(TMatrix));
    TMatrixElem* PElem1;
    PElem1 = (TMatrixElem*)malloc(sizeof(TMatrixElem));
    //Matrix = PElem1;
    //TMatrix Mat; 
    Matrix->HeadElem = PElem1;
    Matrix->CurrentElem = PElem1;
    //создаем первый столбец из N строк (если N строк больше одной)
    printf("[%d][%d]\n", N , M);
    printf("Создали a[1][1]\n");
    printf("первый столбец\n");
    if (N > 1)
    {
        for (int i = 2; i <= N; i++)
        {
            TMatrixElem* PElem2;
            PElem2 = (TMatrixElem*)malloc(sizeof(TMatrixElem));
            PElem2->NextLineElem = nullptr;
            PElem2->NextColumnElem = nullptr;
            PElem1->NextLineElem = PElem2;
            PElem1 = PElem2;
            printf("Создали a[%d][1]\n", i);
        }
    }
    printf("Первый стобец сформирован\n");
    //создаем последующие столбцы, если стобцов больше чем 1
    if (M > 1)
    {
        TMatrixElem* FirstElemOfPreviousColumn = Matrix->HeadElem;
        for (int j = 2; j <= M; j++)
        {
            TMatrixElem* PreviousColumnElem = FirstElemOfPreviousColumn;
            FirstElemOfPreviousColumn = PreviousColumnElem;
            TMatrixElem* PreviousLineElem;
            PreviousLineElem = (TMatrixElem*)malloc(sizeof(TMatrixElem));
            for (int i = 1; i <= N; i++)
            {
                TMatrixElem* CurrentElem;
                CurrentElem = (TMatrixElem*)malloc(sizeof(TMatrixElem));
                CurrentElem->NextLineElem = nullptr;
                CurrentElem->NextColumnElem = nullptr;
                PreviousLineElem->NextLineElem = CurrentElem;
                PreviousColumnElem->NextColumnElem = CurrentElem;
                PreviousLineElem = CurrentElem;
                PreviousColumnElem = PreviousColumnElem->NextLineElem;
                printf("Создали a[%d][%d]\n", i, j);
            }
            printf("Создали столбец\n");
        }
    }
    return true;
}

bool AddMatrixColumn(TMatrix* Matrix)
{
    //если матрица является пустой, то столбец не добавляем
    if (isMatrixEmpty(Matrix)) return false;
    TMatrixElem* CurrentElem = Matrix->HeadElem;
    //доходим до последнего элемента 1 строки
    while (CurrentElem->NextColumnElem != nullptr) 
    { 
        CurrentElem = CurrentElem->NextColumnElem; 
    }
    TMatrixElem* PreviousColumnElem = CurrentElem->NextLineElem;
    //первый элемент нового столбца
    TMatrixElem* NewElem;
    NewElem = (TMatrixElem*)malloc(sizeof(TMatrixElem));
    NewElem->NextLineElem = nullptr;
    NewElem->NextColumnElem = nullptr;
    TMatrixElem* PreviousLineElem = NewElem;

    while (PreviousColumnElem->NextLineElem != nullptr)
    {
        TMatrixElem* NextElem;
        NextElem = (TMatrixElem*)malloc(sizeof(TMatrixElem));
        NextElem->NextLineElem = nullptr;
        NextElem->NextColumnElem = nullptr;
        PreviousLineElem->NextLineElem = NextElem;
        PreviousColumnElem->NextColumnElem = NextElem;
        PreviousColumnElem = PreviousColumnElem->NextLineElem;
    }
    return true;
}

bool AddMatrixLine(TMatrix* Matrix)
{
    //если матрица является пустой, то строку не добавляем
    if (isMatrixEmpty(Matrix)) return false;
    TMatrixElem* CurrentElem = Matrix->HeadElem;
    //доходим до последнего элемента 1 столбца
    while (CurrentElem->NextLineElem != nullptr)
    {
        CurrentElem = CurrentElem->NextLineElem;
    }
    TMatrixElem* PreviousLineElem = CurrentElem->NextColumnElem;
    //первый элемент новой строки
    TMatrixElem* NewElem;
    NewElem = (TMatrixElem*)malloc(sizeof(TMatrixElem));
    NewElem->NextLineElem = nullptr;
    NewElem->NextColumnElem = nullptr;
    TMatrixElem* PreviousColumnElem = NewElem;

    while (PreviousLineElem->NextColumnElem != nullptr)
    {
        TMatrixElem* NextElem;
        NextElem = (TMatrixElem*)malloc(sizeof(TMatrixElem));
        NextElem->NextLineElem = nullptr;
        NextElem->NextColumnElem = nullptr;
        PreviousLineElem->NextLineElem = NextElem;
        PreviousColumnElem->NextColumnElem = NextElem;
        PreviousLineElem = PreviousLineElem->NextColumnElem;
    }
    return true;
}

void ClearMatrix(TMatrix* Matrix)
{
    if (isMatrixEmpty(Matrix)) return;
    TMatrixElem* CurrentElem = Matrix->HeadElem;
    TMatrixElem* NextColumnElem = CurrentElem->NextColumnElem;
    TMatrixElem* NextLineElem;
    while (CurrentElem->NextColumnElem != nullptr)
    {
        while (CurrentElem->NextLineElem != nullptr)
        {
            NextLineElem = CurrentElem->NextLineElem;
            free(CurrentElem);
            CurrentElem = NextLineElem;
        }
        free(CurrentElem);
        CurrentElem = NextColumnElem;
        NextColumnElem = CurrentElem->NextColumnElem;
    }
    Matrix->HeadElem = nullptr;
    Matrix->CurrentElem = nullptr;
    free(Matrix);
    Matrix = nullptr;
    return;
}

bool GoTo_i_Line(TMatrix* Matrix, int i)
{
    if (isMatrixEmpty(Matrix)) return false;
    //если позицию невозможно изменить, то возвращаем false
    if (i < 1)  return false; 
    TMatrixElem* Elem = Matrix->HeadElem;
    for (int ii = 1; ii <= i; ii++)
    {
        //если параметр i оказался больше количества строк, то текущую позицию не меняем, возвращаем false
        if (Elem->NextLineElem == nullptr && ii != i) return false;
        //дошли до нужной строки, меняем текущую позицию
        else if (ii = i) { Matrix->CurrentElem = Elem; return true;};
        Elem = Elem->NextLineElem;
    }
    return true;
}

bool GoTo_j_Column(TMatrix* Matrix, int j)
{
    if (isMatrixEmpty(Matrix)) return false;
    //если позицию невозможно изменить, то возвращаем false
    if (j < 1)  return false;
    TMatrixElem* Elem = Matrix->HeadElem;
    for (int jj = 1; jj <= j; jj++)
    {
        //если параметр j оказался больше количества столбцов, то текущую позицию не меняем, возвращаем false
        if (Elem->NextLineElem == nullptr && jj != j) return false;
        //дошли до нужного столбца, меняем текущую позицию
        else if (jj = j) { Matrix->CurrentElem = Elem; return true; };
        Elem = Elem->NextLineElem;
    }
    return true;
}

bool GoToNextColumnElem(TMatrix* Matrix)
{
    if (isMatrixEmpty(Matrix)) return false;
    //если в этом столбце нет больше элементов, то позицию не меняем
    if (Matrix->CurrentElem->NextColumnElem == nullptr) return false;
    Matrix->CurrentElem = Matrix->CurrentElem->NextColumnElem;
    return true;
}

bool GoToNextLineElem(TMatrix* Matrix)
{
    if (isMatrixEmpty(Matrix)) return false;
    //если в этой строке нет больше элементов, то позицию не меняем
    if (Matrix->CurrentElem->NextLineElem == nullptr) return false;
    Matrix->CurrentElem = Matrix->CurrentElem->NextLineElem;
    return true;
}

//bool GoToNextElem(TMatrix* Matrix)
//{
//    if (isMatrixEmpty(Matrix)) return false;
//    if (Matrix->CurrentElem->NextLineElem == nullptr && Matrix->CurrentElem->NextColumnElem == nullptr) return false;
//    if ()
//}

bool ReadValueOfCurrentElem(TMatrix* Matrix, TElemValue& Value)
{
    if (isMatrixEmpty(Matrix)) return false;
    Value = Matrix->CurrentElem->ElemValue; return true;
}

bool ChangeValueOfCurrenElem(TMatrix* Matrix, TElemValue Value)
{
    if (isMatrixEmpty(Matrix)) return false;
    Matrix->CurrentElem->ElemValue = Value; return true;
}

bool ChangeValueOfMatrixElem(TMatrix* Matrix, int i, int j, TElemValue Value)
{
    if (isMatrixEmpty(Matrix)) return false;
    //TMatrixElem* Elem = Matrix->HeadElem;
    TMatrix* MatrixClone;
    MatrixClone = (TMatrix*)malloc(sizeof(TMatrix));
    MatrixClone = Matrix;
    MatrixClone->CurrentElem = Matrix->HeadElem;
    //возвращаем false если передано некорректное количество строчек
    if (!GoTo_i_Line(MatrixClone, i)) return false;
    for (int jj = 1; jj <= j; jj++)
    {
        //возвращаем false если передано некорректное количество столбцов
        if (!GoToNextColumnElem(MatrixClone)) return false;
    }
    MatrixClone->CurrentElem->ElemValue = Value;
    return true;
}

bool ReadValueOfMatrixElem(TMatrix* Matrix, int i, int j, TElemValue& Value)
{
    if (isMatrixEmpty(Matrix)) return false;
    //TMatrixElem* Elem = Matrix->HeadElem;
    TMatrix* MatrixClone = Matrix;
    MatrixClone->CurrentElem = Matrix->HeadElem;
    //возвращаем false если передано некорректное количество строчек
    if (!GoTo_i_Line(MatrixClone, i)) return false;
    for (int jj = 1; jj <= j; jj++)
    {
        //возвращаем false если передано некорректное количество столбцов
        if (!GoToNextColumnElem(MatrixClone)) return false;
    }
    Value = MatrixClone->CurrentElem->ElemValue;
    return true;
}

void MatrixOutput(FILE* f, TMatrix* Matrix)
{
    if (isMatrixEmpty(Matrix))
    {
        fprintf(f, "\nматрица пустая\n");
        return;
    }
    TMatrixElem* Elem = Matrix->HeadElem;
    TMatrix* MatrixClone = Matrix;
    printf("\nВыводим\n");
    int i = 1;
    while (Elem->NextColumnElem != nullptr && Elem->NextLineElem != nullptr)
    {
        if (Elem->NextLineElem != nullptr)
        {
            int Value = Elem->ElemValue.Value;
            fprintf(f, "%d ", Value);
            printf("%d ", Value);
            Elem = Elem->NextLineElem;
        }
        else
        {
            int Value = Elem->ElemValue.Value;
            fprintf(f, "%d\n", Value);
            printf("%d ", Value);
            i++;
            GoTo_i_Line(MatrixClone, i);
        }
    }
}



