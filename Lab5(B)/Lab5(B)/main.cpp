#include <iostream>
#include "DataChain.h"
#include "Workspace.h"
#include "CDialogManager.h"
#include "CDlgCommand.h"

// Функції для команд
void Init(CWorkspace& ws);
void ShowFullSequence(CWorkspace& ws);
void Save(CWorkspace& ws);
void Load(CWorkspace& ws);

int main() {
	CDataSimple data;
	CWorkspace ws(data);
	CDialogManager mgr(ws);

	// Реєстрація команд
	mgr.RegisterCommand("Init sequence", Init);
	mgr.RegisterCommand("Show sequence", ShowFullSequence);
	mgr.RegisterCommand("Save", Save);
	mgr.RegisterCommand("Load", Load);

	// Запуск діалогу з користувачем
	mgr.Run();

	return 0;
}

// Реалізація функцій для команд
void Init(CWorkspace& ws) {
	int nDepth, nLength;
	std::cout << "Enter depth and length: ";
	std::cin >> nDepth >> nLength;
	ws.Init(nDepth, nLength);
	std::cout << "Sequence initialized." << std::endl;
}

void ShowFullSequence(CWorkspace& ws) {
	std::cout << "Full Sequence: " << ws.GetChainString() << std::endl;
}

void Save(CWorkspace& ws) {
	std::string filepath;
	std::cout << "Enter file path to save: ";
	std::cin >> filepath;
	if (ws.Save(filepath)) {
		std::cout << "Sequence saved to " << filepath << std::endl;
	}
	else {
		std::cout << "Failed to save sequence." << std::endl;
	}
}

void Load(CWorkspace& ws) {
	std::string filepath;
	std::cout << "Enter file path to load: ";
	std::cin >> filepath;
	if (ws.Load(filepath)) {
		std::cout << "Sequence loaded from " << filepath << std::endl;
	}
	else {
		std::cout << "Failed to load sequence." << std::endl;
	}
}
