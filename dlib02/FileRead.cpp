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

//以下为测试文件部分

void FileRead::ReadAcuPos()
{
	FILE *f = fopen("RevPoint3.obj", "r");
	if (!fopen) {
		cout << "创建文件失败";
	}

	bool IsitFirst = true;;

	int i = 0, j = 0;
	while (1)
	{

		if (NULL == fgets(buf, 256, f)) break;
		if ((p = strstr(buf, "object group1_pSphere"))||(p = strstr( buf,"object pSphere")))
		{
			fscanf(f, "%*s\n%s\n", str0);/*忽略一行，并读取下一行*/
			fscanf(f, "%s", str1);/*忽略一行，并读取下一行*/
			AcuPosX[i] = atof(str1);
			fscanf(f, "%s", str2);/*忽略一个空格，并读取下一个数据*/
			AcuPosY[i] = atof(str2);
			fscanf(f, "%s", str3);/*忽略一个空格，并读取下一个数据*/
			AcuPosZ[i] = atof(str3);
			i++;
		}
		if (p = strstr(buf, "object spoint"))
		{
			p += 13;
			j = atoi(p);
			fscanf(f, "%*s\n%s\n", str4);/*忽略一行，并读取下一行*/
			fscanf(f, "%s", str5);/*忽略一行，并读取下一行*/
			FeaPosX[j] = atof(str5);
			fscanf(f, "%s", str6);/*忽略一个空格，并读取下一个数据*/
			FeaPosY[j] = atof(str6);
			fscanf(f, "%s", str7);/*忽略一个空格，并读取下一个数据*/
			FeaPosZ[j] = atof(str7);

		}

	}	
	fclose(f);
}
