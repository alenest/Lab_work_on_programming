#define _CRT_SECURE_NO_WARNINGS
#include "modul7.h"

char* ANSIUpperCase(char* s, char* S) {
	S = strcpy(S, s);
	char* ch = S;
	while (*ch) {
		if (*ch >= 'a' && *ch <= 'z' || *ch >= '�' && *ch <= '�') *ch =
			*ch - 32;
		if (*ch == '�') *ch = '�';
		ch++;
	}
	return S;
}

void CreateBinaryFile(int argc, char* argv[]) {
	if (argc < 3) {
		printf("���� ����������\nPress any key");
		getchar();
		return;
	}
	FILE* ft = fopen(argv[2], "rt");
	if (ft == NULL) {
		printf("Error: �� ������� ������� ���� � \
��������� ������� %s\n", argv[2]);
		printf("Press any key "); getchar();
		return;
	}
	FILE* fb = fopen(argv[1], "wb");
	if (fb == NULL) {
		fclose(ft);
		printf("Error: �� ������� ������� \
�������� ���� %s\n", argv[1]);
		printf("Press any key"); getchar();
		return;
	}
	TRoute Route;
	//TStud Stud; // ���� struct TStud Stud; � �
	int kol = 0, nw = 1;
	char s[60];
	char* n;
	while (nw) {
		fgets(s, 30, ft);
		fflush(ft);
		n = strchr(s, '\n');
		if (n) s[n - s] = '\0';
		TRoute Route;

		Route.Number = atoi(s);

		//Route.Stations.FirstStation = (char*)malloc(30);
		fgets(Route.Stations.FirstStation, 30, ft);
		fflush(ft);
		n = strchr(Route.Stations.FirstStation, '\n');
		if (n) Route.Stations.FirstStation[n - Route.Stations.FirstStation] = '\0';
		//if (strcmp(Route.Stations.FirstStation, "**") == 0 || feof(ft)) break;

		//Route.Stations.IntermediateStations = (char*)malloc(100);
		fgets(Route.Stations.IntermediateStations, 60, ft);
		fflush(ft);
		n = strchr(Route.Stations.IntermediateStations, '\n');
		if (n) Route.Stations.IntermediateStations[n - Route.Stations.IntermediateStations] = '\0';

		//Route.Stations.LastStation = (char*)malloc(30);
		fgets(Route.Stations.LastStation, 30, ft);
		fflush(ft);
		n = strchr(Route.Stations.LastStation, '\n');
		if (n) Route.Stations.LastStation[n - Route.Stations.LastStation] = '\0';

		fgets(s, 30, ft);
		fflush(ft);
		n = strchr(s, '\n');
		if (n) s[n - s] = '\0'; Route.AverageTravelTime = atof(s);

		fgets(s, 30, ft);
		fflush(ft);
		n = strchr(s, '\n');
		if (n) s[n - s] = '\0'; Route.RushHourInterval = atof(s);

		if (strcmp(Route.Stations.FirstStation, "**") == 0 || feof(ft)) break;
		printf("\n������� ����� %d \n������ �������: %s\n������������� �������: %s\n��������� �������: %s\n������� �����: %.2f\n�������� � ��� ���: %.2f\n",
			Route.Number, Route.Stations.FirstStation, Route.Stations.IntermediateStations, Route.Stations.LastStation, Route.AverageTravelTime, Route.RushHourInterval);

		nw = fwrite(&Route, sizeof(Route), 1, fb);
		kol++;
	}
	free(n);
	if (nw != 1) printf("Error: ������ ��� ������");
	fclose(ft);
	fclose(fb);
	printf("������ �������� ���� �� %d ������� �� %d ����\n\n", kol, sizeof(TRoute));
	getchar();
	return;
}

void FindRoute(int argc, char* argv[])
{
	if (argc < 2) {
		printf("���� ����������\n");
		//getch();
		system("pause");
		return;
	}
	FILE* fb;
	fopen_s(&fb, argv[1], "rb");
	if (fb == NULL) {
		printf("Error: �� ������� ������� �������� ���� %s\n", argv[1]);
		printf("Press ENTER");
		//getch();
		system("pause");
		return;
	}
	char UserLastStation[31];
	printf_s("������� �������� �����: ");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	getchar();
	char* n;
	fgets(UserLastStation, 30, stdin);
	for (int i = 0; i < sizeof(UserLastStation); i++)
	{
		if (UserLastStation[i] == '\n') UserLastStation[i] = '\0';
	}
	//UserLastStation = strtok(UserLastStation, "\n");
	fflush(stdin); // ���� ������ ���� �������, ������� ������� �� ������, � ���� ������:
	n = strchr(UserLastStation, '\n'); if (n) UserLastStation[n - UserLastStation] = '\0';

	char UpUserLastStation[31];
	ANSIUpperCase(UserLastStation, UpUserLastStation);
	TRoute Route;
	char SUp[31];
	int kol = 0, nr = 1;
	while (nr) {
		nr = fread(&Route, sizeof(Route), 1, fb);
		if (nr > 0)
		{
			//SUp = ANSIUpperCase(Route.Stations.LastStation, SUp);
			//printf("\nSUp: %s\n", SUp);
			if (Route.RushHourInterval < 10 &&
				strcmp(ANSIUpperCase(Route.Stations.LastStation, SUp), ANSIUpperCase(UserLastStation, UpUserLastStation)) == 0) {
				printf("������ ������� %d � �������� �������� %s � ���������� � ��� ��� (� �������): %.2f\n", Route.Number, Route.Stations.LastStation, Route.RushHourInterval);
				kol++;
			}
		}
	}
	if (kol == 0)
		printf("������, ��������������� �������, �� �������\n");
	else
		printf("����� �������: %d\n", kol);
	fclose(fb);
	//free(UpUserLastStation); free(SUp);
	//printf("Press any key to continue");
	//getch();
	//system("pause");
	getchar();
	return;
}


