#pragma once
#include "Workspace.h"

// Декларація типу функції
typedef void(*ptDlgCommandFunc)(CWorkspace& ws);

class CDlgCommand {
public:
	CDlgCommand(const char* sName, ptDlgCommandFunc pFunc = nullptr);
	~CDlgCommand();

	const char* GetName() const;
	void Run(CWorkspace& ws) const;

private:
	std::string m_sName;
	ptDlgCommandFunc m_pFunc;
};
