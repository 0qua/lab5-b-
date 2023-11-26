#pragma once
#include "DataChain.h"
#include "CLink.h"
#include <string>
#include <fstream>
#include <vector>

typedef std::vector<CLink*> LinksArray;

class CWorkspace {
public:
	CWorkspace(CDataChain& data);
	~CWorkspace();

	void Init(int nDepth, int nLength);
	const char* GetChainString() const;

	bool Save(const std::string& sFilepath) const;
	bool Load(const std::string& sFilepath);

	// Методи для роботи з лінками
	bool AddLink(int nStartPos, int nLength, CLink* pLink);
	bool RemoveLink(int nPosInList);
	bool GetAllLinks(LinksArray& aLinks);

	CDataChain& GetChain() {
		return m_refChain;
	}

private:
	CDataChain& m_refChain;
	LinksArray m_aLinks;
};
