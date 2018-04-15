#include"stdafx.h"
#include "FileRead.h"
#include <iostream>
using namespace std;


//以下为测试文件部分

void FileRead::ReadAcuPos()
{
	FILE *f = fopen("withpoint.obj", "r");
	if (!fopen) {
		cout << "创建文件失败";
	}

	bool IsitFirst = true;;

	int i = 0;
	while (1)
	{

		if (NULL == fgets(buf, 256, f)) break;
		if (p = strstr(buf, "default"))
		{
			if (IsitFirst)//去掉那个最开头的不是表示穴位的default
			{
				IsitFirst = false;
				continue;
			}
			fscanf(f, "%*s\n%s\n", str1);/*忽略一行，并读取下一行*/
			AcuPosX[i] = atof(str1);
			fscanf(f, "%s", str2);/*忽略一个空格，并读取下一个数据*/
			AcuPosY[i] = atof(str1);
			fscanf(f, "%s", str3);/*忽略一个空格，并读取下一个数据*/
			AcuPosZ[i] = atof(str1);
			i++;
		}
	}


	system("pause");
	fclose(f);

}
