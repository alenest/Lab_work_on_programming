#define _CRT_SECURE_NO_WARNINGS
#include "modul7.h"

char* ANSIUpperCase(char* s, char* S) {
	S = strcpy(S, s);
	char* ch = S;
	while (*ch) {
		if (*ch >= 'a' && *ch <= 'z' || *ch >= 'а' && *ch <= 'я') *ch =
			*ch - 32;
		if (*ch == 'ё') *ch = 'Ё';
		ch++;
	}
	return S;
}

void CreateBinaryFile(int argc, char* argv[]) {
	SetConsoleOutputCP(1251);
	if (argc < 3) {
		printf("Мало параметров\nPress any key");
		system("pause");
		return;
	}
	FILE* ft;
	fopen_s(&ft, argv[2], "rt");
	if (ft == NULL) {
		printf("Error: не удалось открыть файл с исходными данными %s\n", argv[2]);
		system("pause");
		return;
	}
	FILE* fb;
	fopen_s(&fb, argv[1], "wb");
	if (fb == NULL) {
		fclose(ft);
		printf("Error: не удалось создать двоичный файл %s\n", argv[1]);
		system("pause");
		return;
	}
	 // либо struct TStud Stud; в С
	int kol = 0, nw = 1;
	char* n;
	char* s;
	s = (char*)malloc(30);
	while (nw) {

		fgets(s, 30, ft);
		fflush(ft);
		n = strchr(s, '\n');
		if (n) s[n - s] = '\0';
		TRoute Route;
		
		Route.Number = atoi(s);

		Route.Stations.FirstStation = (char*)malloc(30);
		fgets(Route.Stations.FirstStation, 30, ft);
		fflush(ft);
		n = strchr(Route.Stations.FirstStation, '\n');
		if (n) Route.Stations.FirstStation[n - Route.Stations.FirstStation] = '\0';
		//if (strcmp(Route.Stations.FirstStation, "**") == 0 || feof(ft)) break;
		
		Route.Stations.IntermediateStations = (char*)malloc(100);
		fgets(Route.Stations.IntermediateStations, 100, ft);
		fflush(ft);
		n = strchr(Route.Stations.IntermediateStations, '\n');
		if (n) Route.Stations.IntermediateStations[n - Route.Stations.IntermediateStations] = '\0';

		Route.Stations.LastStation = (char*)malloc(30);
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

		if (strcmp(Route.Stations.FirstStation, "**") == 0 || feof(ft))
		{
			free(s);
			free(Route.Stations.FirstStation);
			free(Route.Stations.IntermediateStations);
			free(Route.Stations.LastStation);
			break;
		}
		printf("\nмаршрут номер %d \nпервая станция: %s\nпромежуточные станции: %s\nпоследняя станция: %s\nсреднее время: %.2f\nинтервал в час пик: %.2f\n",
			Route.Number, Route.Stations.FirstStation, Route.Stations.IntermediateStations, Route.Stations.LastStation, Route.AverageTravelTime, Route.RushHourInterval);

		nw = fwrite(&Route, sizeof(Route), 1, fb);
		kol++;
		/*free(s);
		free(Route.Stations.FirstStation);
		free(Route.Stations.IntermediateStations);
		free(Route.Stations.LastStation);*/
		//if (feof(ft)) break;
		
	}

	if (nw != 1) printf("Error: Ошибка при записи");
	fclose(ft);
	fclose(fb);
	printf("\nСоздан двоичный файл из %d записей по %d байт\n", kol, sizeof(TRoute));
	//printf("Press any key to continue");
	//getch();
	getchar();
	//system("pause");
	return;
}