void CorrectFile(int argc, char* argv[]) {
	if (argc < 2) {
		printf("���� ����������\nPress any key");
		//getch();
		system("pause");
		return;
	}
	FILE* fb = fopen(argv[1], "rb+");
	if (fb == NULL) {
		printf("Error: �� ������� ������� �������� ���� %s\n",
			argv[1]);
		printf("Press ENTER");
		//getch();
		system("pause");
		return;
	}
	TRoute Route;
	int kol = 0, nr = 1, nw = 1, flag;
	nr = fread(&Route, sizeof(Route), 1, fb);
	while (nr == 1 && nw == 1) {
		printf("������� ������:\n");
		/*printf("%d %25s %40s %25s %.2f %.2f\n", Route.Number, Route.Stations.FirstStation, Route.Stations.IntermediateStations, Route.Stations.LastStation,
			Route.AverageTravelTime, Route.RushHourInterval);*/
		printf("\n������� ����� %d \n������ �������: %s\n������������� �������: %s\n��������� �������: %s\n������� �����: %.2f\n�������� � ��� ���: %.2f\n",
			Route.Number, Route.Stations.FirstStation, Route.Stations.IntermediateStations, Route.Stations.LastStation, Route.AverageTravelTime, Route.RushHourInterval);
		flag = 0;
		//if (Route.RushHourInterval < 0) { Route.RushHourInterval = pow(10,sizeof(double)); flag = 1; }
		if (Route.RushHourInterval <= 0) { Route.RushHourInterval = 1; flag = 1; }
		if (Route.RushHourInterval > 60.0) { Route.RushHourInterval = 60.0; flag = 1; }
		if (Route.AverageTravelTime < 30.0) { Route.AverageTravelTime = 30; flag = 1; }
		if (Route.AverageTravelTime > 2 * 60) { Route.AverageTravelTime = 2 * 60; flag = 1; }
		if (flag) {
			kol++;
			fseek(fb, 0 - sizeof(Route), SEEK_CUR);
			nw = fwrite(&Route, sizeof(Route), 1, fb);
			fseek(fb, 0, SEEK_CUR);
			printf("\n������� �������������:\n");
			/*printf("%d %25s %40s %25s %.2f %.2f\n", Route.Number, Route.Stations.FirstStation, Route.Stations.IntermediateStations, Route.Stations.LastStation,
				Route.AverageTravelTime, Route.RushHourInterval);*/
			printf("\n������� ����� %d \n������ �������: %s\n������������� �������: %s\n��������� �������: %s\n������� �����: %.2f\n�������� � ��� ���: %.2f\n",
				Route.Number, Route.Stations.FirstStation, Route.Stations.IntermediateStations, Route.Stations.LastStation, Route.AverageTravelTime, Route.RushHourInterval);
		}
		nr = fread(&Route, sizeof(Route), 1, fb);
	}
	if (kol == 0)
		printf("\n�� ����� �������������\n\n");
	else
		printf("����� �������������: %d\n\n", kol);
	fclose(fb);
	//("Press any key to continue");
	//getch();
	getchar();
	//system("pause");
	return;
}


void RouteOutput(int argc, char* argv[])
{
	if (argc < 2) {
		printf("���� ����������\nPress any key");
		//getch();
		system("pause");
		return;
	}
	FILE* fb = fopen(argv[1], "rb");
	if (fb == NULL) {
		printf("Error: �� ������� ������� �������� ���� %s\n",
			argv[1]);
		printf("Press ENTER");
		//getch();
		system("pause");
		return;
	}
	printf("\n|� ��������|���. �������|          ������. �������           |������. �������|�����. �����(���)|�������� � ��� ���(���)|\n");
	TRoute Route;
	int kol = 0, nr = 1;
	while (nr) {
		nr = fread(&Route, sizeof(Route), 1, fb);
		if (nr > 0)
		{
			printf("|%10d|%12s|%36s|%15s|%17.2f|%23.2f|\n",
				Route.Number, Route.Stations.FirstStation, Route.Stations.IntermediateStations, Route.Stations.LastStation, Route.AverageTravelTime, Route.RushHourInterval);
			kol++;
		}

	}
	fclose(fb);
	if (kol == 0) printf("P������� ���\n");
	else printf("����� %d �������\n", kol);
	getchar();
}
