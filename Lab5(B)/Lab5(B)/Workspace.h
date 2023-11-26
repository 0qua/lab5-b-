#pragma once
#include "DataChain.h"
#include <string>
#include <fstream>

class CWorkspace {
public:
	CWorkspace(CDataChain& data);
	~CWorkspace();

	void Init(int nDepth, int nLength);
	const char* GetChainString() const;

	bool Save(const std::string& sFilepath) const;
	bool Load(const std::string& sFilepath);

private:
	CDataChain& m_refChain;
};