void FindRoute(int argc, char* argv[]) {
	if (argc < 2) {
		printf("Мало параметров\n");
		//getch();
		system("pause");
		return;
	}
	FILE* fb;
	fopen_s(&fb, argv[1], "rb");
	if (fb == NULL) {
		printf("Error: не удалось открыть двоичный файл %s\n", argv[1]);
		printf("Press ENTER");
		//getch();
		system("pause");
		return;
	}

	char* UserLastStation;
	UserLastStation = (char*)malloc(50);
	printf_s("Введите конечный пункт: ");
	//gets(UserLastStation);
	//system("pause");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	getchar();
	fgets(UserLastStation, 100, stdin);
	UserLastStation = strtok(UserLastStation,"\n");
	/*std::cout << "коды : " << std::endl;
	for (int i = 0; i < sizeof(UserLastStation); i++)
	{
		std::cout << int(UserLastStation[i]) << " ";
	}
	std::cout << std::endl;*/
	//scanf_s("\n%s", &UserLastStation);
	char* UpUserLastStation;
	UpUserLastStation = (char*)malloc(50);
	UpUserLastStation = ANSIUpperCase(UserLastStation, UpUserLastStation);
	
	
	//printf("\nUserLastStation: %s\n", UserLastStation);
	free(UserLastStation);
	
	//printf("\nUpUserLastStation: %s\n", UpUserLastStation);

	TRoute Route;
	char* SUp;
	SUp = (char*)malloc(50);
	int kol = 0, nr = 1;
	while (nr) {
		nr = fread(&Route, sizeof(Route), 1, fb);
		//fseek(fb, 0, SEEK_SET);
		////fseek(fb, 0 - sizeof(Route) + sizeof(int), SEEK_CUR);
		//int Number; fread(&Number, sizeof(int), 1, fb);
		//char FirstStation[30]; fread(&FirstStation, 30, 1, fb); 
		////Route.Stations.FirstStation = (char*)malloc(30); 
		//Route.Stations.FirstStation = FirstStation;
		////fread(&Route.Stations.FirstStation, 30, 1, fb);
		//fread(&Route.Stations.IntermediateStations, 100, 1, fb);
		//fread(&Route.Stations.LastStation, 30, 1, fb);
		//fseek(fb, 0 + sizeof(double) + sizeof(double), SEEK_CUR);
		if (nr > 0)
		{
			SUp = ANSIUpperCase(Route.Stations.LastStation, SUp);
			//printf("\nSUp: %s\n", SUp);
			if (Route.RushHourInterval < 10 &&
				strcmp(SUp, UpUserLastStation) == 0) {
				printf("Найден маршрут %d с конченой станцией %s и интервалом в час пик (в минутах): %.2f\n", Route.Number, Route.Stations.LastStation, Route.RushHourInterval);
				kol++;
			}
		}
	}
	if (kol == 0)
		printf("Данные, соответствующие запросу, не найдены\n");
	else
		printf("Всего найдено: %d\n", kol);
	fclose(fb);
	 free(UpUserLastStation); free(SUp);
	//printf("Press any key to continue");
	//getch();
	//system("pause");
	 getchar();
	return;
}


void CorrectFile(int argc, char* argv[]) {
	if (argc < 2) {
		printf("Мало параметров\nPress any key");
		//getch();
		system("pause");
		return;
	}
	FILE* fb = fopen(argv[1], "rb+");
	if (fb == NULL) {
		printf("Error: не удалось открыть двоичный файл %s\n",
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
		printf("Считана запись:\n");
		/*printf("%d %25s %40s %25s %.2f %.2f\n", Route.Number, Route.Stations.FirstStation, Route.Stations.IntermediateStations, Route.Stations.LastStation, 
			Route.AverageTravelTime, Route.RushHourInterval);*/
		printf("\nмаршрут номер %d \nпервая станция: %s\nпромежуточные станции: %s\nпоследняя станция: %s\nсреднее время: %.2f\nинтервал в час пик: %.2f\n",
			Route.Number, Route.Stations.FirstStation, Route.Stations.IntermediateStations, Route.Stations.LastStation, Route.AverageTravelTime, Route.RushHourInterval);
		flag = 0;
		if (Route.RushHourInterval < 0) { Route.RushHourInterval = 0; flag = 1; }
		if (Route.RushHourInterval > 60.0) { Route.RushHourInterval = 60.0; flag = 1; }
		if (Route.AverageTravelTime < 30.0) { Route.AverageTravelTime = 30; flag = 1; }
		if (Route.AverageTravelTime > 2 * 60) { Route.AverageTravelTime = 2 * 60; flag = 1; }
		if (flag) {
			kol++;
			fseek(fb, 0 - sizeof(Route), SEEK_CUR);
			nw = fwrite(&Route, sizeof(Route), 1, fb);
			fseek(fb, 0, SEEK_CUR);
			printf("\nСделана корректировка:\n");
			/*printf("%d %25s %40s %25s %.2f %.2f\n", Route.Number, Route.Stations.FirstStation, Route.Stations.IntermediateStations, Route.Stations.LastStation,
				Route.AverageTravelTime, Route.RushHourInterval);*/
			printf("\nмаршрут номер %d \nпервая станция: %s\nпромежуточные станции: %s\nпоследняя станция: %s\nсреднее время: %.2f\nинтервал в час пик: %.2f\n",
				Route.Number, Route.Stations.FirstStation, Route.Stations.IntermediateStations, Route.Stations.LastStation, Route.AverageTravelTime, Route.RushHourInterval);
		}
		nr = fread(&Route, sizeof(Route), 1, fb);
	}
	if (kol == 0)
		printf("\nНи одной корректировки\n\n");
	else
		printf("Всего корректировок: %d\n\n", kol);
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
		printf("Мало параметров\nPress any key");
		//getch();
		system("pause");
		return;
	}
	FILE* fb = fopen(argv[1], "rb+");
	if (fb == NULL) {
		printf("Error: не удалось открыть двоичный файл %s\n",
			argv[1]);
		printf("Press ENTER");
		//getch();
		system("pause");
		return;
	}
	printf("\n|№ маршрута|Нач. станция|          Промеж. станции           |Конечн. станция|Средн. время(мин)|Интервал в час пик(мин)|\n");
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
	 if (kol == 0) printf("PЗаписей нет\n");
	 else printf("всего %d записей\n", kol);
	 getchar();

}