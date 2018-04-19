#pragma once
#include"stdafx.h"
#ifndef FILEREAD_H
#define FILEREAD_H
#define MAXACUNUM 100

class FileRead
{
public:
	void ReadAcuPos();



private:
	char buf[256];
	char st[80];
	char *p;
	char str0[1000];
	char str1[1000];
	char str2[1000];
	char str3[1000];

	char str4[1000];
	char str5[1000];
	char str6[1000];
	char str7[1000];

};


#endif
extern float AcuPosX[MAXACUNUM];
extern float AcuPosY[MAXACUNUM];
extern float AcuPosZ[MAXACUNUM];

extern float FeaPosX[MAXACUNUM];
extern float FeaPosY[MAXACUNUM];
extern float FeaPosZ[MAXACUNUM];