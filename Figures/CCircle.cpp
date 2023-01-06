#include "CCircle.h"
#include <string>
#include <fstream>
#include <iostream>


CCircle::CCircle(Point P1, int _radius, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	center = P1;
	radius = _radius;
	ID++;
}
CCircle::CCircle()
{}

void CCircle::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawCircle to draw a Circle on the screen	
	pGUI->DrawCircle(center,radius, FigGfxInfo, Selected);

	


}
void CCircle::Save(ofstream& OutFile)
{
	cout << "noooooon";
	OutFile << "circle \t" << ID
		    << "\t" << center.x 
		    << "\t" << center.y 
		    << "\t" << radius <<"\t"
		<< ColorToString(this->FigGfxInfo.DrawClr);
	
	if (!this->FigGfxInfo.isFilled) {
		cout << "fff";

		OutFile << "\t" << "Not_color_now!";

	}
	else {
		OutFile << "\t" << ColorToString(this->FigGfxInfo.FillClr);
	}
}


void CCircle::Load(ifstream& Infile)
{
	string temp;
	Infile >> this->ID >>
		this->center.x >> 
		this->center.y >>
		this->radius;
	Infile >> temp;
	this->FigGfxInfo.DrawClr = StringToColor(temp);
	Infile >> temp;
	if (temp == "Not_color_now!") {
		this->FigGfxInfo.isFilled = false;
	}
	else
	{
		this->FigGfxInfo.FillClr = StringToColor(temp);
		this->FigGfxInfo.isFilled = true;
		cout << "fail";
	}
	this->Selected = false;
	this->FigGfxInfo.BorderWdth = 3;
}

bool CCircle::insideFigure(int x, int y)
{
	float dx = pow(x - center.x, 2);
	float dy = pow(y - center.y, 2);
	if (dx + dy < radius * radius)
		return true;
	return false;
}