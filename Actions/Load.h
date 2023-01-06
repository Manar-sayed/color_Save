#ifndef ACTION_LOAD
#define ACTION_LOAD
#include "Action.h"
class Load : public Action
{
private:
	string FileName;

public:

	Load(ApplicationManager* pApp);

	virtual void Execute();
};
#endif
