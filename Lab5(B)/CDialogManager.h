#pragma once
#include "CDlgCommand.h"
#include <vector>

class CDialogManager {
public:
	CDialogManager(CWorkspace& ws);
	~CDialogManager();

	void RegisterCommand(const char* sName, ptDlgCommandFunc pFunc);
	void Run();

private:
	std::vector<CDlgCommand*> m_aCommands;
	CWorkspace& m_refWorkspace;
};
