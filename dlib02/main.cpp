// dlib02.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "FileRead.h"
#include "MarkFace.h"



using namespace std;
#define RATIO 1  
#define SKIP_FRAMES 2  



int main()
{

//文件操作部分
	FileRead a;
	a.ReadAcuPos();
	//标定穴位
MarkFace b;
b.MarkPoints();

}
