#pragma once
#include "CDlgCommand.h"
#include "LinkURL.h"
#include "CLink.h"
#include "Workspace.h"
#include <vector>

class CDialogManager {
public:
	CDialogManager(CWorkspace& ws);
	~CDialogManager();

	void RegisterCommand(const char* sName, ptDlgCommandFunc pFunc);
	void Run();
	void AddURL(const std::string& subStr, const std::string& url);

	// Видалення лінка
	void RemoveLink(int linkIndex);
private:
	std::vector<CDlgCommand*> m_aCommands;
	CWorkspace& m_refWorkspace;
	std::vector<CLink*> m_aLinks;
};
