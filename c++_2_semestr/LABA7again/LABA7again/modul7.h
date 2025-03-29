#pragma once

#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>



struct TRoute {
	int Number;
	struct {
		char FirstStation[31];
		char IntermediateStations[61];
		char LastStation[31];
	} Stations;
	double AverageTravelTime;//в минутах
	double RushHourInterval; //в минутах 
};

//char* ANSIUpperCase(char* s, char* S);
char* ANSIUpperCase(char* s, char* S);

void CreateBinaryFile(int argc, char* argv[]);

void FindRoute(int argc, char* argv[]);

void CorrectFile(int argc, char* argv[]);

void RouteOutput(int argc, char* argv[]);