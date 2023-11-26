#pragma once
#include "CDlgCommand.h"

CDlgCommand::CDlgCommand(const char* sName, ptDlgCommandFunc pFunc) : m_sName(sName), m_pFunc(pFunc) {}

CDlgCommand::~CDlgCommand() {}

const char* CDlgCommand::GetName() const {
	return m_sName.c_str();
}

void CDlgCommand::Run(CWorkspace& ws) const {
	if (m_pFunc != nullptr) {
		m_pFunc(ws);
	}
}
