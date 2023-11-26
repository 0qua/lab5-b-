#pragma once
#include "DataChain.h"

class CDataSimple : public CDataChain {
public:
	CDataSimple();
	virtual ~CDataSimple();

	void Generate(int nDepth, int nMaxLength = 0) override;
};
