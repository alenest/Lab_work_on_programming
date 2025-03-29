#include "MODUL1_2.h"

TElem* PushElemToStructure(TElem* St, TInfo Info)
{
	TElem* PElem = new TElem;

	PElem->Info.Number = Info.Number;

	PElem->Next = St;

	return PElem; // Адрес новой вершины
}

TInfo PopElemFromStructure(TElem** PSt) { //извлечь элемент из стека

	TElem* Elem = *PSt;

	TInfo Info = Elem->Info;

	*PSt = Elem->Next;

	delete Elem;

	return Info;

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
		printf("%5d\n", inf.Number);
		//printf("%30s %3d\n", inf.FamIO, inf.Ball);
		Dop = PushElemToStructure(Dop, inf);
	}
	while (Dop) TopToTop(&Dop, &St);// printf("Press any key to continue");
	//getchar();
	return;
}

void InsertElemAfterX(TElem*& St, TInfo Info, TInfo X)
{
	TElem* Dop = NULL;
	TInfo inf;
	if (!St) printf("пустой\n");
	//TElem* Stt = St;
	while (St)
	{

		inf = PopElemFromStructure(&St);
		//printf("%5d\n", inf.Number);
		Dop = PushElemToStructure(Dop, inf);
		if (inf.Number == X.Number)
		{
			St = PushElemToStructure(St, Info);
			break;
		}
	}
	while (Dop) TopToTop(&Dop, &St);// printf("Press any key to continue");
	//getchar();
	return;
}

TElem* CheckForIndential(TElem* St, bool &containIndential)
{
	containIndential = false;
	TElem* Dop = NULL;
	TInfo inf;
	if (!St) printf("пустой\n");
	//TElem* Stt = St;
	std::set <int> numbers;
	while (St)
	{
		inf = PopElemFromStructure(&St);
		//printf("%5d\n", inf.Number);
		Dop = PushElemToStructure(Dop, inf);
		if (numbers.count(inf.Number)) { containIndential = true; }
		numbers.insert(inf.Number);
	}
	while (Dop) TopToTop(&Dop, &St);// printf("Press any key to continue");

	return St;
}
