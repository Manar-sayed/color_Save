#ifndef CCIRCLE_H
#define CCIRCLE_H

#include "CFigure.h"

class CCircle :public CFigure
{
private:
	Point center;
	int radius;
public:
	CCircle(Point, int, GfxInfo FigureGfxInfo);
	CCircle();
	virtual void DrawMe(GUI* pOut) const;
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	bool insideFigure(int x, int y);
};

#endif

