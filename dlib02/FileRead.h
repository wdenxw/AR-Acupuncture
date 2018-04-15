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
	char str1[1000];
	char str2[1000];
	char str3[1000];
	float AcuPosX[MAXACUNUM];
	float AcuPosY[MAXACUNUM];
	float AcuPosZ[MAXACUNUM];


};


#endif
