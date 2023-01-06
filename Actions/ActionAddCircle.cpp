#include "ActionAddCircle.h"
#include "..\Figures\CCircle.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

ActionAddCircle::ActionAddCircle(ApplicationManager* pApp) : Action(pApp)
{}

//Execute the action
void ActionAddCircle::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo SqrGfxInfo;
	SqrGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	SqrGfxInfo.FillClr = pGUI->getCrntFillColor();
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read Circle data from the user

	pGUI->PrintMessage("New Square: Click at first point");
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);

	pGUI->PrintMessage("New Square: Click at second point");
	//Read 2nd point and store in point P2
	pGUI->GetPointClicked(P2.x, P2.y);

	pGUI->ClearStatusBar();


	//Step 2 - prepare square data
	//User has entered two points P1&P2
	//2.1- Identify the Top left corner of the square
	Point center;
	center.x = P1.x < P2.x ? P1.x : P2.x;
	center.y = P1.y < P2.y ? P1.y : P2.y;

	//2.2- Calcuate square side legnth
	//The square side length would be the longer distance between the two points coordinates
	int radius = max(abs(P1.x - P2.x), abs(P1.y - P2.y));


	//Step 3 - Create a Square with the parameters read from the user
	CCircle* R = new CCircle(center, radius, SqrGfxInfo);

	//Step 4 - Add the Square to the list of figures
	pManager->AddFigure(R);
}





