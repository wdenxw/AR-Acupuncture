#include"stdafx.h"
#include "FileRead.h"
#include <iostream>
using namespace std;


//����Ϊ�����ļ�����

void FileRead::ReadAcuPos()
{
	FILE *f = fopen("withpoint.obj", "r");
	if (!fopen) {
		cout << "�����ļ�ʧ��";
	}

	bool IsitFirst = true;;

	int i = 0;
	while (1)
	{

		if (NULL == fgets(buf, 256, f)) break;
		if (p = strstr(buf, "default"))
		{
			if (IsitFirst)//ȥ���Ǹ��ͷ�Ĳ��Ǳ�ʾѨλ��default
			{
				IsitFirst = false;
				continue;
			}
			fscanf(f, "%*s\n%s\n", str1);/*����һ�У�����ȡ��һ��*/
			AcuPosX[i] = atof(str1);
			fscanf(f, "%s", str2);/*����һ���ո񣬲���ȡ��һ������*/
			AcuPosY[i] = atof(str1);
			fscanf(f, "%s", str3);/*����һ���ո񣬲���ȡ��һ������*/
			AcuPosZ[i] = atof(str1);
			i++;
		}
	}


	system("pause");
	fclose(f);

}
