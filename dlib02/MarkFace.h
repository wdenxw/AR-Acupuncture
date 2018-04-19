#pragma once
#include"stdafx.h"
#ifndef MAKEFACE_H
#define MARKFACE_H
#define RATIO 1  
#define SKIP_FRAMES 2  
class MarkFace
{
public:

	void MarkPoints();
	void translation(float *Xpoint, float *Ypoint, float *Zpoint, float translateX, float translateY, float translateZ);
	void scaling(float *Xpoint, float *Ypoint, float *Zpoint, float scaleX, float scaleY, float scaleZ);
	void rotation(float *Xpoint, float *Ypoint, float *Zpoint, float Xangle, float Yangle, float Zangle);

	friend void onMouseHandle(int event, int x, int y, int flags, void* userdata);


private:



};


#endif
