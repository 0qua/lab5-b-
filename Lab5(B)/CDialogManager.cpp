#pragma once
#include "CDlgCommand.h"
#include "CDialogManager.h"
#include "Workspace.h"
#include "LinkURL.h"
#include "CLink.h"
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
void CDialogManager::AddURL(const std::string& subStr, const std::string& url) {
	CDataChain& refChain = m_refWorkspace.GetChain();
	CLinkURL* pLink = new CLinkURL(refChain);
	pLink->SetURL(url); // Припускаючи, що ви додали метод SetURL до CLinkURL

	if (pLink->Attach(subStr.c_str())) {
		m_aLinks.push_back(pLink);
		std::cout << "URL '" << url << "' successfully attached to substring '" << subStr << "'." << std::endl;
	}
	else {
		delete pLink;
		std::cout << "Failed to attach URL to substring." << std::endl;
	}
}


void CDialogManager::RemoveLink(int linkIndex) {
	if (linkIndex >= 0 && linkIndex < m_aLinks.size()) {
		delete m_aLinks[linkIndex];
		m_aLinks.erase(m_aLinks.begin() + linkIndex);
		std::cout << "Link removed successfully." << std::endl;
	}
	else {
		std::cout << "Invalid link index. Removal failed." << std::endl;
	}
}
