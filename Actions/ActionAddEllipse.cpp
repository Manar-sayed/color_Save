#include "ActionAddEllipse.h"
#include "..\Figures\CEllipse.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

ActionAddEllipse::ActionAddEllipse(ApplicationManager* pApp) : Action(pApp)
{}

//Execute the action
void ActionAddEllipse::Execute()
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

	pGUI->PrintMessage("New Ellipse: Click at first point");
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);

	pGUI->PrintMessage("New Ellipse: Click at second point");
	//Read 2nd point and store in point P2
	pGUI->GetPointClicked(P2.x, P2.y);

	pGUI->ClearStatusBar();


	//Step 2 - prepare square data
	//User has entered two points P1&P2
	//2.1- Identify the Top left corner of the square


	//2.2- Calcuate square side legnth
	//The square side length would be the longer distance between the two points coordinates
	


	//Step 3 - Create a Square with the parameters read from the user
	CEllipse* R = new CEllipse ( P1, P2, SqrGfxInfo);

	//Step 4 - Add the Square to the list of figures
	pManager->AddFigure(R);
}


//void window::DrawEllipse(const int iX1, const int iY1, const int iX2, const int iY2, const drawstyle dsStyle) {



