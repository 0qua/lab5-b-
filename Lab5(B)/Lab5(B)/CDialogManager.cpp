#include "CDialogManager.h"
#include <iostream>

CDialogManager::CDialogManager(CWorkspace& ws) : m_refWorkspace(ws) {
	m_aCommands.push_back(new CDlgCommand("Quit"));
}

CDialogManager::~CDialogManager() {
	for (auto* command : m_aCommands) {
		delete command;
	}
}

void CDialogManager::RegisterCommand(const char* sName, ptDlgCommandFunc pFunc) {
	m_aCommands.push_back(new CDlgCommand(sName, pFunc));
}

void CDialogManager::Run() {
	int nCommand = 0;
	do {
		std::cout << std::endl;
		for (size_t i = 0; i < m_aCommands.size(); i++) {
			std::cout << i << ". " << m_aCommands[i]->GetName() << std::endl;
		}
		std::cout << "Enter command: ";
		std::cin >> nCommand;
		if (nCommand > 0 && nCommand < static_cast<int>(m_aCommands.size())) {
			m_aCommands[nCommand]->Run(m_refWorkspace);
		}
	} while (nCommand != 0);
}
