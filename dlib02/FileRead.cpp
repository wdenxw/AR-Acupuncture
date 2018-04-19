#include"stdafx.h"
#include "FileRead.h"
#include <iostream>
using namespace std;
float AcuPosX[MAXACUNUM];
float AcuPosY[MAXACUNUM];
float AcuPosZ[MAXACUNUM];

float FeaPosX[MAXACUNUM];
float FeaPosY[MAXACUNUM];
float FeaPosZ[MAXACUNUM];

//����Ϊ�����ļ�����

void FileRead::ReadAcuPos()
{
	FILE *f = fopen("RevPoint3.obj", "r");
	if (!fopen) {
		cout << "�����ļ�ʧ��";
	}

	bool IsitFirst = true;;

	int i = 0, j = 0;
	while (1)
	{

		if (NULL == fgets(buf, 256, f)) break;
		if ((p = strstr(buf, "object group1_pSphere"))||(p = strstr( buf,"object pSphere")))
		{
			fscanf(f, "%*s\n%s\n", str0);/*����һ�У�����ȡ��һ��*/
			fscanf(f, "%s", str1);/*����һ�У�����ȡ��һ��*/
			AcuPosX[i] = atof(str1);
			fscanf(f, "%s", str2);/*����һ���ո񣬲���ȡ��һ������*/
			AcuPosY[i] = atof(str2);
			fscanf(f, "%s", str3);/*����һ���ո񣬲���ȡ��һ������*/
			AcuPosZ[i] = atof(str3);
			i++;
		}
		if (p = strstr(buf, "object spoint"))
		{
			p += 13;
			j = atoi(p);
			fscanf(f, "%*s\n%s\n", str4);/*����һ�У�����ȡ��һ��*/
			fscanf(f, "%s", str5);/*����һ�У�����ȡ��һ��*/
			FeaPosX[j] = atof(str5);
			fscanf(f, "%s", str6);/*����һ���ո񣬲���ȡ��һ������*/
			FeaPosY[j] = atof(str6);
			fscanf(f, "%s", str7);/*����һ���ո񣬲���ȡ��һ������*/
			FeaPosZ[j] = atof(str7);

		}

	}	
	fclose(f);
}
