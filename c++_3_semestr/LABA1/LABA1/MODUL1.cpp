#include "MODUL1.h"

TElem* PushElemToStructure(TElem* St, TInfo Info)
{
	TElem* PElem = new TElem;

	PElem->Info.Number = Info.Number;

	PElem->Next = St;

	return PElem; // Адрес новой вершины
}

//TElem* PopElemFromStructure(TElem* PSt)
//{
//	TElem* Elem = PSt;
//
//	//TInfo Info = Elem->Info;
//
//	PSt = Elem->Next;
//
//	delete Elem;
//
//	return PSt;
//
//	//return Info;
//}

TInfo PopElemFromStructure(TElem** PSt) { //извлечь элемент из стека

	TElem* Elem = *PSt;

	TInfo Info = Elem->Info;

	*PSt = Elem->Next;

	delete Elem;

	return Info;

}

TElem* FreeStructure(TElem* St) {

	TInfo Info;

	while (St) {

		Info = PopElemFromStructure(&St);

	}
	return St;

}

void TopToTop(TElem** PSt1, TElem** PSt2) {

	TElem* Elem, * StTop = *PSt1, * Dop = *PSt2;

	Elem = StTop;

	StTop = StTop->Next; // или StTop=(*StTop).Next;

	Elem->Next = Dop;

	Dop = Elem;

	*PSt1 = StTop; *PSt2 = Dop; // сохранить новые адреса вершин по адресам PSt1 и PSt2

	return;

}

void OutputStructure(TElem*& St) {

	TElem* Dop = NULL;
	TInfo inf;
	if (!St) printf("пустой\n");
	while (St) {

		inf = PopElemFromStructure(&St);
		printf("%5.2lf\n", inf.Number);
		//printf("%30s %3d\n", inf.FamIO, inf.Ball);
		Dop = PushElemToStructure(Dop, inf);
	}
	while (Dop) TopToTop(&Dop, &St);// printf("Press any key to continue");
	//getchar();
	return;
}

TElem* SwitchStackToQueue(TElem* St)
{
	if (St == NULL) return St;
	TElem* Current = St;
	if (Current->Next == NULL) return St;

	TElem* Next = Current->Next;
	Current->Next = NULL;
	TElem* Previous = NULL;
	while (Next != NULL)
	{
		Previous = Current;
		Current = Next;
		Next = Current->Next;
		Current->Next = Previous;
	}
	//Current->Next = Previous;
	//St = Current;
	return Current;
}


