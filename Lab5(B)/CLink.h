#pragma once
#include "DataChain.h"
#include <iostream>
#include <vector>

class CLink {
public:
	CLink(CDataChain& refChain);
	virtual ~CLink();

	bool Attach(const char* sSubStr);
	virtual void Output(std::ostream& os);
	virtual bool Save(std::ostream& so);
	virtual bool Load(std::istream& is);

protected:
	CDataChain& m_refChain;
	int m_nPos;
	int m_nSize;
};

typedef std::vector<CLink*> LinksArray;
