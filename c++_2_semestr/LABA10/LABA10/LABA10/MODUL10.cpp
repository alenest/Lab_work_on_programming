#define _CRT_SECURE_NO_WARNINGS

#include "MODUL10.h"


TElem* PushStack(TElem* St, TInfo Info) { // добавить элемент в стек

	TElem* Elem = new TElem;

	Elem->Info.Number = Info.Number;

	//strcpy(Elem->Info.FamIO, Info.FamIO);

	Elem->Next = St;

	return Elem; // јдрес новой вершины

}

TInfo PopStack(TElem** PSt) { //извлечь элемент из стека

	TElem* Elem = *PSt;

	TInfo Info = Elem->Info;

	*PSt = Elem->Next;

	delete Elem;

	return Info;

}

// дополнительна€ процедура перекладывани€ элемента из одного стека (StTop) в другой(Dop)

void TopToTop(TElem** PSt1, TElem** PSt2) {

	TElem* Elem, * StTop = *PSt1, * Dop = *PSt2;

	Elem = StTop;

	StTop = StTop->Next; // или StTop=(*StTop).Next;

	Elem->Next = Dop;

	Dop = Elem;

	*PSt1 = StTop; *PSt2 = Dop; // сохранить новые адреса вершин по адресам PSt1 и PSt2

	return;

}

TElem* CreateNonNegativeStack(int argc, char* argv[], TElem* St)
{
	FILE* ft = fopen(argv[1], "rt");
	int kol = 0;
	double num;
	TInfo Info;
	struct stat finfo;
	if (fstat(_fileno(ft), &finfo)) printf("fail");
	else off_t pngDataLength = finfo.st_size;
	while (finfo.st_size != 0)
	{
		fscanf(ft, "%lf", &num);
		if (feof(ft)) break;
		if (num >= 0) {
			Info.Number = num;
			St = PushStack(St, Info);
			kol++;
			//if (feof(ft)) break;
		}
	}
	printf("—оздан стек из %d неотрицательных чисел\n", kol);
	fclose(ft);
	return St;
}

TElem* CreateNonPositiveStack(int argc, char* argv[], TElem* St)
{
	FILE* ft = fopen(argv[2], "rt");
	int kol = 0;
	double num;
	TInfo Info;
	//struct stat finfo;
	struct stat finfo;
	if (fstat(_fileno(ft), &finfo)) printf("fail");
	else off_t pngDataLength = finfo.st_size;
	while (finfo.st_size != 0)
	{
		fscanf(ft, "%lf", &num);
		if (feof(ft)) break;
		if (num <= 0) {
			Info.Number = num;
			St = PushStack(St, Info);
			kol++;
			//if (feof(ft)) break;
		}
	}
	printf("—оздан стек из %d неположительных чисел\n", kol);
	fclose(ft);
	return St;
}

//----------втора€ часть: вывод стека на экран ------

void OutputStack(TElem*& St) {

	TElem* Dop = NULL;
	TInfo inf;
	if (!St) printf("пустой\n");
	while (St) {

		inf = PopStack(&St);
		printf("%5.2lf\n", inf.Number);
		//printf("%30s %3d\n", inf.FamIO, inf.Ball);
		Dop = PushStack(Dop, inf);
	}
	while (Dop) TopToTop(&Dop, &St);// printf("Press any key to continue");
	//getchar();
	return;
}

TElem* Decide(TElem** PSt1, TElem** PSt2, TElem* St3)
{
	TElem *St1 = *PSt1, *St2 = *PSt2 ,*Dop = NULL;
	St3 = FreeStack(St3);
	int countpair = 0, countstack1 = 0, countstack2 = 0;
	while (St1 && St2) 
	{
		
			//if (St1->Info.Number !=0) St3 = PushStack(St3, St1->Info);
			St3 = PushStack(St3, St1->Info);
			//if (St2->Info.Number != 0) St3 = PushStack(St3, St2->Info);
			St3 = PushStack(St3, St2->Info);
			TopToTop(&St1, &Dop);
			TopToTop(&St2, &Dop);
			countpair++;
	}
	while (St1)
	{
		//if (St1->Info.Number != 0) St3 = PushStack(St3, St1->Info);
		St3 = PushStack(St3, St1->Info);
		TopToTop(&St1, &Dop);
		countstack1++;
	}
	while (St2)
	{
		//if (St1->Info.Number != 0) St3 = PushStack(St3, St1->Info);
		St3 = PushStack(St3, St2->Info);
		TopToTop(&St2, &Dop);
		countstack2++;
	}
	for(int i = 0; i < countstack2; i++) TopToTop(&Dop, &St2);
	for (int i = 0; i < countstack1; i++) TopToTop(&Dop, &St1);
	for (int i = 0; i < countpair; i++) { TopToTop(&Dop, &St2); TopToTop(&Dop, &St1);}

	printf("—тек неотрицательных чисел:\n"); OutputStack(St1);
	printf("—тек неположительных чисел:\n"); OutputStack(St2);
	printf("Ќовый стек поочередно вз€тых чисел:\n"); OutputStack(St3);

	while(St3)
	{
		if (St3->Info.Number == 0) PopStack(&St3);
		else TopToTop(&St3, &Dop);
	}
	//while (Dop) TopToTop(&Dop, &St3);
	printf("Ќовый стек чисел без нулей:\n"); OutputStack(St3);

	*PSt1 = St1; // новый адрес через параметр (изменение по адресу)
	*PSt2 = St2;
	return Dop; // новый адрес через результат функции вернетс€
}

//----------треть€ часть: решение задачи -------------

//TElem* Decide(TElem** PSt1, TElem* St2) {
//
//	TElem* St1 = *PSt1, * Dop = NULL;
//
//	St2 = FreeStack(St2);
//
//	int Sum = 0, N = 0;
//
//	while (St1) {
//
//		Sum += St1->Info.Ball;
//
//		N++;
//
//		if (St1->Info.Ball >= 85) St2 = PushStack(St2, St1->Info); // отличники
//
//		TopToTop(&St1, &Dop);
//
//	}
//
//	while (Dop) TopToTop(&Dop, &St1);
//
//	if (N) printf("—редний балл = %6.2f\n", (float)Sum / N);
//
//	else printf("—тек пуст\n");
//
//	printf("Press any key to continue");
//
//	getchar();
//
//	*PSt1 = St1; // новый адрес через параметр (изменение по адресу)
//
//	return St2; // новый адрес через результат функции вернетс€
//
//}

//----------четверта€ часть: освобождение пам€ти -----

TElem* FreeStack(TElem* St) {

	TInfo Info;

	while (St) {

		Info = PopStack(&St);

	}

	return St;

}
