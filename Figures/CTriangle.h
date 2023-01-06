#ifndef CTriangle_H
#define CTriangle_H

#include "CFigure.h"

class CTriangle : public CFigure
{
	Point P1;
	Point P2;
	Point P3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	CTriangle();
	virtual void DrawMe(GUI* pOut) const;
	virtual bool insideFigure(int x, int y);
	virtual void Save(ofstream& File);
	void Load(ifstream& Infile);
};

#endif