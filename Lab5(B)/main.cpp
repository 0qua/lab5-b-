
#include <iostream>
#include "DataChain.h"
#include "Workspace.h"
#include "CDialogManager.h"
#include "CDlgCommand.h"
#include "CDataSimple.h"
#include "LinkURL.h"
#include "CLink.h"

void Init(CWorkspace& ws);
void ShowFullSequence(CWorkspace& ws);
void Save(CWorkspace& ws);
void Load(CWorkspace& ws);
void FindSubstring(CWorkspace& ws);
void RemoveLink(CWorkspace& ws);
void AddURL(CWorkspace& ws);
CWorkspace* pWorkspace;

int main() {
	CDataSimple data;
	CWorkspace ws(data);
	CDialogManager mgr(ws);

	mgr.RegisterCommand("Init sequence", Init);
	mgr.RegisterCommand("Show sequence", ShowFullSequence);
	mgr.RegisterCommand("Save", Save);
	mgr.RegisterCommand("Load", Load);
	mgr.RegisterCommand("Find Substring", FindSubstring);
	mgr.RegisterCommand("Add URL", AddURL); 
	mgr.RegisterCommand("Remove Link", RemoveLink);
	mgr.Run();

	return 0;
}

void AddURL(CWorkspace& ws) {
	std::string url;
	std::cout << "Enter URL to add: ";
	std::cin >> url;

	CLinkURL* pLinkURL = new CLinkURL(ws.GetChain());
	if (pLinkURL->Attach(url.c_str())) {
		std::cout << "URL added successfully." << std::endl;
		ws.AddLink(0, url.length(), pLinkURL);
	} else {
		std::cout << "Failed to add URL." << std::endl;
		delete pLinkURL;
	}
}

void RemoveLink(CWorkspace& ws) {
	int linkIndex;
	std::cout << "Enter index of the link to remove: ";
	std::cin >> linkIndex;

	if (ws.RemoveLink(linkIndex)) {
		std::cout << "Link removed successfully." << std::endl;
	} else {
		std::cout << "Failed to remove link." << std::endl;
	}
}

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

void FindSubstring(CWorkspace& ws) {
    std::string substr;
    std::cout << "Enter substring to find: ";
    std::cin >> substr;

    // ����� ������ ��������
    int position = ws.GetChain().Find(substr.c_str());
    if (position != -1) {
        std::cout << "Substring found at position: " << position << std::endl;
    } else {
        std::cout << "Substring not found." << std::endl;
    }
}